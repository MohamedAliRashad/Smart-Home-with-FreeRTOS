#include "LCD.h"
#include <stdint.h>

void LCD_init() //microcontroller initialization aiming to LCD "USING FULL PINS OF PORT B"
{
	Port_Init(PORTB); //Port B init
	Port_SetPinDirection(PORTB, 0xFF, PORT_PIN_OUT);
	/* Configure the control pins(E,RS,RW) as output pins */
	Port_Init(PORTF);
	Port_SetPinDirection(PORTF, 0x1C, PORT_PIN_OUT);
	LCD_SendCommand(TWO_LINE_LCD_Eight_BIT_MODE); //2 lines with 5x7 characters

	LCD_SendCommand(CURSOR_OFF); //Cursor off

	LCD_SendCommand(CLEAR_COMMAND); //clear screen
}
void LCD_ClearScreen(void)
{
	LCD_SendCommand(CLEAR_COMMAND);
}

void LCD_SendCommand(uint8_t com) //sending command function through port D pins(0,1,2), 0-->RS, 1-->RW, 2-->E
{
	CLEAR_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	delayMS(1);

	SET_BIT(LCD_CTRL_PORT, E);
	delayMS(1);

	LCD_DATA_PORT = com; //sending command to lcd
	delayMS(1);

	CLEAR_BIT(LCD_CTRL_PORT, E); //enable "E" is low
	delayMS(1);					 //high to low delay
}

void LCD_SendData(uint8_t data) //sending data to lcd function
{
	SET_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	delayMS(1);

	SET_BIT(LCD_CTRL_PORT, E);
	delayMS(1);

	LCD_DATA_PORT = data; //sending command to lcd
	delayMS(1);

	CLEAR_BIT(LCD_CTRL_PORT, E); //enable "E" is low
	delayMS(1);					 //high to low delay
}
void LCD_GoToRowColumn(uint8_t row, uint8_t col)
{
	uint8_t Address;

	//calculating required address
	switch (row)
	{
	case 0:
		Address = col;
		break;
	case 1:
		Address = col + 0x40;
		break;
	}

	//to write to a specific address in the LCD
	// we need to apply the corresponding command 0x80 + Address

	LCD_SendCommand(Address | SET_CURSOR_LOCATION);
}

void LCD_ShowString(const char *Str)
{
	uint8_t i = 0;
	while (Str[i] != '\0')
	{
		LCD_SendData(Str[i]);
		i++;
	}
}

char *itoa(int i, char b[])
{
	char const digit[] = "0123456789";
	char *p = b;
	int shifter = i;
	if (i < 0)
	{
		*p++ = '-';
		i *= -1;
	}
	do
	{ //Move to where representation ends
		++p;
		shifter = shifter / 10;
	} while (shifter);
	*p = '\0';
	do
	{ //Move back, inserting digits as u go
		*--p = digit[i % 10];
		i = i / 10;
	} while (i);
	return b;
}

void LCD_IntgerToString(uint32_t Data)
{
	char string[32];
	itoa(Data, string);
	LCD_ShowStringRowAndColumn(0, 0, string);
}

void LCD_ShowStringRowAndColumn(uint8_t row, uint8_t col, const char *Str)
{
	LCD_GoToRowColumn(row, col); /* go to to the required LCD position */
	LCD_ShowString(Str);		 /* display the string */
}
