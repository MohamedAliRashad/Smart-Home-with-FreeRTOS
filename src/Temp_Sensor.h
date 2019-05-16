/*
* TIVA-C Internal Temperature Sensor
* Built on the top of the ADC Driver
* 30/4/2019
*
*/
#ifndef TEMP_H
#define TEMP_H

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "ADC.h"

void TempSensor_init(void);
        /* Initialize Temperature sensor */


float TempSensor_readTemp(void);
        /* read Temperature from sensor */
        
#endif
