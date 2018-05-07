#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <glib.h>
#include <glib/gprintf.h>

#include "elm-enco.h"
#include "elm-log.h"
#include "elm-cost.h"
#include "elm-setting.h"
#include "enco.h"
#include "elm.h"
#include "lcd_i2c.h"
#include "elm_membercard.h"
#include "server_gui.h"
#include "usb-printer.h"


static mdr_ctx *CTX;
static gboolean etoll_status = TRUE;

long time_reboot;

static gboolean pch_started =FALSE;
/* hasil akses CST */
static ELMCstAccess cst2_access;



unsigned long long cardnum;


/* status running thread CST */
static gboolean volatile cst_run;

/* status akses CST */
static unsigned int cst2_status;

static ELMTscData *cst_tsc;
static struct mdr_etoll2 epayment;
static struct mdr_etoll2 e_last_tsc;
static time_t etime_ex;
static time_t etime_en;


static char e_num[17];
static unsigned int e_balance;

static GStaticMutex mutex = G_STATIC_MUTEX_INIT;
static GStaticMutex access_mutex = G_STATIC_MUTEX_INIT;
static GStaticMutex status_mutex = G_STATIC_MUTEX_INIT;
static GStaticMutex wait_mutex = G_STATIC_MUTEX_INIT;

int enco_write_entran(char);

/* status transaksi */
enum
{
    /* eToll Mandiri  */
    STATUS_IR     = 0,  /* transaksi dilakukan setelah menekan metoda pembayaran */
    STATUS_NORMAL = 1,  /* transaksi normal */
    STATUS_GP     = 2,  /* grace period */
    STATUS_DIFF   = 3,  /* amount transaksi berbeda dengan amount report */

    /* Brizzi BRI Javacard */
    STATUS_IR_BRI_JC     = 10,  /* transaksi dilakukan setelah menekan metoda pembayaran */
    STATUS_NORMAL_BRI_JC = 11,  /* transaksi normal */
    STATUS_GP_BRI_JC     = 12,  /* grace period */
    STATUS_DIFF_BRI_JC   = 13,  /* amount transaksi berbeda dengan amount report */

    /* Brizzi BRI Desfire */
    STATUS_IR_BRI_DF     = 15,  /* transaksi dilakukan setelah menekan metoda pembayaran */
    STATUS_NORMAL_BRI_DF = 16,  /* transaksi normal */
    STATUS_GP_BRI_DF     = 17,  /* grace period */
    STATUS_DIFF_BRI_DF   = 18,  /* amount transaksi berbeda dengan amount report */

    /* TapCash BNI    */
    STATUS_IR_BNI     = 20,  /* transaksi dilakukan setelah menekan metoda pembayaran */
    STATUS_NORMAL_BNI = 21,  /* transaksi normal */
    STATUS_GP_BNI     = 22,  /* grace period */
    STATUS_DIFF_BNI   = 23,  /* amount transaksi berbeda dengan amount report */

    /* BCA Flazz    */
    STATUS_IR_BCA     = 25,  /* transaksi dilakukan setelah menekan metoda pembayaran */
    STATUS_NORMAL_BCA = 26,  /* transaksi normal */
    STATUS_GP_BCA     = 27,  /* grace period */
    STATUS_DIFF_BCA   = 28,  /* amount transaksi berbeda dengan amount report */
};

unsigned char commandGetCardNumber[19] =
{0x10,0x02,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x05,0x43,0x31,0x30,0x30,0x31,0x4e,0x10,0x03};
unsigned char commandGetBalance[30] =
{0x10,0x02,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x10,0x31,0x33,0x31,0x30,0x37,0x31,0x37,0x31,0x35,0x30,
 0x36,0x34,0x32,0x30,0x30,0x31,0x1f,0x10,0x03};
unsigned char commandPurchaseDebit[40] =
{0x10,0x02,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x1a,0x46,
 0x32,0x30,0x31,0x31,0x31,0x37,
 0x31,0x30,0x33,0x37,0x34,0x32,
 0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x31,
 0X30,0X30,0X31,
 0x63,0x10,0x03};

struct Enco enco;
int saldo;

enum
{
    RELEASE_ETOLL_NUM = 0,
    READ_ETOLL_NUM,
    SAVE_ETOLL_NUM,
};

/**
 * elm_cst2_set_access:
 *
 * Set status akses CST.
 **/

void elm_cst2_set_access (ELMCstAccess access)
{
    g_static_mutex_lock (&access_mutex);
    cst2_access = access;
    g_static_mutex_unlock (&access_mutex);
}
/* konversi data transaksi: saldo terakhir dan jumlah transaksi
   dari hexadecimal ke decimal. Mandiri is totally sucks! */
