// ----------------------------------------------------------------
// Copyright Stephen Stebbing 2014
// $Id: $
// ----------------------------------------------------------------
#include "lcd_i2c.h"

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// pcf8574 bit positions of the lcd control pins 
// bits 4 to 7 are the data bits
#define LCD_I2C_RS 0
#define LCD_I2C_RW 1
#define LCD_I2C_E  2
#define LCD_I2C_BACKLIGHT 3

// convenience macros
// write current value of output variable to device
#define LCD_I2C_WRITE(lcd_p) wiringPiI2CWrite(lcd_p->fd, lcd_p->output);
// enable
#define LCD_I2C_E_HI(lcd_p)  lcd_p->output |= (1<<LCD_I2C_E)
#define LCD_I2C_E_LO(lcd_p)  lcd_p->output &=~ (1<<LCD_I2C_E)
// set data or instruction mode
#define LCD_I2C_RS_D(lcd_p) lcd_p->output |= (1<<LCD_I2C_RS)
#define LCD_I2C_RS_I(lcd_p) lcd_p->output &=~ (1<<LCD_I2C_RS)
// set the data nibble -
// note: will need to change this for devices with different wiring.
#define LCD_I2C_DATA_NIBBLE(lcd_p, x) lcd_p->output= (x<<4 | (lcd_p->output & 0x0f))
//! set the lcd data ram address to that passed, only lower 7 bits are used.
#define LCD_I2C_SET_DD_RAM_ADDRESS(lcd_p, address) lcd_i2c_write_i(lcd_p, 0x80 | ((address) & 0x7f) )

// -----------------------------------------------------
// static functions
// -----------------------------------------------------
static void lcd_i2c_e_assert(lcd_i2c_t *lcd)
{
    LCD_I2C_E_LO(lcd);
    LCD_I2C_WRITE(lcd);
    LCD_I2C_E_HI(lcd);
    LCD_I2C_WRITE(lcd);
    LCD_I2C_E_LO(lcd);
    LCD_I2C_WRITE(lcd);
}

//! Write passed data to device
//! Note: RS must be set prior to calling
static void lcd_i2c_write(lcd_i2c_t *lcd, uint8_t data)
{
   // high nibble
   LCD_I2C_DATA_NIBBLE(lcd, (data >> 4));
   lcd_i2c_e_assert(lcd);
   // low nibble
   LCD_I2C_DATA_NIBBLE(lcd, (data & 0x0f));
   lcd_i2c_e_assert(lcd);
   // delay for command to be executed
   delayMicroseconds(50);
}

// -----------------------------------------------------
// user callable functions
// -----------------------------------------------------
void lcd_i2c_gotoxy(lcd_i2c_t *lcd, uint8_t x, uint8_t y)
{
    // note: on two line devices, second line begins at address 0x40
    // XXX so this will work with 1 and 2 line devices, but probabaly not with 4.
  char addr;
      switch(y)
  {
     case 0: addr = 0x00; break; //Starting address of 1st line
     case 1: addr = 0x40; break; //Starting address of 2nd line
     case 2: addr = 0x14; break; //Starting address of 3rd line
     case 3: addr = 0x54; break; //Starting address of 4th line
     default: ; 
  }
    
  LCD_I2C_SET_DD_RAM_ADDRESS( lcd,  addr + x  );
    lcd->x=x;
    lcd->y=y;
}

void lcd_i2c_printf(lcd_i2c_t *lcd,int x, int y,  char* format, ...)
{
    va_list args;
    char *spp=NULL;

    va_start(args, format);
    int r=vasprintf(&spp, format, args);
    if(r!=-1){
	lcd_i2c_puts(lcd,x,y, spp);
	free(spp);
    }
    va_end(args);
}

int lcd_i2c_setup( lcd_i2c_t *lcd,int address)
{
	lcd_i2c_opt_cols=20;
	lcd_i2c_opt_rows=4;
 
    lcd->output=0;
    lcd->fd=wiringPiI2CSetup(address);
    // XXX for now, alway use a 1602 display
   
    lcd->rows=4;
    lcd->cols=20;
    lcd_i2c_init(lcd);
	LCD_I2C_BACKLIGHT_ON(lcd);
    return lcd->fd;
}

void lcd_i2c_write_i(lcd_i2c_t *lcd, uint8_t data)
{
   LCD_I2C_RS_I(lcd);
   lcd_i2c_write(lcd,data);
}

void lcd_i2c_write_d(lcd_i2c_t *lcd, uint8_t data)
{
   LCD_I2C_RS_D(lcd);
   lcd_i2c_write(lcd,data);
}

void lcd_i2c_clear(lcd_i2c_t *lcd)
{
    lcd_i2c_write_i(lcd, 0x1);
    delay(2); // delay for command to take effect
}

void lcd_i2c_home(lcd_i2c_t *lcd)
{
    lcd_i2c_write_i(lcd, 0x02);
    lcd->x=0;
    lcd->y=0;
    delay(2); // delay for command to take effect
}

void lcd_i2c_putc(lcd_i2c_t *lcd, char c)
{
	
    lcd_i2c_write_d(lcd, c);
  //  printf("c: %c (%i,%i)\n",c, lcd->x, lcd->y);
    
    if(++lcd->x == lcd->cols){
	lcd->x=0;
	if(++lcd->y == lcd->rows){
	    lcd->y=0;
	}
	lcd_i2c_gotoxy(lcd,lcd->x,lcd->y);
    }
    
}

void lcd_i2c_puts(lcd_i2c_t *lcd,int x, int y, const char* str)
{
	
	lcd_i2c_gotoxy(lcd, x,y);
    while(*str!='\x0'){
	lcd_i2c_putc(lcd,*str++);
    }
}

void lcd_i2c_init(lcd_i2c_t *lcd)
{
    LCD_I2C_E_LO(lcd);
    LCD_I2C_RS_I(lcd);
    LCD_I2C_WRITE(lcd);

    // software reset
    LCD_I2C_DATA_NIBBLE(lcd,0x3);
    lcd_i2c_e_assert(lcd);
    delay(5); // ms
    lcd_i2c_e_assert(lcd);
    delayMicroseconds(150);
    lcd_i2c_e_assert(lcd);
    delayMicroseconds(150);
    
    // set 4 bit mode
    LCD_I2C_DATA_NIBBLE(lcd,0x02);
    lcd_i2c_e_assert(lcd);

    // entry mode - 0x06 is display shift on, increment address counter
    lcd_i2c_write_i(lcd,0x06);

    // set cursor
    LCD_I2C_CURSOR_BLINK_OFF(lcd);
    LCD_I2C_CURSOR_OFF(lcd);

    // clear and home 
    lcd_i2c_clear(lcd);
    lcd_i2c_home(lcd);
       
}

/** 
 * Turn backlight on or off
 * @param ct lcd_i2c_t control structure for the device
 * @param on Turn on if non-zero, off otherwise
 */
void lcd_i2c_backlight(lcd_i2c_t *lcd, uint8_t on)
{
    if(on)
	lcd->output |= (1<<LCD_I2C_BACKLIGHT);
    else
	lcd->output &=~ (1<<LCD_I2C_BACKLIGHT);
    LCD_I2C_WRITE(lcd);
}
