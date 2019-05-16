#ifndef UART_H /* Include guard */
#define UART_H

// include Registers Header
#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "stdbool.h"

void UART7_init(int Baudrate);
/* Everything about UART7 initialization */

bool UART7_Send(uint8_t data);
/* sends the data and returns a bool value to inform if the data was correctly send or not */

bool UART7_Recieve(uint8_t *data);
/* recieves data and returns a bool value to inform if the data recieved valid or not */

#endif /* UART_H */