static void convert_tsc (unsigned char *tsc_report)
{
    int i, j;
    unsigned long amount, balance;
    unsigned char n[4];
    char str[9];

    /* konversi jumlah transaksi ke decimal */
    for (i = 0, j = 0; i < sizeof(n); i++, j += 2)
    {
        g_snprintf (str, 3, (char*) tsc_report + 46 + j);
        n[i] = strtol (str, NULL, 0x10);
    }
    amount = n[3] << 24 | n[2] << 16 | n[1] << 8 | n[0];
    g_snprintf (str, sizeof(str), "%.8lu", amount);
    memcpy (tsc_report + 46, str, 8);

    /* konversi saldo terkahir ke decimal */
    for (i = 0, j = 0; i < sizeof(n); i++, j += 2)
    {
        g_snprintf (str, 3, (char*) tsc_report + 54 + j);
        n[i] = strtol (str, NULL, 0x10);
    }
    balance = n[3] << 24 | n[2] << 16 | n[1] << 8 | n[0];
    g_snprintf (str, sizeof(str), "%.8lu", balance);
    memcpy (tsc_report + 54, str, 8);
}

static inline void bin_to_ascii(unsigned char *hex, char *str, int len)
{
    char ascii[2];
    int i;

    for (i = 0; i < len-1; i++) {
        sprintf(ascii, "%c", hex[i]);
        str[i] = *ascii;
    }
    str[i] = '\0';
}

static void bri_jc_convert_tsc (unsigned char *tsc_report)
{
    int i, j;
    unsigned long balance;
    unsigned char n[4];
    char str[9];

    /* konversi saldo terkahir ke decimal */
    for (i = 0, j = 0; i < sizeof(n); i++, j += 2)
    {
        g_snprintf (str, 3, (char*) tsc_report + 48 + j);
        n[i] = strtol (str, NULL, 0x10);
    }

    balance = n[0] << 24 | n[1] << 16 | n[2] << 8 | n[3];
    g_snprintf (str, sizeof(str), "%.8lu", balance);
    memcpy (tsc_report + 48, str, 8);
}

static void bri_df_convert_tsc (unsigned char *tsc_report)
{
    int i, j;
    unsigned long balance;
    unsigned char n[4];
    char str[9];

    /* konversi saldo terkahir ke decimal */
    for (i = 0, j = 0; i < sizeof(n); i++, j += 2)
    {
        g_snprintf (str, 3, (char*) tsc_report + 79 + j);
        n[i] = strtol (str, NULL, 0x10);
    }

    balance = n[0] << 24 | n[1] << 16 | n[2] << 8 | n[3];
    g_snprintf (str, sizeof(str), "%.8lu", balance);
    memcpy (tsc_report + 79, str, 8);
}

static void bni_convert_tsc (unsigned char *tsc_report)
{
    int i, j;
    unsigned long amount, balance;
    unsigned char n[3];
    char str[7];

    /* konversi jumlah transaksi ke decimal */
    for (i = 0, j = 0; i < sizeof(n); i++, j += 2)
    {
        g_snprintf (str, 3, (char*) tsc_report + 45 + j);
        n[i] = strtol (str, NULL, 0x10);
    }

    amount = n[0] << 16 | n[1] << 8 | n[2];
    g_snprintf (str, sizeof(str), "%.6lu", amount);
    memcpy (tsc_report + 45, str, 6);

    /* konversi saldo terkahir ke decimal */
    for (i = 0, j = 0; i < sizeof(n); i++, j += 2)
    {
        g_snprintf (str, 3, (char*) tsc_report + 51 + j);
        n[i] = strtol (str, NULL, 0x10);
    }
    balance = n[0] << 16 | n[1] << 8 | n[2];
    g_snprintf (str, sizeof(str), "%.6lu", balance);
    memcpy (tsc_report + 51, str, 6);
}

static void convert_cmd2 (const struct mdr_etoll *mdr,  char *res)
{
    int i = 0, j = 0;

    while (i < sizeof mdr->tsc_cmd)
    {
        g_snprintf (res + j, 3, "%x", *(mdr->tsc_cmd + i));
        j += 2;
        ++i;
    }
    res[j] = '\0';
}

inline static gboolean validate_tsc_data (const unsigned char *data, size_t len)
{
    size_t i;

    for (i = 0; i < len; i++)
        if ((data[i] < '0' || data[i] > '9') &&
                (data[i] < 'A' || data[i] > 'Z') &&
                (data[i] != 0x20))
        {
            fprintf(stderr,"%s: %x %x %x %d\n",__func__, data[i-2], data[i-1], data[i], i);
            return FALSE;
        }
    return TRUE;
}

static gboolean elm_cst2_get_run (void)
{
    gboolean retval;

    g_static_mutex_lock (&mutex);
    retval = enco.run;
    g_static_mutex_unlock (&mutex);
    return retval;
}

static unsigned long get_last_balance (unsigned char *tsc_report)
{
    g_return_val_if_fail (tsc_report != NULL, 0UL);

    char tmp[2], balance[9];
    unsigned char *ptr = tsc_report + 54;
    unsigned long retval;
    int i;

    for (i = 0; i < 8; i++)
    {
        g_snprintf (tmp, sizeof(tmp), "%c", ptr[i]);
        balance[i] = *tmp;
    }
    balance[i] = 0;
    retval = strtoul (balance, NULL, 16);
    retval = GULONG_TO_BE (retval);

    return retval;
}

