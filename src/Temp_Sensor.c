#include "Temp_Sensor.h"


void TempSensor_init(void)
{

  ADC0_init(AIN0, TIMER_TRIGGER); /* Initialize ADC with Analog Input Channel 0 and timer periodic triggering */
	ADC0_SSCTL3_R |= 0x0E;          /* set register content to 0000 1110 */
                                    /* reset bit0: single ended input */	
                                    /* Set bit3: for internal temp sensor enabling */	
}

float TempSensor_readTemp(void)
{
    float temp = 0.0;
    ADC0_start_conversion(); 
		temp = 147.5 - (247 * result) / 4096; /* from the datasheet */
    return temp;
}
