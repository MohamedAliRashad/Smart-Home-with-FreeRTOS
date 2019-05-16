#include "delay.h"

//void systick_init(void){
//	NVIC_ST_CTRL_R = 0;
//	NVIC_ST_RELOAD_R = 0x00FFFFFF;
//	NVIC_ST_CURRENT_R = 0;
//	NVIC_ST_CTRL_R = 0x00000005;

//}

//void systick_wait(uint32_t delay)
//{
//	systick_init();
//	NVIC_ST_RELOAD_R = delay - 1;
//	NVIC_ST_CURRENT_R = 0;
//	while ((NVIC_ST_CTRL_R & 0x00010000) == 0)
//		;
//}

//void delayMS(uint32_t n)
//{
//	uint32_t i;
//	for (i = 0; i < n; i++)
//	{
//		systick_wait(16000);
//	}
//}

//void delayUS(uint32_t N)
//{
//	uint32_t j;
//	for (j = 0; j < N; j++)
//	{
//		systick_wait(16);
//	}
//}


//void GPTM_init(void){
//	 |= (1<<0);
//	NVIC_ST_RELOAD_R = 0x00FFFFFF;
//	NVIC_ST_CURRENT_R = 0;
//	NVIC_ST_CTRL_R = 0x00000005;

//}

//void GPTM_wait(uint32_t delay)
//{
//	NVIC_ST_RELOAD_R = delay - 1;
//	NVIC_ST_CURRENT_R = 0;
//	while ((NVIC_ST_CTRL_R & 0x0001000) == 0)
//		;
//}

void delayMS(uint32_t n)
{
	uint32_t i;
	for (i = 0; i < n*3180; i++)
	{}
}

void delayUS(uint32_t N)
{
	uint32_t j;
	for (j = 0; j < N*16; j++)
	{}
}