int enco_open(void)
{

    cst_tsc = (ELMTscData*) malloc(sizeof(ELMTscData));
    CTX = mdr_init();
    if (!CTX)
    {
        elm_debug (ELM_DEBUG_ERROR, "%s: open fail\n", __func__);
        return FALSE;
    }

    return TRUE;

}


int enco_start(void)
{
    enco.run= TRUE;
    mutexelm = g_mutex_new ();
    condelm = g_cond_new ();

    ENCOThread = g_thread_create(enco_thread, NULL,TRUE, NULL);

    g_mutex_lock (mutexelm);
    g_cond_wait (condelm, mutexelm);
    g_mutex_unlock (mutexelm);

    return 1;
}

int bank_sam_init(void)
{

    LCD_I2C_CLEAR(&lcd_i2c);

    lcd_i2c_puts(&lcd_i2c,0,0,"MANDIRI");
    lcd_i2c_puts(&lcd_i2c,0,1,"BRI");
    lcd_i2c_puts(&lcd_i2c,0,2,"BNI");
    lcd_i2c_puts(&lcd_i2c,0,3,"BCA");

    if(mandiri_sam_init())
    {
        lcd_i2c_puts(&lcd_i2c,10,0,"OK");
    }else
    {
        lcd_i2c_puts(&lcd_i2c,10,0,"FAILED");
    }

    if(bri_sam_init())
    {
        lcd_i2c_puts(&lcd_i2c,10,1,"OK");
    }else
    {
        lcd_i2c_puts(&lcd_i2c,10,1,"FAILED");
    }

    if(bni_sam_init())
    {
        lcd_i2c_puts(&lcd_i2c,10,2,"OK");
    }else
    {
        lcd_i2c_puts(&lcd_i2c,10,2,"FAILED");
    }

    if(bca_sam_init())
    {
        lcd_i2c_puts(&lcd_i2c,10,3,"OK");
    }else
    {
        lcd_i2c_puts(&lcd_i2c,10,3,"FAILED");

    }

    return 1;

}

int enco_stop(void)
{
    enco.run= FALSE;
    g_thread_join(ENCOThread);

    g_mutex_free(mutexelm);
    g_cond_free(condelm);
    return 1;
}

void* enco_thread(void *data)
{

    char cid;
    gboolean con;
    int ret;
    long time;
    elm_debug (ELM_DEBUG_INFO, "%s: thread started", __func__);
    char *label;
    //    char label[2000];
    //char text[60];
    g_mutex_lock(mutexelm);
    g_cond_broadcast(condelm);
    g_mutex_unlock(mutexelm);

    LCD_I2C_CLEAR(&lcd_i2c);

    LCD_I2C_OUTLET_NAME(&lcd_i2c);
    sleep(2);
    ///	bank_sam_init();
    sleep(2);


    time=times(NULL);
    time_reboot=times(NULL);
    while(TRUE)
    {
        LCD_I2C_CLEAR(&lcd_i2c);
        LCD_I2C_OUTLET_NAME(&lcd_i2c);

        lcd_i2c_puts(&lcd_i2c,0,2," SILAHKAN TEMPELKAN ");
        lcd_i2c_puts(&lcd_i2c,0,3,"       KARTU        ");

        enco_purchase_debit(data);

next:
        sleep(2);


        if(((times(NULL)-time)*10)>3600000)
        {
            elm_buffer_close();
            elm_buffer_open();
            time=times(NULL);
        }


    }
    return NULL;

}

