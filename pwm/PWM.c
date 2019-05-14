#include "PWM.h"


void Enable_PWM_clk ()
{
	SYSCTL_RCGCPWM_R |= 0x02; // enable PWM Module in run mode 
}


void PWM_PORT_config()
{
	SYSCTL_RCGCGPIO_R |= 0x20; /// PORTF CLOCK Enable
	/*
	GPIO_PORTF_AFSEL_R |= GPIO_PF2_M;
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF) | (GPIO_PCTL_PF2_M1PWM6);
	                                                     //0x00000500  // M1PWM6 on PF2
	GPIO_PORTF_DIR_R |= GPIO_PF2_M;
	GPIO_PORTF_DEN_R |= GPIO_PF2_M;
	*/

}
//void PWM_Init(uint32_t Frequency , uint32_t Duty , uint32_t Mask
void PWM_Init()
{
	
	Enable_PWM_clk();
	
	PWM_PORT_config();

	
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV; //0x00100000  Enable PWM Clock Divisor
	SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock =16M/64= 250kHz //0x000A0000 PWM clock /64
	PWM1_3_CTL_R = 0x00000000;
	PWM1_3_GENA_R = 0x0000008C; // Drive PWM High at reload value and drive it to zero when it matches CMP
	PWM1_3_LOAD_R = 5000 - 1; // 1KHz
	PWM1_3_CMPA_R = 5000 - 2; // 0% Duty Cycle // from 0 to 5000-2 5alik zero 8er keda 2b2a 1 
	PWM1_3_CTL_R = PWM_0_CTL_ENABLE;	// Set bit 0 to enable PWM1
	
	//PWM_PORT_config();
	
	GPIO_PORTF_AFSEL_R |= GPIO_PF2_M;
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF) | (GPIO_PCTL_PF2_M1PWM6);
	                                                     //0x00000500  // M1PWM6 on PF2
	GPIO_PORTF_DIR_R |= GPIO_PF2_M;
	GPIO_PORTF_DEN_R |= GPIO_PF2_M;
	
	PWM1_ENABLE_R = PWM_ENABLE_PWM6EN; // M1PWM6 (PF2)

}


void PWM_set_dutyCycle(uint32_t duty_cycle)
{ 
	PWM1_3_CMPA_R= duty_cycle ;
}