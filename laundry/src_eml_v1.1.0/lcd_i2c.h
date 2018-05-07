#ifndef LCD_I2C_H
#define LCD_I2C_H
// ----------------------------------------------------------------
// Copyright Stephen Stebbing 2014
// $Id: $
// ----------------------------------------------------------------
#include <stdint.h>
#include "elm.h"
#include "elm-setting.h"

#include <stdio.h>
#include <string.h>

//! Structure for containing lcd state data
typedef struct {
    // i2c file descriptor/identifier
    int fd;
    // current pcf8574  output
    uint8_t output;
    // number of rows
    uint8_t rows;
    // number of columns
    uint8_t cols;
    // row and column coord of current cursor position
    // for a 1602 display, bottom right is (15,1), home is (0,0) 
    uint8_t x,y;
} lcd_i2c_t;


// default i2c address
#define LCD_I2C_PCF8574_ADDRESS_DEFAULT 0x3f

int lcd_i2c_cursor; // 0 off, 1 on , 2 blink
int lcd_i2c_opt_address;
int lcd_i2c_opt_backlight; // -1 do nothing, 0 turn off, 1 turn on
int lcd_i2c_opt_clear;
int lcd_i2c_opt_cols;
int lcd_i2c_opt_help;
int lcd_i2c_opt_init;
int lcd_i2c_opt_rows;
int lcd_i2c_opt_x;
int lcd_i2c_opt_y;


lcd_i2c_t lcd_i2c;

// convenience macros
#define LCD_I2C_BACKLIGHT_ON(lcd_p) lcd_i2c_backlight(lcd_p, 1)
#define LCD_I2C_BACKLIGHT_OFF(lcd_p) lcd_i2c_backlight(lcd_p, 0)
// Display, cursor and blink on/off control.
#define LCD_I2C_DISPLAY_CONTROL(lcd_p, display, cursor, blink) lcd_i2c_write_i ( lcd_p, 0x08 | (display << 2) | (cursor << 1) | (blink) )
#define LCD_I2C_CURSOR_ON(lcd_p) LCD_I2C_DISPLAY_CONTROL(lcd_p,1,1,0)
#define LCD_I2C_CURSOR_OFF(lcd_p) LCD_I2C_DISPLAY_CONTROL(lcd_p,1,0,0)
#define LCD_I2C_CURSOR_BLINK_ON(lcd_p) LCD_I2C_DISPLAY_CONTROL(lcd_p,1,1,1)
#define LCD_I2C_CURSOR_BLINK_OFF(lcd_p) LCD_I2C_DISPLAY_CONTROL(lcd_p, 1,1,0)
#define LCD_I2C_OUTLET_NAME(lcd_p) lcd_i2c_puts(lcd_p,(20-strlen(elm_outlet[elm_setting.elm_outlet]))/2,0,elm_outlet[elm_setting.elm_outlet])
#define LCD_I2C_CLEAR(lcd_p) lcd_i2c_clear(lcd_p)


/** 
 *  Initialise i2c and lcd_i2c_t structure.
 * @param address i2c address of the pcf8574 that controls the LCD. Use PC LCD_I2C_PCF8574_ADDRESS_DEFAULT for default
 * @param lcd Pointer to an lcd_i2c_t structure that will be used to keep lcd variables
 * @return The 'file descriptor' for the device (as returned by wiringPiI2CSetup) on success, -1 on error with errno set
 */
int lcd_i2c_setup(lcd_i2c_t *lcd,int address);

/** 
 * Initalise the lcd by doing a software reset, clearing and positioning cursor in home position
 * @param lcd Pointer to lcd_i2c_t structure 
 */
void lcd_i2c_init(lcd_i2c_t *lcd);

/** 
 * Write an instruction byte to the lcd
 * @param lcd Pointer to lcd_i2c_t structure 
 * @param data The instruction byte
 */
void lcd_i2c_write_i(lcd_i2c_t *lcd, uint8_t data);

/** 
 * Write a data byte to the lcd
 * @param lcd Pointer to lcd_i2c_t structure 
 * @param data The data byte
 */
void lcd_i2c_write_d(lcd_i2c_t *lcd, uint8_t data);

/** 
 * Move the cursor location to specified coords.
 * Note that no range checking is done
 * @param lcd Pointer to lcd_i2c_t structure 
 * @param x The x coord
 * @param y The y coord
 */
void lcd_i2c_gotoxy(lcd_i2c_t *lcd, uint8_t x, uint8_t y);

/** 
 * Write to lcd with printf like functionallity
 * @param lcd  Pointer to lcd_i2c_t structure 
 * @param format_p The format string, followed by the parameters
 */
void lcd_i2c_printf(lcd_i2c_t *lcd,int x, int y,  char* format_p, ...);

/** 
 * Clear the lcd
 * @param lcd Pointer to lcd_i2c_t structure 
 */
void lcd_i2c_clear(lcd_i2c_t *lcd);

/** 
 * Move curson to home position
 * @param lcd Pointer to lcd_i2c_t structure 
 */
void lcd_i2c_home(lcd_i2c_t *lcd);

/** 
 * Display passed character at current position
 * @param lcd Pointer to lcd_i2c_t structure 
 * @param c The character to be displayed
 */
void lcd_i2c_putc(lcd_i2c_t *lcd, char c);

/** 
 * Display passed string at current position
 * @param lcd Pointer to lcd_i2c_t structure 
 * @param str Pointer to the string to be displayed
 */
void lcd_i2c_puts(lcd_i2c_t *lcd,int x, int y, const char* str);

/** 
 * Turn backlight on or off
 * @param ct lcd_i2c_t control structure for the device
 * @param on Turn on if non-zero, off otherwise
 */
void lcd_i2c_backlight(lcd_i2c_t *lcd, uint8_t on);



#endif
