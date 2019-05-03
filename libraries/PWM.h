#ifndef PWM_H /* Include guard */
#define PWM_H

// include Registers Header
#include "tm4c123gh6pm.h"
#include <stdint.h>

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

bool SetPinFrequency(int8_t pin, uint32_t freq);
/*
Description: Sets the frequency of the PWM signal for a pin.

Parameters:
    1- pin: Pin Number of the port.
    2- freq: The prescaller value for the tiva frequency.
        Example:
            Set pin 6's PWM frequency to 62500 Hz (62500/1 = 62500)
            The base frequency here was 62500 Hz
            setPwmFrequency(6, 1);
        Another Example:
            Set pin 9's PWM frequency to 3906 Hz (31250/8 = 3906)
            The base frequency here was 3906 Hz
            setPwmFrequency(9, 8);

Return:
    Nothing
*/

void pwmWrite(uint8_t pin, uint8_t val);
/*
Description: Writes an analog value (PWM wave) to a pin.

Parameters:
    1- pin: Pin Number of the port.
    2- val: The duty cycle between 0 (always off) - 255 (always on) 

Return:
    Nothing
*/

#endif /* PWM_H */
