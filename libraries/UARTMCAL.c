#include "uart.h"



void UART7_init (  bool intEn , uint32_t baudRate ) { 

		
	
	
float BRD = (board_frequency )/(16.0 * baudRate ) ;
	
NVIC_EN0_R = 0x40 ;
	
	SYSCTL_RCGCUART_R |= 0x080 ;

	
	///////////portE/////////////using uart 7
	SYSCTL_RCGCGPIO_R |= 0x010 ;
	
	GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY ;
	
	GPIO_PORTE_CR_R = 0x03 ;
	
	
	GPIO_PORTE_AMSEL_R = 0x0 ;
	
	GPIO_PORTE_AFSEL_R = 0x03 ;
	

	GPIO_PORTE_DEN_R |= 0x03; 
	
	GPIO_PORTE_DIR_R |= 0x02 ;
	
	GPIO_PORTE_PCTL_R = 0x11 ;
	
	///////////////////////
	
	
	
	UART7_CTL_R = 0x00 ;  //disable for config 
	
	
	UART7_IBRD_R  =(int) BRD ;
	
	UART7_FBRD_R = (int) ( ( (BRD - (int)BRD )   * 64  )+ 0.5 ) ;
	

  UART7_LCRH_R = 0x72 ; // frame 8 bits , fifo enabled , odd parity enabled
	
	UART7_CC_R = 0x00 ; //use system clock with BRD regs 
	

	//////////interrupts /////////
	
	
	if(intEn) UART7_IM_R = 0x0050 ;
	else  UART7_IM_R = 0x0000 ;
	
	//sending packets that contain all the variables //
	
	UART7_IFLS_R = 0x08 ; //interrupt on reciever when recieved 4 words 
	
	
	///////////////////////
	
		UART7_CTL_R = 0x301 ;  //enable  UART + TX RX 
	
	

}
















void UART7_Handler (void) {
	
int i =0 ;
	int8_t word ;
	
				if ( (UART7_MIS_R &0x10 )!= 0 ) //recieved 4 words 
				{	
					UART7_ICR_R |= 0x10 ;
					
							for ( i =0 ; i<=1 ; i++)
						{
							word = UART7_DR_R ;
										switch (word )
										{
											case 'T' : temp = UART7_DR_R & 0xff ; break ;
											case 'M' : motor_dir = UART7_DR_R & 0xff ; break ;
											case 'P' : potentiometer = UART7_DR_R  & 0xff ; break ;	
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











bool UART7_Send_NonBusy ( int8_t data ) { 

	if  (  (UART7_FR_R & 0x20 ) == 0  ) 
		
	{
	UART7_DR_R = data ;	
	return true ;
	}
	
	return false ;
	
}





void UART7_send_Busy (int8_t data  ) {
	
	while (  (UART7_FR_R & 0x20 ) != 0  ) ;
	UART7_DR_R = data ;
	}








int8_t UART7_Recieve_Busy () { 


	
			while(  (UART7_FR_R & 0x0010)      !=0 ) {}
						
				return UART7_DR_R  & 0xff ;
	
				
	

}

bool UART7_Recieve_NonBusy ( int8_t* data) { 

int8_t word ;
	
			if(  (UART7_FR_R & 0x0010)      ==0 ) {
						
				*data = UART7_DR_R  & 0xff ;
				
				return true ;
	
			}
			
			return false ;
				
	

}







