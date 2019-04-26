#ifndef UART_H   /* Include guard */
#define UART_H

// include Registers Header
#include "tm4c123gh6pm.h"
#include "stdint.h"

#endif /* UART_H */


uint32_t board_frequency ;

int8_t temp ;

int8_t motor_dir ;

int8_t potentiometer ;

void UART_init () ;

void send_data ( char title[] , int8_t data) ; // title : Temp or Potentiometer or Motor 
