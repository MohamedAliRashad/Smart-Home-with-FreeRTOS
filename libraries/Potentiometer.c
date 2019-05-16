
#include "potentiometer.h"

uint16_t Read_Potentiometer()
{
    //ADC0_init(channel, SW_TRIGGER); /* Initialize ADC with Analog Input Channel 1 and timer periodic triggering */
    ADC0_start_conversion();
		return result;
}
