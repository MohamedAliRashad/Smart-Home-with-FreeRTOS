#include <stdint.h>
#include <FreeRTOS.h>
#include <task.h>
#include "Temp_Sensor.h"
#include "uart.h"
#include "PORT.h"
#include "DIO.h"
#include "interrupt.h"
#include "PLL.h"
#include "PWM.h"

typedef struct {
	uint8_t value;
	uint8_t valid;
} MailBox;

MailBox LEDMailBox;
MailBox TempMailBox;
MailBox MotorMailBox;

void vLEDTask(void *pvParameters);

void vMotorTask(void *pvParameters);

void vTempTask(void *pvParameters);

void vUARTSendTask(void *pvParameters);

void vUARTReceiveTask(void *pvParameters);

uint16_t map(uint16_t RangeS_0, uint16_t RangeE_0, uint16_t RangeS_1, uint16_t RangeE_1, uint16_t value_0){

	uint16_t res = ( (RangeE_1 - RangeS_1)* (value_0 -RangeS_0))/(RangeE_0 - RangeS_0) ;
	
	return res + RangeS_1 ;
}


int main(void)
{
		PLL_Init();
		UART_init (115200) ;
		PWM_Init();
		
    //Tasks runs here
		xTaskCreate(vTempTask, "TempratureTask", 256, NULL, 1, NULL);
		xTaskCreate(vUARTSendTask, "UARTSendTask", 256, NULL, 1, NULL);
		xTaskCreate(vUARTReceiveTask, "UARTReceiveTask", 256, NULL, 1, NULL);

    vTaskStartScheduler();
	
    while(1); //should never reach here


}

//void vLEDTask(void *pvParameters){
//	
//	LED_init();
//	
//	while(1){
//		
//	
//	}
//	vTaskDelete( NULL );
//}

//void vMotorTask(void *pvParameters){
//	
//	Motor_init();
//	
//	while(1){
//		
//	
//	}
//	vTaskDelete( NULL );
//}

void vTempTask(void *pvParameters){
	
	TempSensor_init();
	
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	while(1){
		
		if (TempMailBox.valid == 0){
			TempMailBox.value = TempSensor_readTemp();
			TempMailBox.valid = 1;
		}
		
		// Block until the next release time.
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}	
}

void vUARTSendTask(void *pvParameters){

	while(1){
		
		if(TempMailBox.valid == 1){
			while(!UART7_Send_NonBusy(TempMailBox.value));
			TempMailBox.valid = 0;
			taskYIELD();
		}
	}
}

void vUARTReceiveTask(void *pvParameters){
	uint8_t data = 0;
	while(1){
		if(UART7_Recieve_NonBusy(&data)){
		if(data == 1){

		}else if (data == 2){

		}else if (data == 0){
			
		}else{
			 PWM_set_dutyCycle(map(3, 255, 0, 5000, data));
		}
	}
		taskYIELD();
}
	}