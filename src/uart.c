

#include "UART.h"



extern uint32_t board_frequency ;


int8_t temp ;

int8_t motor_dir ;

int8_t potentiometer ;

void UART_init () { 
	
	SYSCTL_RCGCUART_R |= 0x080 ;
	
	
	
	///////////portE/////////////using uart 7
	SYSCTL_RCGCGPIO_R |= 0x010 ;
	
	GPIO_PORTE_AMSEL_R = 0x0 ;
	
	GPIO_PORTE_AFSEL_R = 0x03 ;
	
	GPIO_PORTE_CR_R = 0x03 ;
	
	GPIO_PORTE_DEN_R |= 0x03; 
	
	GPIO_PORTE_DIR_R |= 0x02 ;
	
	GPIO_PORTE_PCTL_R = 0x11 ;
	
	///////////////////////
	
	
	uint32_t BRD = (board_frequency )/(16 * 115200 ) ;
	
	UART7_CTL_R = 0x00 ;  //disable for config 
	
	
	UART7_IBRD_R  = (int) BRD ;
	
	UART7_FBRD_R = (int) ( ( (BRD - (int)BRD )   * 64  )+ 0.5 ) ;
	

  UART7_LCRH_R = 0x71 ; // frame 8 bits , fifo enabled , parity enabled
	
	UART7_CC_R = 0x00 ; //use system clock with BRD regs 
	

	//////////interrupts /////////
	
	// UART7_IM_R = 0x0ff0 ;
	UART7_IM_R = 0x0050 ;
	
	//sending packets that contain all the variables //
	
	UART7_IFLS_R = 0x01 ; //interrupt on reciever when recieved 4 words 
	
	
	///////////////////////
	
		UART7_CTL_R = 0x311 ;  //enable  TX RX + EOT -> interrupt when transmit fifo is empty
	
	
	
}






void UART7_Handler (void) {

	int8_t word ;
	
				if ( (UART7_MIS_R &0x10 )!= 0 ) //recieved 4 words 
				{	
					UART7_ICR_R |= 0x10 ;
							for (int i =0 ; i<=1 ; i++)
						{
							word = UART7_DR_R ;
										switch (word )
										{
											case 'T' : temp = UART7_DR_R ; break ;
											case 'M' : motor_dir = UART7_DR_R ; break ;
											case 'P' : temp = UART7_DR_R ; break ;	
										}
	
						}
					
				
				}
				
				
					if ( (UART7_MIS_R &0x40 )!= 0 ) //recieve timeout

							{
								UART7_ICR_R |= 0x40 ;
								 //packet is not correct , empty the fifo 
								while ((UART7_FR_R & 0x10 ) == 0 ){
								
								word = UART7_DR_R ;
								
											while ((UART7_FR_R & 0x08 )  ); //wait until not busy 
								}
								
							}
	
	
}





void send_data ( char title[] , int8_t data) { 
	
	while (  (UART7_FR_R & 0x10 ) != 0  ) ;
	UART7_DR_R = title[0] ;
	while (  (UART7_FR_R & 0x10 ) != 0  ) ;
	UART7_DR_R = data ;
	
	
}





