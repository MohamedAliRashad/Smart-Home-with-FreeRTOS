#ifndef LCD_H
#define LCD_H

#include "TM4C123.h"
#include "PORT.h"

void LCD_init8bit(void);
void LCD_init4bit(void);

void LCD_Cmd8bit(char command);
void LCD_Cmd4bit(char command);

void LCD_Send8bit(char x[]);
void LCD_Send4bit(char x[]);

#endif /* TM4C123_H */
