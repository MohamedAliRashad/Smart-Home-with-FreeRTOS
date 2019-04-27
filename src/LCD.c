#include "LCD.h"

void LCD_data(char data) //sending data to lcd function
{
	GPIO_PORTD_DATA_R = 0x01;  //setting RS=1 & RW=0
	GPIO_PORTB_DATA_R = data;  //send data to lcd
	GPIO_PORTD_DATA_R |= 0x04; //enable "E" is high
	delayUS(100);			   //high to low delay (might be adjusted)
	GPIO_PORTD_DATA_R = 0;	 //enable "E" is low
}

void LCD_command(char com) //sending command through port B function
{
	GPIO_PORTD_DATA_R = 0;	 //RS & RW =0
	GPIO_PORTB_DATA_R = com;   //sending command to lcd
	GPIO_PORTD_DATA_R |= 0x04; //enable "E" is high
	delayUS(100);			   //high to low delay (might be adjusted)
	GPIO_PORTD_DATA_R = 0;	 //enable "E" is low
}

void LCD_init() //microcontroller initialization aiming to LCD "USING FULL PINS OF PORT B"
{
	Port_Init(1); //Port B init
	Port_SetPinDirection(1, 0xFF, 1);
	/* init of port D pins 0,1,2 */
	SYSCTL_RCGCGPIO_R |= 0x08;
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R |= 0x07;
	GPIO_PORTD_AFSEL_R = 0;
	GPIO_PORTD_PCTL_R = 0;
	GPIO_PORTD_AMSEL_R = 0;
	GPIO_PORTD_DEN_R |= 0x07;
	GPIO_PORTD_DIR_R |= 0x07;
	/* end init of port D */
	LCD_command(0x30); //lcd wakeup
	delayUS(45);	   //wakeup delay
	LCD_command(0x0F); //lcd display on & cursor blinking
	delayUS(45);	   //lcd display on delay
	LCD_command(0x38); //2 lines 5*7 characters
	delayUS(45);	   //2 lines 5*7 characters delay
	LCD_command(0x01); //clear display screen
	delayMS(2);		   //clear display screen
}