int enco_purchase_debit(int data)
{

    ELMTscData tsc;
    unsigned long amount = 0, balance;
    int ret,eid;
    char cid;
    int report_size=94;
    long time1, time2, time3;
    struct timeval  tv;
    static int cancel_count = 0;
    unsigned int status, tmp_status;
    unsigned char tsc_report[255],tsc_report_str[256], label[1000], cost[100];
    gboolean con;
    elm_debug (ELM_DEBUG_INFO, "%s: work start\n", __func__);


    switch (data) {
    case 1:
        amount = elm_cost.pkt2 ;
        cst_tsc->tarif = amount;
        cst_tsc->machine=elm_data.machine;
        cst_tsc->location=elm_data.location;
        cst_tsc->sn=elm_data.sn;
        cst_tsc->paket=2;
        break;
    case 2 :
        amount = elm_cost.pkt3 ;
        cst_tsc->tarif = amount;
        cst_tsc->machine=elm_data.machine;
        cst_tsc->location=elm_data.location;
        cst_tsc->sn=elm_data.sn;
        cst_tsc->paket=3;
        break;
    case 3 :
        amount = elm_cost.pkt4 ;
        cst_tsc->tarif = amount;
        cst_tsc->machine=elm_data.machine;
        cst_tsc->location=elm_data.location;
        cst_tsc->sn=elm_data.sn;
        cst_tsc->paket=4;
        break;
    }
    //    amount = elm_cost.pkt1 ;
    //    printf("SUCC2\n");
    //    cst_tsc->tarif = amount;
    //    printf("SUCC3\n");
    //    cst_tsc->machine=elm_data.machine;
    //    printf("SUCC4\n");
    //    cst_tsc->location=elm_data.location;
    //    printf("SUCC5\n");
    //    cst_tsc->sn=elm_data.sn;
    //    printf("SUCC6\n");
    //    cst_tsc->paket=1;


    //	amount = elm_cost;

    struct mdr_etoll2 et1;

    do {

        elm_cst2_set_access (ELM_CST_ON_PURCHASE);

        time1 = times(NULL);
        ret = mdr2_purchase_debt (CTX, amount, 0, 1, tsc_report, &epayment);
        time2 = (times(NULL)-time1)*10;
        memcpy(e_last_tsc.e1.tsc_cmd, epayment.e1.tsc_cmd, sizeof e_last_tsc.e1.tsc_cmd);


        if (ret == MDR_ERROR)
        {            elm_debug (ELM_DEBUG_ERROR, "%s: purchase_debt LRC or "
                                                 "I/O error \n", __func__);
            elm_cst2_set_access (ELM_CST_EFAIL);
            cst2_status = MDR_IO_ERROR;
            goto stop;
        }

        else if (ret == MDR_TIMEOUT)
        {
            elm_debug (ELM_DEBUG_WARNING, "%s: purchase_debt timeout\n", __func__);
            elm_cst2_set_access (ELM_CST_EFAIL);
            cst2_status = MDR_TIMEOUT;
            goto stop;
        }

        cst2_status = mdr_get_status (CTX);

    } while (cst2_status == MDR_PURCHASE_TIMEOUT);


    elm_debug (ELM_DEBUG_INFO,"%s: cst2_status %x\n", __func__, cst2_status);

    switch (cst2_status)
    {
    case MDR_PURCHASE_DOUBLE:
        LCD_I2C_CLEAR(&lcd_i2c);
        LCD_I2C_OUTLET_NAME(&lcd_i2c);
        lcd_i2c_puts(&lcd_i2c,0,2,"      TUNGGU           BEBERAPA DETIK   ");
        sleep(3);
        goto stop1;
        break;

    case MDR_SAM_NOT_INIT:
        elm_debug (ELM_DEBUG_INFO, "%s: sam init\n",__func__);
        ///	bank_sam_init();
        ///	goto stop1;
        goto stop;
        break;

    case MDR_PURCHASE_UNCOMPLETED:
        LCD_I2C_CLEAR(&lcd_i2c);
        LCD_I2C_OUTLET_NAME(&lcd_i2c);
        elm_debug (ELM_DEBUG_INFO, "%s: payment uncomplete\n",__func__);
        lcd_i2c_puts(&lcd_i2c,0,1," PAYMENT UNCOMPLETE ");
        goto stop1;
        break;

    case MDR_FAIL:
        elm_cst2_set_access (ELM_CST_EFAIL);
        break;


    case MDR_PURCHASE_MIFARE:
        elm_cst2_set_access (ELM_CST_MIFARE);
        elm_debug (ELM_DEBUG_INFO,"%s: Mifare detected..\n",__func__);
        //g_cond_signal (tsc_cond);
        break;

        //saldo kurang
    case MDR_PURCHASE_INSUFFICIENT:
        /* ambil jumlah saldo jika pengecekan di bypass, jika
           pengecekan gagal, set status/response mejadi gagal */
        ret = mdr_inq_balance (CTX,&balance, 1);

        if (ret == MDR_SUCCESS)
        {
            cst_tsc->epayment_balance = balance;
            elm_debug (ELM_DEBUG_INFO, "%s: cost: %lu, current "
                                       "balance: %lu\n", __func__, amount, balance);
        }else
        {
            status = tmp_status;
            elm_debug (ELM_DEBUG_WARNING, "%s: inq_balance failed\n", __func__);
        }

        LCD_I2C_CLEAR(&lcd_i2c);
        LCD_I2C_OUTLET_NAME(&lcd_i2c);
        lcd_i2c_puts(&lcd_i2c,0,2,"    SALDO KURANG    ");
        goto stop1;
        break;

        //sam init atau kartu tidak dikenal
    case MDR_SAM_LENGTH:
        /* ambil jumlah saldo jika pengecekan di bypass, jika
           pengecekan gagal, set status/response mejadi gagal */
        ret = mdr_inq_balance (CTX,&balance, 1);

        if (ret == MDR_SUCCESS)
        {
            cst_tsc->epayment_balance = balance;
            elm_debug (ELM_DEBUG_INFO, "%s: cost: %lu, current "
                                       "balance: %lu\n", __func__, amount, balance);
        }
        else
        {
            status = tmp_status;
            elm_debug (ELM_DEBUG_WARNING, "%s: inq_balance failed\n", __func__);
        }

        break;


    case MDR_PURCHASE_GP1:
    case MDR_PURCHASE_GP2:
        ret = mdr2_get_report (CTX, tsc_report, &eid);
        if (ret != MDR_SUCCESS)
        {
            elm_debug (ELM_DEBUG_WARNING, "%s: get report failed\n", __func__);
            goto stop;
        }

        elm_cst2_set_access (ELM_CST_GP);

        cst_tsc->epayment_status = STATUS_GP;
        cst_tsc->time_ex = time (NULL);
        cst_tsc->epayment_balance = get_last_balance (tsc_report);

        convert_cmd2 (&epayment.e1,cst_tsc->epayment_cmd);
        convert_tsc (tsc_report);
        g_snprintf (cst_tsc->epayment_data, sizeof(cst_tsc->epayment_data),
                    (char*) tsc_report);
        elm_buffer_insert_epayment_data (cst_tsc);
        elm_log_insert_epayment (cst_tsc);
        break;

    case MDR_SUCCESS:
md_success:
        cancel_count = 0;
        ret = mdr2_get_report (CTX, tsc_report, &eid);

        if (ret != MDR_SUCCESS)
        {
            elm_debug (ELM_DEBUG_WARNING, "%s: try get report\n", __func__);
            g_usleep(G_USEC_PER_SEC >> 1);
            ret = mdr2_get_report (CTX, tsc_report, &eid);
            if (ret != MDR_SUCCESS)
            {
                elm_debug (ELM_DEBUG_WARNING, "%s: try get report failed\n", __func__);
                cst2_status = MDR_LRC_ERROR;
                elm_cst2_set_access (ELM_CST_EFAIL);
                goto stop;
            }
            elm_debug (ELM_DEBUG_WARNING, "%s: try get report success\n", __func__);
        }

        if (eid == MANDIRI_CARD)
        {
            report_size = MANDIRI_REPORT_SZ;
            tsc.type = ELM_TRANS_ETOLL_NORMAL;
        }
        else if (eid == BRI_JAVA_CARD)
        {
            report_size = BRI_REPORT_SZ;
            tsc.type = ELM_TRANS_BRI_NORMAL;
        }
        else if (eid == BRI_DESFIRE_CARD)
        {
            report_size = BRI_REPORT_SZ+10;
            tsc.type = ELM_TRANS_BRI_NORMAL;
        }
        else if (eid == BNI_CARD)
        {
            report_size = BNI_REPORT_SZ;
            tsc.type = ELM_TRANS_BNI_NORMAL;
        }
        else if (eid == BCA_CARD)
        {
            report_size = BCA_REPORT_SZ;
            tsc.type = ELM_TRANS_BCA_NORMAL;
        }

        cst_tsc->type= tsc.type;

        ret = validate_tsc_data (tsc_report, report_size);

        if (!ret && eid != BCA_CARD)
        {
            elm_debug (ELM_DEBUG_ERROR, "%s: malformed tsc report data\n", __func__);
            elm_cst2_set_access (ELM_CST_EFAIL);
            goto stop;
        }


        memcpy (tsc_report_str, tsc_report, report_size);
        *(tsc_report_str + report_size) = 0;

        elm_debug (ELM_DEBUG_INFO, "%s: tsc report: %s\n",
                   __func__, (char*) tsc_report_str);

        if (eid == MANDIRI_CARD)
            convert_tsc (tsc_report_str);
        else if (eid == BRI_JAVA_CARD)
            bri_jc_convert_tsc (tsc_report_str);
        else if (eid == BRI_DESFIRE_CARD)
            bri_df_convert_tsc (tsc_report_str);
        else if (eid == BNI_CARD)
        {
            memcpy (cst_tsc->epayment_data, tsc_report_str, report_size);
            bni_convert_tsc (tsc_report_str);
        }
        else if (eid == BCA_CARD)
        {

        }

        convert_cmd2 (&epayment.e1,cst_tsc->epayment_cmd);
        if (eid != BNI_CARD)
            memcpy (cst_tsc->epayment_data, tsc_report_str, report_size);
        *(cst_tsc->epayment_data + report_size) = 0;


        char str[17],str2[17];
        unsigned long amt1,amt2;
        if (eid == MANDIRI_CARD)
        {
            /* no kartu MANDIRI*/
            memcpy(str, tsc_report_str, 17);
            str[16]=0;
            cst_tsc->card_id = strtoull(str, NULL, 10);

            memcpy(str, tsc_report_str+46, 8);
            str[8]=0;
            epayment.e1.tsc_amount = strtoul(str, NULL, 10);

            /* saldo MANDIRI*/
            memcpy(str, tsc_report_str+54, 8);
            str[8]=0;
            cst_tsc->epayment_balance = strtoul(str, NULL, 10);
            /* */
            g_snprintf (e_num, sizeof e_num, (char*)tsc_report_str);
        }
        else if (eid == BRI_JAVA_CARD)
        {
            /* no kartu BRI JAVA*/
            bin_to_ascii(tsc_report_str, str, 17);
            cst_tsc->card_id = strtoull(str, NULL, 10);

            memcpy(str, tsc_report_str+28, 8);
            str[8]=0;
            epayment.e1.tsc_amount = strtoul(str, NULL, 10);

            /* saldo BRI JAVA*/
            memcpy(str, tsc_report_str+48, 8);
            str[8]=0;
            cst_tsc->epayment_balance = strtoul(str, NULL, 10);
        }
        else if (eid == BRI_DESFIRE_CARD)
        {
            /* no kartu BRI DESFIRE*/
            bin_to_ascii(tsc_report_str, str, 17);
            cst_tsc->card_id = strtoull(str, NULL, 10);

            memcpy(str, tsc_report_str+28, 8);
            str[8]=0;
            epayment.e1.tsc_amount = strtoul(str, NULL, 10);

            /* saldo BRI DESFIRE*/
            memcpy(str, tsc_report_str+79, 8);
            str[8]=0;
            cst_tsc->epayment_balance = strtoul(str, NULL, 10);
        }
        else if (eid == BNI_CARD)
        {
            /* no kartu */
            memcpy(str, tsc_report_str+3, 17);
            str[16]=0;
            cst_tsc->card_id = strtoull(str, NULL, 10);

            memcpy(str, tsc_report_str+45, 6);
            memcpy(str2, tsc_report_str+51, 6);
            str[6]=0;
            str2[6]=0;

            /* saldo */
            amt1 = strtoul(str, NULL, 10);
            amt2 = strtoul(str2, NULL, 10);
            epayment.e1.tsc_amount = amt1 - amt2;
            cst_tsc->epayment_balance = amt2;
        }
        else if (eid == BCA_CARD)
        {
            /* no kartu */
            memcpy(str, tsc_report_str+4, 17);
            str[16]=0;
            cst_tsc->card_id = strtoull(str, NULL, 10);

            memcpy(str, tsc_report_str+50, 10);
            str[10]=0;
            epayment.e1.tsc_amount = strtoul(str, NULL, 10);

            memcpy(str, tsc_report_str+40, 10);
            str[10]=0;
            cst_tsc->epayment_balance = strtoul(str, NULL, 10);
        }

        if (!pch_started)
            pch_started = TRUE;

        e_last_tsc.card_num = cst_tsc->card_id;
        e_last_tsc.e1.last_balance = cst_tsc->epayment_balance;
        e_last_tsc.eid = eid;

        switch(e_last_tsc.eid)
        {
        case 0x30:
            sprintf(label,"MANDIRI             %016llu    SALDO: Rp. %lu", e_last_tsc.card_num, e_last_tsc.e1.last_balance);
            break;
        case 0x32:
            sprintf(label,"BRI                 %016llu    SALDO: Rp. %lu", e_last_tsc.card_num, e_last_tsc.e1.last_balance);
            break;
        case 0x33:
            sprintf(label,"BNI                 %016llu    SALDO: Rp. %lu", e_last_tsc.card_num, e_last_tsc.e1.last_balance);
            break;
        case 0x34:
            sprintf(label,"BCA                 %016llu    SALDO: Rp. %lu", e_last_tsc.card_num, e_last_tsc.e1.last_balance);
            break;
        }

        LCD_I2C_CLEAR(&lcd_i2c);
        LCD_I2C_OUTLET_NAME(&lcd_i2c);
        lcd_i2c_puts(&lcd_i2c,0,1,label);

        optocoupler();

        elm_debug (ELM_DEBUG_INFO, "%s: e-last saved  %llu  %lu %x %lu \n",
                   __func__,
                   e_last_tsc.card_num,
                   e_last_tsc.e1.last_balance,
                   e_last_tsc.eid, time2);



        elm_cst2_set_access (ELM_CST_ESUCCESS);

        if (amount == epayment.e1.tsc_amount)
        {
            if (eid == MANDIRI_CARD)
                cst_tsc->epayment_status = STATUS_NORMAL;
            else if (eid == BRI_JAVA_CARD)
                cst_tsc->epayment_status = STATUS_NORMAL_BRI_JC;
            else if (eid == BRI_DESFIRE_CARD)
                cst_tsc->epayment_status = STATUS_NORMAL_BRI_DF;
            else if (eid == BNI_CARD)
                cst_tsc->epayment_status = STATUS_NORMAL_BNI;
            else if (eid == BCA_CARD)
                cst_tsc->epayment_status = STATUS_NORMAL_BCA;
        }
        else
        {
            if (eid == MANDIRI_CARD)
                cst_tsc->epayment_status = STATUS_DIFF;
            else if (eid == BRI_JAVA_CARD)
                cst_tsc->epayment_status = STATUS_DIFF_BRI_JC;
            else if (eid == BRI_DESFIRE_CARD)
                cst_tsc->epayment_status = STATUS_DIFF_BRI_DF;
            else if (eid == BNI_CARD)
                cst_tsc->epayment_status = STATUS_DIFF_BNI;
            else if (eid == BCA_CARD)
                cst_tsc->epayment_status = STATUS_DIFF_BCA;

            elm_debug (ELM_DEBUG_WARNING, "%s: invalid purchased "
                                          "amount report, request: %lu, report: %lu\n",
                       __func__, amount, epayment.e1.tsc_amount);
        }
        //           g_cond_signal (tsc_cond);


        cst_tsc->time_ex = time (NULL);
        cst_tsc->cycle = time (NULL);


        ///        if (cst_tsc->epayment_status == STATUS_IR ||
        ///            cst_tsc->epayment_status == STATUS_IR_BRI_JC ||
        ///            cst_tsc->epayment_status == STATUS_IR_BRI_DF ||
        ///            cst_tsc->epayment_status == STATUS_IR_BNI ||
        ///            cst_tsc->epayment_status == STATUS_IR_BCA)
        ///          {
        ///            etime_ex = tsc.time_ex;
        ///            elm_buffer_insert_epayment_data2 (&tsc);
        ///			elm_log_insert_epayment (&tsc);
        ///         }
        ///        else
        ///          {
        etime_ex = cst_tsc->time_ex;
        elm_buffer_insert_epayment_data2 (cst_tsc);
        elm_log_insert_epayment (cst_tsc);
        ///          }
        resi = elm_data.sn;

        setting_sn_inc();
        goto stop1;
        break;

    default:

        break;

    }

stop:

    if (!(&cst2_status==MDR_SUCCESS))
    {
        con=enco_get_cardnumber(READ_ETOLL_NUM,&cardnum,&cid);
        if(con)
        {
            switch (cid)
            {
            case 0x39: //MIFARE
                if(find_card_member_uid(cardnum))
                {
                    membercard[indeks][2]=membercard[indeks][2]-amount;
                    cst_tsc->epayment_balance = membercard[indeks][2];
                    switch(data)
                    {
                    case 1:
                        amount = elm_cost.pkt2;
                        cst_tsc->tarif = amount;
                        sprintf(cst_tsc->epayment_data,"%llu",cardnum);
                        cst_tsc->paket=2;
                        printf("PAKET1\nTARIF : %d\n",amount);
                        break;
                    case 2:
                        amount = elm_cost.pkt3;
                        cst_tsc->tarif = amount;
                        sprintf(cst_tsc->epayment_data,"%llu",cardnum);
                        cst_tsc->paket=3;
                        printf("PAKET2\nTARIF : %d\n", amount);

                        break;
                    case 3:
                        amount = elm_cost.pkt4;
                        cst_tsc->tarif = amount;
                        sprintf(cst_tsc->epayment_data,"%llu",cardnum);
                        cst_tsc->paket=4;
                        printf("PAKET3\nTARIF : %d\n", amount);
                        break;
                    }

                    printf("SALDOO\n : %d",cst_tsc->epayment_balance);

                    if(cst_tsc->epayment_balance<0)
                    {
                        sprintf(label,"\t\tTARIF \t\t: %d\n\t\tMEMBER CARD \t\t: %016llu\nMAAF, SALDO ANDA KURANG",amount,membercard[indeks][1]);

                        LCD_I2C_CLEAR(&lcd_i2c);
                        LCD_I2C_OUTLET_NAME(&lcd_i2c);
                        lcd_i2c_puts(&lcd_i2c,0,1,label);
                        membercard[indeks][2]=membercard[indeks][2]+amount;
                        cst_tsc->epayment_balance=membercard[indeks][2];
                        info = label;

//                        tariff = cost;

                    }else
                    {
                        tsc.type = ELM_TRANS_MEMCARD_NORMAL;
                        cst_tsc->type= tsc.type;
                        optocoupler();
                        sprintf(label,"TARIF : %d\nMEMBER CARD : %016llu\nSALDO : %d\n",amount,membercard[indeks][1],membercard[indeks][2]);
                        sprintf(info_print,"TARIF : %d\nMEMBER CARD : %016llu\nSALDO : %d\n",amount,membercard[indeks][1],membercard[indeks][2]);

                        LCD_I2C_CLEAR(&lcd_i2c);
                        LCD_I2C_OUTLET_NAME(&lcd_i2c);
                        lcd_i2c_puts(&lcd_i2c,0,1,label);

                        cst_tsc->cycle = time (NULL);
                        convert_cmd2 (&epayment.e1,cst_tsc->epayment_cmd);
                        cst_tsc->time_ex = time (NULL);
                        card_member_update(cardnum,cst_tsc->epayment_balance);
                        elm_buffer_insert_epayment_data2 (cst_tsc);
                        setting_sn_inc();
                        info = label;
                         printer();

//                        tariff = cost;
//                        info = label;

                    }


                }else if (membercard[0][0]==0)
                {
                    LCD_I2C_CLEAR(&lcd_i2c);
                    LCD_I2C_OUTLET_NAME(&lcd_i2c);
                    lcd_i2c_puts(&lcd_i2c,0,2,"KONEKSI GAGAL");
                    sprintf(label,"KONEKSI GAGAL");
                    info = label;

                }else
                {
                    LCD_I2C_CLEAR(&lcd_i2c);
                    LCD_I2C_OUTLET_NAME(&lcd_i2c);
                    lcd_i2c_puts(&lcd_i2c,0,2,"KARTU TIDAK DIKENAL");
                    sprintf(label,"KARTU TIDAK DIKENAL");
                    info = label;
                }
                break;
            default:
                if(!(&cst2_status==MDR_PURCHASE_TIMEOUT))
                {
                    LCD_I2C_CLEAR(&lcd_i2c);
                    LCD_I2C_OUTLET_NAME(&lcd_i2c);
                    lcd_i2c_puts(&lcd_i2c,0,2,"KARTU TIDAK DIKENAL");
                    sprintf(label,"KARTU TIDAK DIKENAL");
                    info = label;
                }
                break;
            }
        }else
        {
            LCD_I2C_CLEAR(&lcd_i2c);
            LCD_I2C_OUTLET_NAME(&lcd_i2c);
            lcd_i2c_puts(&lcd_i2c,0,2,"KARTU TIDAK DIKENAL");
            sprintf(label,"KARTU TIDAK DIKENAL");
            info = label;
        }
    }

stop1:
    time3 = (times(NULL)-time1)*10;
    elm_debug (ELM_DEBUG_INFO, "%s: Time Deduct %lu %d \n", __func__, time2,indeks);
    elm_debug (ELM_DEBUG_INFO, "%s: Time Debit Purchase %lu\n", __func__, time3);
    elm_debug (ELM_DEBUG_INFO, "%s: work end\n", __func__);

    return &cst2_status;
}

