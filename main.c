#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <glib.h>

#include "elm-enco.h"
#include "elm-log.h"
#include "elm-cost.h"
#include "elm-setting.h"
#include "lcd_i2c.h"
#include "server_gui.h"


int main(int argc, char *argv[])
{

    g_thread_init (NULL);
//    socket_server();

    ///baca setting ELM
    if (!elm_setting_read_enco (&elm_setting))
        return -1;
    elm_data.outlet = elm_setting.elm_outlet;

    elm_data.location = elm_setting.elm_location;
    elm_data.machine = elm_setting.elm_machine;
    elm_data.type = elm_setting.elm_type;

    elm_setting_read_sn (&elm_sn);
    elm_data.sn = elm_sn.resi;


    ///baca setting PCS
    if (!elm_setting_read_pcs (&pcs_setting))
        return -1;

    ///baca setting PCS
    if (!elm_setting_read_cost())
        return -1;

    /// baca setting epayment MID dan TID
    elm_setting_read_epayment(&epayment_setting);

    /// open file buffer.log
    if (!elm_buffer_open ())
        return -1;


    /// open file log epayment
    if (!elm_log_open_epayment ())
        return -1;
    
    /// open file log etran
    if (!elm_entran_open ())
        return -1;

    /// optocoupler ON
    wiringPiSetup () ;
    pinMode (1, OUTPUT) ;
    optocoupler_on();

    elm_id_tarif=1;

    /* thread proses buffer akan selmalu berjalan, thread ini akan di
    inisialisasi ulang saat perubahan data pcs */
    printf("LCD MONITOR INIT \n");
    lcd_i2c_opt_address = elm_setting.elm_lcd;
    if( lcd_i2c_setup(&lcd_i2c,lcd_i2c_opt_address)==-1  ){
        fprintf(stderr,"Error intialising PCF8574 at address i2c 0x%02x: %s\n",lcd_i2c_opt_address,  strerror(errno));
    }

    lcd_i2c_puts(&lcd_i2c,4,1,"ENCO LAUNDRY");
        lcd_i2c_puts(&lcd_i2c,6,2,VERSI);
        sleep(1);

        /// buka koneksi ke reader melmalu tcp ip
        LCD_I2C_CLEAR(&lcd_i2c);
        sleep(3);
        enco_open();

        /// running thread
        elm_buffer_start ();

//        enco_start();
        server_start();

        /// stop thread
//         printf("FINISH");
//        enco_stop();
        server_stop();
        elm_buffer_stop();


    return 0;
}

