#include "stdint.h"
#include "tm4c123gh6pm.h"
void systick_wait (uint32_t delay)
{
	NVIC_ST_RELOAD_R = delay-1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R & 0x0001000) ==0){}
}
void delayMS(uint32_t n)
{
uint32_t i;
	for(i=0;i<n;i++)
	{
		systick_wait(16000);
	}
}
void delayUS(uint32_t N)
{
uint32_t j;
	for(j=0;j<N;j++)
	{
		systick_wait(16);
	}
}
