#ifndef UART_H   /* Include guard */
#define UART_H

// include Registers Header
#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "stdbool.h"
#include "PLL.h"

extern uint32_t board_frequency ;

extern int8_t temp ;

extern int8_t motor_dir ;

extern int8_t potentiometer ;

void UART_init (bool intEn) ;


bool UART7_Send_NonBusy ( int8_t data ) ;
void UART7_send_Busy (int8_t data  ) ;
void UART7_send_data_packet ( char title[] , int8_t data)  ; // title : Temp or Potentiometer or Motor 

int8_t UART7_Recieve_Busy (void) ;
bool UART7_Recieve_NonBusy ( int8_t* data) ;
void UART7_recieve_packet (void);
#endif /* UART_H */

