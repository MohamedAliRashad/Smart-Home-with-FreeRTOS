#include "interrupt.h"

void initalize_PORTF_interrupt(uint8_t pinsmask)
{
	GPIO_PORTF_IM_R = 0;
	GPIO_PORTF_IS_R |= pinsmask;
	GPIO_PORTF_IBE_R &= ~pinsmask;
	GPIO_PORTF_IEV_R &= ~pinsmask;
	GPIO_PORTF_RIS_R = 0;
	GPIO_PORTF_IM_R |= pinsmask;
	NVIC_EN0_R |= 1 << 30;
}
void GPIOF_Handler(void)
{
	GPIO_PORTF_IM_R |= 0; // Inmasking or disabling interrupts for PORTF untill the handler finished excution

	if (GPIO_PORTF_RIS_R & PF0)
	{
		// What do you want the Tiva to do if SW2 was clicked
	}
	else
	{
		// What do you want the Tiva to do if SW1 was clicked
	}

	GPIO_PORTF_IM_R = PF0 | PF4; // Enabling the interrupts for SW1 & SW2 again
}