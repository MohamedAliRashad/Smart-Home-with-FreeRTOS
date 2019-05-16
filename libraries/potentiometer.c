
#include "potentiometer.h"

uint16_t Read_Potentiometer()
{
    ADC0_start_conversion();
    return ADC0_digital_toVoltage(result);
}
