#include "stdint.h"
#include"tm4c123gh6pm.h"
#define PF0 0x0U
#define PF4 0x08U
void initalize_PORTF_interrupt(uint8_t pinsmask)
{
		GPIO_PORTF_IM_R = 0;
		GPIO_PORTF_IS_R |= pinsmask;
		GPIO_PORTF_IBE_R &= ~pinsmask; 
		GPIO_PORTF_IEV_R &= ~pinsmask;
		GPIO_PORTF_RIS_R = 0;
		GPIO_PORTF_IM_R |= pinsmask;		
		NVIC_EN0_R |=1<<30;
       	
}



void GPIOF_Handler(void)
{
	GPIO_PORTF_IM_R |= 0;
	
	if(GPIO_PORTF_RIS_R & PF0){
		//
	}
	else{
		//
	}
	
	GPIO_PORTF_IM_R=PF0|PF4;
}