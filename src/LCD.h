#ifndef LCD_H   /* Include guard */
#define LCD_H

#include "libraries/DIO.h"
#include "libraries/PORT.h"

void LCD_init8bit(void);
void LCD_init4bit(void);
/*
Description: Init the LCD based on what configuration it is working on.

Paramaters:
    NOTHING

Return:
    NOTHING

*/

void LCD_Cmd8bit(char command);
void LCD_Cmd4bit(char command);
/*
Description: Send Commands after configuring the LCD to accept it.

Paramaters:

    command: 1 Byte command either sent one time in 8-bit Mode or two times in 4-bit Mode.

Return:
    NOTHING

*/

void LCD_Send8bit(char x[], int size);
void LCD_Send4bit(char x[], int size);
/*
Description: Send Data after Enabling the LCD to accept it.

Paramaters:

    1- x[]: Array of chars to show on the LCD. 
    2- size: The size of the array to loop on.

Return:
    NOTHING
    
*/

#endif /* LCD_H */
