#ifndef PWM_H   /* Include guard */
#define PWM_H

// include Registers Header
#include "tm4c123gh6pm.h"
#include "stdint.h"

#define GPIO_PF2_M	0x04

void Enable_PWM_clk();
void PWM_PORT_config();
void PWM_Init();
void PWM_set_dutyCycle(uint32_t dutyCycle);


#endif /* PWM_H */
