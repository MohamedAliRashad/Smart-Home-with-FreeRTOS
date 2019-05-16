#ifndef UART_H   /* Include guard */
#define UART_H

// include Registers Header
#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "stdbool.h"

void UART_init (int Baudrate) ;

bool UART7_Send_NonBusy (uint8_t data ) ;

bool UART7_Recieve_NonBusy (uint8_t* data) ;
#endif /* UART_H */

