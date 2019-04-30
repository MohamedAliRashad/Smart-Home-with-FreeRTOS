/*
* TIVA-C Internal Temperature Sensor
* Built on the top of the ADC Driver
* 30/4/2019
*
*/

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "ADC.h"


void TempSensor_init();
        /* Initialize Temperature sensor */


float TempSensor_readTemp();
        /* read Temperature from sensor */
        

 

