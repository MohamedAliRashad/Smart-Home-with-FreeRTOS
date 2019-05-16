/*
 * GPIO.h
 *  Created on: May 16, 2019
 *      Author: Hp
 */

#ifndef GPIO_H_
#define GPIO_H_


// include Registers Header
#include "tm4c123gh6pm.h"
#include "stdint.h"

void Port_Init(unsigned int port_index);
void Port_SetPinDirection(unsigned int port_index,unsigned int pins_mask,int pins_direction);
unsigned int Read_Port(uint8_t port_index,uint8_t pins_mask);
void Write_Port(uint8_t port_index,uint8_t pins_mask,Dio_levelType pins_level);


#endif /* GPIO_H_ */
