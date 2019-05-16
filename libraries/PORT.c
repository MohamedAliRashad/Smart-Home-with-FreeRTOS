#include "PORT.h"

void Port_Init(uint8_t port_index)
{
	SYSCTL_RCGCGPIO_R |= (1 << port_index);
	volatile uint8_t delay = 1;

	switch (port_index)
	{
	case 0: //portA
		GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
		GPIO_PORTA_CR_R = 0xFF;
		GPIO_PORTA_AFSEL_R = 0x00;
		GPIO_PORTA_PCTL_R = 0;
		GPIO_PORTA_AMSEL_R = 0;
		GPIO_PORTA_DEN_R = 0xFF;
		break;

	case 1: //port B
		GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
		GPIO_PORTB_CR_R = 0xFF;
		GPIO_PORTB_AFSEL_R = 0x00;
		GPIO_PORTB_PCTL_R = 0;
		GPIO_PORTB_AMSEL_R = 0;
		GPIO_PORTB_DEN_R = 0xFF;
		break;

	case 2: //port c
		GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;
		GPIO_PORTC_CR_R = 0xFF;
		GPIO_PORTC_AFSEL_R = 0x00;
		GPIO_PORTC_PCTL_R = 0;
		GPIO_PORTC_AMSEL_R = 0;
		GPIO_PORTC_DEN_R = 0xFF;
		break;

	case 3: //port D
		GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
		GPIO_PORTD_CR_R = 0xFF;
		GPIO_PORTD_AFSEL_R = 0x00;
		GPIO_PORTD_PCTL_R = 0;
		GPIO_PORTD_AMSEL_R = 0;
		GPIO_PORTD_DEN_R = 0xFF;
		break;

	case 4: //port E
		GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;
		GPIO_PORTE_CR_R = 0xFF;
		GPIO_PORTE_AFSEL_R = 0x00;
		GPIO_PORTE_PCTL_R = 0;
		GPIO_PORTE_AMSEL_R = 0;
		GPIO_PORTE_DEN_R = 0xFF;
		break;

	case 5: //port F
		GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
		GPIO_PORTF_CR_R = 0xFF;
		GPIO_PORTF_AFSEL_R = 0x00;
		GPIO_PORTF_PCTL_R = 0;
		GPIO_PORTF_AMSEL_R = 0;
		GPIO_PORTF_DEN_R = 0xFF;
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
			GPIO_PORTA_DIR_R |= pins_mask;
			break;
		case 1:
			GPIO_PORTB_DIR_R |= pins_mask;
			break;
		case 2:
			GPIO_PORTC_DIR_R |= pins_mask;
			break;
		case 3:
			GPIO_PORTD_DIR_R |= pins_mask;
			break;
		case 4:
			GPIO_PORTE_DIR_R |= pins_mask;
			break;
		case 5:
			GPIO_PORTF_DIR_R |= pins_mask;
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
