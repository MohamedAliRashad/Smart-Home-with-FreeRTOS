#include "UART.h"

#define board_frequency 16000000

void UART7_init(int Baudrate)
{

	float BRD = (board_frequency) / (16.0 * Baudrate);

	NVIC_EN0_R = 0x40;

	SYSCTL_RCGCUART_R |= 0x080;

	///////////portE/////////////using uart 7

	SYSCTL_RCGCGPIO_R |= 0x010;

	GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;

	GPIO_PORTE_CR_R = 0x03;

	GPIO_PORTE_AMSEL_R = 0x0;

	GPIO_PORTE_AFSEL_R = 0x03;

	GPIO_PORTE_DEN_R |= 0x03;

	GPIO_PORTE_DIR_R |= 0x02;

	GPIO_PORTE_PCTL_R = 0x11;

	///////////////////////

	UART7_CTL_R = 0x00; //disable for config

	UART7_IBRD_R = (int)BRD;

	UART7_FBRD_R = (int)(((BRD - (int)BRD) * 64) + 0.5);

	UART7_LCRH_R = 0x72; // frame 8 bits , fifo enabled , odd parity enabled

	UART7_CC_R = 0x00; //use system clock with BRD regs

	///////////////////////

	UART7_CTL_R = 0x301; //enable  UART + TX RX
}

bool UART7_Send_NonBusy(uint8_t data)
{

	if ((UART7_FR_R & 0x20) == 0)

	{
		UART7_DR_R = data;
		return true;
	}

	return false;
}

bool UART7_Recieve_NonBusy(uint8_t *data)
{

	uint8_t word;

	if ((UART7_FR_R & 0x0010) == 0)
	{

		*data = UART7_DR_R & 0xff;

		return true;
	}

	return false;
}
