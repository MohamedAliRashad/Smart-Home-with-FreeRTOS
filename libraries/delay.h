#ifndef DELAY_H /* Include guard */
#define DELAY_H

#include "stdint.h"
#include "tm4c123gh6pm.h"

void systick_init(void);

void systick_wait(uint32_t delay);

void delayMS(uint32_t n);

void delayUS(uint32_t N);

#endif /* DELAY_H */