gboolean enco_get_cardnumber(char cmd, unsigned long long* num, char* id)
{
    int ret;
    unsigned long long cnum;
    char idc;

    ret = mdr2_get_cardnumber(CTX,cmd,1,&cnum,&idc);
    if (ret != MDR_SUCCESS)
    {
        printf("SUCCCC");
        cst2_status = mdr_get_status(CTX);
        if (cst2_status == MDR_PURCHASE_MIFARE)
        {
            //*id = MIFARE_CARD;
            //elm_debug (ELM_DEBUG_INFO, "%s: Mifare detected\n",__func__);
            //return TRUE;
        }
        else if (cst2_status == MDR_SAM_NOT_INIT)
        {
            elm_debug (ELM_DEBUG_INFO, "%s: sam init\n",__func__);
            ///   bank_sam_init();
        }
        return FALSE;
    }
    *num = cnum;
    *id = idc;

    elm_debug (ELM_DEBUG_INFO, "%s: %x %llu\n",__func__, idc, cnum);
    return TRUE;
}


int enco_get_balance(void)
{

    int valid_ans=45;
    int ret;
    size_t bytes = 0;
    int cmd_len = sizeof(commandGetBalance);
    unsigned char ans[36];
    int iPrint = 0;
    unsigned char status[4];

    while (bytes < cmd_len)
    {
        ret = write(enco.connfd, commandGetBalance+bytes, cmd_len-bytes);
        if (ret == -1) {
        }
        bytes += ret;
    }

    ret = read(enco.connfd,ans, valid_ans);
    if (ret == -1)
    {

    }

    printf("%s reply: ",__func__);
    while(iPrint < ret)
    {
        printf("%02X ", ans[iPrint]);
        iPrint++;
    }
    printf("\n");

    int i;
    for (i=0;i<10;i++)
    {
        scbalance[i]=ans[i+16];
    }

    for (i=0;i<4;i++)
    {
        status[i]=ans[i+12];
    }
    if ((status[0]==0x30)&&(status[1]==0x30)&&(status[2]==0x30)&&(status[3]==0x30))
    {

        return 1;
    }else
    {
        return 0;
    }

    return 1;
}

