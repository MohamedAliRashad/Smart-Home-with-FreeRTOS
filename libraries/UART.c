#include "uart.h"


 uint32_t board_frequency ;

 int8_t temp ;

 int8_t motor_dir ;

 int8_t potentiometer ;






void UART7_send_data_packet ( char title[] , int8_t data) { 
	

	UART7_send_Busy ( title [0] );
	
	UART7_send_Busy ( data );

	
	
}










void UART7_recieve_packet () { 


int word = UART7_Recieve_Busy() ;
	
	
			switch (word )
										{
											case 'T' : temp = UART7_Recieve_Busy() ; break ;
											case 'M' : motor_dir = UART7_Recieve_Busy() ; break ;
											case 'P' : potentiometer = UART7_Recieve_Busy() ; break ;	
										}

}




