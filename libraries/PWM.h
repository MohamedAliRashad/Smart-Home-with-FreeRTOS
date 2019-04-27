#ifndef PWM_H /* Include guard */
#define PWM_H

// include Registers Header
#include "tm4c123gh6pm.h"
#include <stdint.h>

typedef unsigned char bool;

void InitTimers();
/*
Description: Initialize the PWM Timers by
    1- Enable the PWM clock through the RCGC0.
    2- Enable the clock to the appropriate GPIO module via RCGC2   <check with the others if no one accessed this>

Parameters:
    Nothing

Return:
    Nothing
*/

bool SetPinFrequency(int8_t pin, uint32_t frequency);

void pwmWrite(uint8_t pin, uint8_t val);
/*
Description: 
    1- Enable the PWM clock through the RCGC0.
    2- Enable the clock to the appropriate GPIO module via RCGC2   <check with the others if no one accessed this>

Parameters:
    1- pin: Pin Number of the port.
    2- val: 

Return:
    Nothing
*/

#endif /* PWM_H */