gboolean mandiri_sam_init(void)
{

    int ret;

    ret = mdr_init_sam (CTX, epayment_setting.sam_pin,
                        epayment_setting.instution_id,
                        epayment_setting.terminal_id);

    if (ret != MDR_SUCCESS)
    {
        if (mdr_get_status (CTX) == MDR_TIMEOUT)
            etoll_status = FALSE;
        return FALSE;
    }
    return TRUE;
}

gboolean bri_sam_init(void)
{
    char _shift[4];

    //  sprintf(_shift,"%02d",tct_data.shift);
    sprintf(_shift,"%02d",1);

    int ret = bri_init_sam (CTX, epayment_setting.bri_mid,
                            epayment_setting.bri_tid,
                            epayment_setting.bri_pcd,
                            _shift);

    if (ret != MDR_SUCCESS)
    {
        if (mdr_get_status (CTX) == MDR_TIMEOUT)
            etoll_status = FALSE;
        return FALSE;
    }
    return TRUE;
}

gboolean bca_sam_init(void)
{

    int ret = bca_init_sam (CTX, epayment_setting.bca_mid,
                            epayment_setting.bca_tid);

    if (ret != MDR_SUCCESS)
    {
        if (mdr_get_status (CTX) == MDR_TIMEOUT)
            etoll_status = FALSE;
        return FALSE;
    }
    return TRUE;
}

gboolean bni_sam_init(void)
{
    int ret = bni_init_sam (CTX, epayment_setting.bni_tid);

    if (ret != MDR_SUCCESS)
    {
        if (mdr_get_status (CTX) == MDR_TIMEOUT)
            etoll_status = FALSE;
        return FALSE;
    }
    return TRUE;
}



//char saldos(char *salldo){
//    return salldo;
//}

//int trigger(int numm){
//    return numm;
//}

