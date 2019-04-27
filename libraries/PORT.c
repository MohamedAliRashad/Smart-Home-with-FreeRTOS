#include "PORT.h"

void Port_Init(uint8_t port_index)
{

	switch (port_index)
	{
	case '0':					  //portA
		SYSCTL_RCGCGPIO_R = 0X01; //enable port A
		delayMS(20);
		GPIO_PORTA_LOCK_R = 0X4C4F434B;
		GPIO_PORTA_DEN_R = 0XFF;
		break;

	case '1':					  //port B
		SYSCTL_RCGCGPIO_R = 0X02; //enable port  B
		delayMS(20);
		GPIO_PORTB_LOCK_R = 0X4C4F434B;
		GPIO_PORTB_DEN_R = 0XFF;
		break;

	case '2':					  //port c
		SYSCTL_RCGCGPIO_R = 0X04; //enable port C
		delayMS(20);
		GPIO_PORTC_LOCK_R = 0X4C4F434B;
		GPIO_PORTC_DEN_R = 0XFF;
		break;

	case '3':					  //port D
		SYSCTL_RCGCGPIO_R = 0X08; //enable port D
		delayMS(20);
		GPIO_PORTD_LOCK_R = 0X4C4F434B;
		GPIO_PORTD_DEN_R = 0XFF;
		break;

	case '4':					  //port E
		SYSCTL_RCGCGPIO_R = 0X10; //enable port E
		delayMS(20);
		GPIO_PORTE_LOCK_R = 0X4C4F434B;
		GPIO_PORTE_DEN_R = 0XF;
		break;

	case '5':					  //port F
		SYSCTL_RCGCGPIO_R = 0X20; //enable port F
		delayMS(20);
		GPIO_PORTF_LOCK_R = 0X4C4F434B;
		GPIO_PORTF_DEN_R = 0XFF;
		break;
	}
}

void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, Port_PinDirectionType pins_direction)
{

	if (pins_direction)
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_DIR_R |= ~(pins_mask);
			break;
		case 1:
			GPIO_PORTB_DIR_R |= ~(pins_mask);
			break;
		case 2:
			GPIO_PORTC_DIR_R |= ~(pins_mask);
			break;
		case 3:
			GPIO_PORTD_DIR_R |= ~(pins_mask);
			break;
		case 4:
			GPIO_PORTE_DIR_R |= ~(pins_mask);
			break;
		case 5:
			GPIO_PORTF_DIR_R |= ~(pins_mask);
			break;
		}
	}
	else
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_DIR_R &= ~(pins_mask);
			break;
		case 1:
			GPIO_PORTB_DIR_R &= ~(pins_mask);
			break;
		case 2:
			GPIO_PORTC_DIR_R &= ~(pins_mask);
			break;
		case 3:
			GPIO_PORTD_DIR_R &= ~(pins_mask);
			break;
		case 4:
			GPIO_PORTE_DIR_R &= ~(pins_mask);
			break;
		case 5:
			GPIO_PORTF_DIR_R &= ~(pins_mask);
			break;
		}
	}
}

void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask, uint8_t enable)
{

	if (enable)
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_PUR_R |= pins_mask;
			break;
		case 1:
			GPIO_PORTB_PUR_R |= pins_mask;
			break;
		case 2:
			GPIO_PORTC_PUR_R |= pins_mask;
			break;
		case 3:
			GPIO_PORTD_PUR_R |= pins_mask;
			break;
		case 4:
			GPIO_PORTE_PUR_R |= pins_mask;
			break;
		case 5:
			GPIO_PORTF_PUR_R |= pins_mask;
			break;
		}
	}
	else
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_PUR_R &= ~pins_mask;
			break;
		case 1:
			GPIO_PORTB_PUR_R &= ~pins_mask;
			break;
		case 2:
			GPIO_PORTC_PUR_R &= ~pins_mask;
			break;
		case 3:
			GPIO_PORTD_PUR_R &= ~pins_mask;
			break;
		case 4:
			GPIO_PORTE_PUR_R &= ~pins_mask;
			break;
		case 5:
			GPIO_PORTF_PUR_R &= ~pins_mask;
			break;
		}
	}
}

void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask, uint8_t enable)
{

	if (enable)
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_PDR_R |= pins_mask;
			break;
		case 1:
			GPIO_PORTB_PDR_R |= pins_mask;
			break;
		case 2:
			GPIO_PORTC_PDR_R |= pins_mask;
			break;
		case 3:
			GPIO_PORTD_PDR_R |= pins_mask;
			break;
		case 4:
			GPIO_PORTE_PDR_R |= pins_mask;
			break;
		case 5:
			GPIO_PORTF_PDR_R |= pins_mask;
			break;
		}
	}
	else
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_PDR_R &= ~pins_mask;
			break;
		case 1:
			GPIO_PORTB_PDR_R &= ~pins_mask;
			break;
		case 2:
			GPIO_PORTC_PDR_R &= ~pins_mask;
			break;
		case 3:
			GPIO_PORTD_PDR_R &= ~pins_mask;
			break;
		case 4:
			GPIO_PORTE_PDR_R &= ~pins_mask;
			break;
		case 5:
			GPIO_PORTF_PDR_R &= ~pins_mask;
			break;
		}
	}
}
