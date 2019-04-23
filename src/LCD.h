#ifndef LCD_h
#define LCD_h
#include "stdint.h"
/*LCD DRIVERS*/
void systick_wait (uint32_t delay);
void delayMS(uint32_t n);
void delayUS(uint32_t N);
void LCD_data(char data);
void LCD_command(char com);
void LCD_init();
#endif
