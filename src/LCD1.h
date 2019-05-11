#ifndef LCD_H
#define	LCD_H


#include "Mcal.h"
#include "tm4c123gh6pm.h"

/* LCD HardWare Pins */
#define RS  2
#define RW  3
#define E   4
#define LCD_CTRL_PORT        GPIO_PORTF_DATA_R
#define LCD_DATA_PORT        GPIO_PORTB_DATA_R

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

/* LCD Functions Prototypes */
void delayMS(uint32_t n);
void LCD_SendCommand(uint8_t com);
void LCD_SendData(uint8_t data);
void LCD_ShowString(const char *Str);
void LCD_init(void);
void LCD_ClearScreen(void);
void LCD_GoToRowColumn(uint8_t row,uint8_t col);
void LCD_ShowStringRowAndColumn(uint8_t row,uint8_t col,const char *Str);
char* itoa(int i, char b[]);
void LCD_IntgerToString(uint32_t Data);



#endif

