#ifndef ADC_H
#define ADC_H

#include "stdint.h"
#include "tm4c123gh6pm.h"

typedef enum
{
    SW_TRIGGER,
    TIMER_TRIGGER
} triggerType;

extern uint16_t result;

/*************** Channel Numbers *************/

#define AIN0 0
#define AIN1 1
#define AIN2 2
#define AIN3 3

/*************** Functions Prototypes ***********************/

void ADC0_init(uint8_t channel_num, triggerType trig_type);

void ADC0_channelConfig(uint8_t channel_num);

void ADC0_start_conversion(void);

float ADC0_digital_toVoltage(uint16_t digital_value);

#endif
