#ifndef INT_H
#define INT_H

#define PF0 0x01
#define PF4 0x10

#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "PORT.h"

void initalize_PORTF_interrupt(uint8_t pinsmask);
/* pinsmask: Choose the pins you want the interrupt to take into consideration */

#endif