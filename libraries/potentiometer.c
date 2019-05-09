
#include "potentiometer.h"


float Read_Potentiometer(uint8_t channel)
{
    float voltge;
    ADC0_init(channel, TIMER_TRIGGER); /* Initialize ADC with Analog Input Channel 1 and timer periodic triggering */
    ADC0_start_conversion(); 
    voltage = ADC0_digital_toVoltage(result);
    return voltage ; 
}

