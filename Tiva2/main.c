#include <stdint.h>
#include <FreeRTOS.h>
#include <task.h>
#include "LCD.h"
#include "Temp_Sensor.h"
#include "potentiometer.h"
#include "interrupt.h"
#include "uart.h"
#include "PLL.h"
#include "ADC.h"

typedef struct {
	uint16_t value;
	uint8_t valid;
} MailBox;

MailBox MotorMailBox;
MailBox PotMailBox;
MailBox TempMailBox;

//extern uint32_t board_frequency ;

//extern int8_t temp ;

//extern int8_t motor_dir ;

//extern int8_t potentiometer ;


void vLCDTask(void *pvParameters);

void vPushTask(void *pvParameters);

void vPotTask(void *pvParameters);

void vTempTask(void *pvParameters);

void vUARTSendTask(void *pvParameters);

void vUARTReceiveTask(void *pvParameters);

void vUARTTask(void *pvParameters);

void GPIOF_Handler(void)
{
	GPIO_PORTF_IM_R |= 0;
	
	if(GPIO_PORTF_RIS_R & PF0){
		while(!UART7_Send_NonBusy(1));
	}
	else{
		while(!UART7_Send_NonBusy(2));
	}
	
	GPIO_PORTF_IM_R |= PF0 | PF4;
	
}

uint16_t map(uint16_t RangeS_0, uint16_t RangeE_0, uint16_t RangeS_1, uint16_t RangeE_1, uint16_t value_0){

uint16_t res = ( (RangeE_1 - RangeS_1)* (value_0 -RangeS_0))/(RangeE_0 - RangeS_0) ;
	
	return res + RangeS_1 ;
}

int main(void){
		
	PLL_Init();
	UART_init (115200);
	ADC0_init(AIN0, SW_TRIGGER);
	
	Port_Init(PORTF);
	Port_SetPinDirection(PORTF, PF0, PORT_PIN_IN);//switch 1
	Port_SetPinDirection(PORTF, PF4, PORT_PIN_IN);//switch 2

	Port_SetPinPullUp(PORTF, PF0, 1);
	Port_SetPinPullUp(PORTF, PF4, 1);

	initalize_PORTF_interrupt(PF0 | PF4);
	
	//Tasks runs here
	xTaskCreate(vLCDTask, "LCDTask", 256, NULL, 1, NULL);
	xTaskCreate(vUARTSendTask, "vUARTSendTask", 256, NULL, 1, NULL);
	xTaskCreate(vUARTReceiveTask, "vUARTReceiveTask", 256, NULL, 1, NULL);

	vTaskStartScheduler();

	while(1); //should never reach here
}

void vLCDTask(void *pvParameters){
	
	LCD_init();
	
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();

	while(1){
		if(TempMailBox.valid == 1){
			LCD_IntgerToString(TempMailBox.value);
			LCD_SendData(0xDF);
			LCD_SendData('C');
			TempMailBox.valid = 0;
		}
		
		// Block until the next release time.
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}	

}

//void vPushTask(void *pvParameters){
//	
//	initalize_PORTF_interrupt(PF0 | PF4);
//	while(1);
//}


//void vPotTask(void *pvParameters){
//	
//	while(1){
//		if(PotMailBox.valid == 0){
//			PotMailBox.value = Read_Potentiometer(AIN0);
//			PotMailBox.valid = 1;
//		}
//	}
//	
//}

void vUARTSendTask(void *pvParameters){

	while(1){
	
		while(!UART7_Send_NonBusy((uint8_t)map(0, 4095, 3, 255, Read_Potentiometer()))){}
		
		taskYIELD();
	}
}

void vUARTReceiveTask(void *pvParameters){
	
	uint8_t data;
	
	while(1){
		
		if(UART7_Recieve_NonBusy(&data)){			
			if(TempMailBox.valid == 0){
				TempMailBox.value = data;
				TempMailBox.valid = 1;
			}
		}
		taskYIELD();
	}
}
