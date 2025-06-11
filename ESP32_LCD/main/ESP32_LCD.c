/* @file  ESP32_LCD.c
   @brief main application for ESP32 and 16x2 LCD Display
   @author Avinashee Tech
*/

#include <stdio.h>
#include "lcd_i2c.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//macros
#define LCD_COLS       16    // LCD Display has 16 columns
#define LCD_ROWS       2     // LCD Display has 2 rows

/**  
* @brief LCD Display Start Message
* @retval None
* @param None
*/
void lcd_home_message(void){
    /*lcd custom characters*/
    uint8_t subscribe[] = {0x00,0x08,0x0C,0x0E,0x0C,0x08,0x00,0x1F};
    uint8_t share_back[] = {0x08,0x0C,0x1E,0x1F,0x1E,0x0C,0x08,0x00};
    uint8_t share_front[] = {0x00,0x00,0x03,0x07,0x0F,0x1C,0x18,0x10};
    uint8_t like[] = {0x00,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00};

    /*lcd kana characters*/
    uint8_t channelname_japanese[] = {0xB1,0xCB,0xDE,0xC5,0xC2,0xBC,0xB0,0xA5,0xC3,0xC2,0xB8};
    uint8_t subscribe_japanese[] = {0xBB,0xCC,0xDE,0xCD,0xB8,0xD7,0xB2,0xCC,0xDE};
    
    /*
      0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
    0 N  a  m  a  s  t  e     &
    1 W  e  l  c  o  m  e     t  o
    */
    clear();
    setCursor(0,0);
    send_string("Namaste &");
    setCursor(0,1);
    send_string("Welcome to");

    vTaskDelay(pdMS_TO_TICKS(4000));  //wait 4s

    /*
      0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
    0 A  v  i  n  a  s  h  e  e     T  e  c  h
    1 ❤️     ➦      ▶ s  u  b  s  c  r  i  b  e
    */
    clear();
    setCursor(0,0);
    send_string("Avinashee");
    setCursor(10,0);
    send_string("Tech");
    
    createChar(0,subscribe);
    createChar(1,share_back);
    createChar(2,share_front);
    createChar(3,like);
    //subscribe
    setCursor(5,1);
    lcd_write(0);
    setCursor(6,1);
    send_string("subscribe");
    //share
    setCursor(2,1);
    lcd_write(2);
    setCursor(3,1);
    lcd_write(1);
    //like
    setCursor(0,1);
    lcd_write(3);

  }

/**  
* @brief main function
* @retval None
* @param None
*/  
void app_main(void)
{
    lcd_init(LCD_COLS,LCD_ROWS);
    backlight();
    lcd_home_message();
}
