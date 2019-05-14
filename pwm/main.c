#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "PWM.h"



void SystemInit(void){
}




void BlueLED_SetDutyCycle(uint8_t duty_cycle){
	if(duty_cycle == 100){
		PWM1_3_CMPA_R = 1;
	} else if(duty_cycle == 0) {
		PWM1_3_CMPA_R = 1248;
	}else {
		PWM1_3_CMPA_R = (uint16_t)(1250 * (1 - (duty_cycle / 100.0)) - 1);
	}
}
void delay_milli(uint32_t n)
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++)
{}
}

uint8_t reading;     // value came via UART

int main()
{
	PWM_Init();
	
while (1)
{
	/*PWM_set_dutyCycle(0); //  0% duty cycle // el led mabtnawrsh 
	delay_milli(1000);
	PWM_set_dutyCycle(50); // 50% duty cycle
	delay_milli(1000);*/
	PWM_set_dutyCycle(5);// 100 % duty cycle // el led btnawr
   delay_milli(1000);
	
	
	
}

}