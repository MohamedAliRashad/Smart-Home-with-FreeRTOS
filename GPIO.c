#include <C:/Keil/Datasheets/tm4c123gh6pm.h>
#include "stdint.h"


void Port_Init(unsigned int port_index)

/****Initialize port based on selected port_index (0 to 5)*****
*****by enabling the clock, unlocking the port, and making*****
*****the selected mode digital*********************************/

{
volatile unsigned long delay;

    if(port_index == 0)
    {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;          //PORTA
    delay=SYSCTL_RCGCGPIO_R;
    GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;                // Unlock PortA Commit register
    }

    else if(port_index == 1)
    {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;         //PORTB
    delay=SYSCTL_RCGCGPIO_R;
    GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;               // Unlock PortB Commit register
    }

    else if(port_index == 2)
    {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;         //PORTC
    delay=SYSCTL_RCGCGPIO_R;
    GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;               // Unlock PortC Commit register
    }

    else if(port_index == 3)
    {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;         //PORTD
    delay=SYSCTL_RCGCGPIO_R;
    GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;               // Unlock PortD Commit register/
    }

    else if(port_index == 4)
    {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;         //PORTE
    delay=SYSCTL_RCGCGPIO_R;
    GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;               // Unlock PortE Commit register
    }

    else if(port_index == 5)
    {
    SYSCTL_RCGCGPIO_R |=  SYSCTL_RCGCGPIO_R5;        //PORTF
    delay=SYSCTL_RCGCGPIO_R;
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;               // Unlock PortF Commit register
    }
}

    /*************************************************************************************
     *************************************************************************************/

    void Port_SetPinDirection(unsigned int port_index,unsigned int pins_mask,int pins_direction)
    {
    /************Change the direction of the selected pins by pins_mask********************
    *************mask in the port selected by port_index**********************************/

        if(port_index == 0)                     //PORTA
        {
         if (pins_direction == 1)               //1 means output
         GPIO_PORTA_DIR_R |= pins_mask ;
         else                                   //0 means input
         GPIO_PORTA_DIR_R &= ~pins_mask ;
        }

    else if(port_index == 1)                   //PORTB
        {
        if (pins_direction == 1)               //1 means output
        GPIO_PORTB_DIR_R |= pins_mask ;
        else                                   //0 means input
        GPIO_PORTB_DIR_R &= ~pins_mask ;
        }

    else if(port_index == 2)                   //PORTC
        {
        if (pins_direction == 1)               //1 means output
        GPIO_PORTC_DIR_R |= pins_mask ;
        else                                   //0 means input
        GPIO_PORTC_DIR_R &= ~pins_mask ;
        }

    else if(port_index == 3)                   //PORTD
        {
        if (pins_direction == 1)               //1 means output
        GPIO_PORTD_DIR_R |= pins_mask ;
        else                                   //0 means input
        GPIO_PORTD_DIR_R &= ~pins_mask ;
        }

    else if(port_index == 4)                   //PORTE
        {
        if (pins_direction == 1)               //1 means output
        GPIO_PORTE_DIR_R |= pins_mask ;
        else                                   //0 means input
        GPIO_PORTE_DIR_R &= ~pins_mask ;
        }

    else if(port_index == 5)                   //PORTF
        {
        if (pins_direction == 1)               //1 means output
        GPIO_PORTF_DIR_R |= pins_mask ;
        else                                   //0 means input
        GPIO_PORTF_DIR_R &= ~pins_mask ;
        }
    }

    unsigned int Read_Port(uint8_t port_index,uint8_t pins_mask) //pins_level is the output value//pins_mask is the pins iwant to manipulate
    {

    if(port_index == 0)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTA_CR_R|=pins_mask;
    GPIO_PORTA_AMSEL_R&=~pins_mask;
    GPIO_PORTA_PCTL_R&=~pins_mask;
    GPIO_PORTA_AFSEL_R&=~pins_mask;
    GPIO_PORTA_DEN_R |=pins_mask;
    return GPIO_PORTA_DATA_R&pins_mask;
    }

    else if(port_index == 1)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTB_CR_R|=pins_mask;
    GPIO_PORTB_AMSEL_R&=~pins_mask;
    GPIO_PORTB_PCTL_R&=~pins_mask;
    GPIO_PORTB_AFSEL_R&=~pins_mask;
    GPIO_PORTB_DEN_R |=pins_mask;
    return GPIO_PORTB_DATA_R&pins_mask;
    }


    else if(port_index == 2)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTC_CR_R|=pins_mask;
    GPIO_PORTC_AMSEL_R&=~pins_mask;
    GPIO_PORTC_PCTL_R&=~pins_mask;
    GPIO_PORTC_AFSEL_R&=~pins_mask;
    GPIO_PORTC_DEN_R |=pins_mask;
    return GPIO_PORTC_DATA_R&pins_mask;
    }

    else if(port_index == 3)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTD_CR_R|=pins_mask;
    GPIO_PORTD_AMSEL_R&=~pins_mask;
    GPIO_PORTD_PCTL_R&=~pins_mask;
    GPIO_PORTD_AFSEL_R&=~pins_mask;
    GPIO_PORTD_DEN_R |=pins_mask;
    return GPIO_PORTD_DATA_R&pins_mask;
    }


    else if(port_index == 4)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTE_CR_R|=pins_mask;
    GPIO_PORTE_AMSEL_R&=~pins_mask;
    GPIO_PORTE_PCTL_R&=~pins_mask;
    GPIO_PORTE_AFSEL_R&=~pins_mask;
    GPIO_PORTE_DEN_R |=pins_mask;
    return GPIO_PORTE_DATA_R&pins_mask;
    }

    else if(port_index == 5)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R|=pins_mask;
    GPIO_PORTF_AMSEL_R&=~pins_mask;
    GPIO_PORTF_PCTL_R&=~pins_mask;
    GPIO_PORTF_AFSEL_R&=~pins_mask;
    GPIO_PORTF_DEN_R |=pins_mask;
    return GPIO_PORTF_DATA_R&pins_mask;
    }
    //return 0;
    }
    void Write_Port(uint8_t port_index,uint8_t pins_mask,Dio_levelType pins_level) //pins_level is the output value//pins_mask is the pins iwant to manipulate
    {


    if(port_index == 0)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTA_CR_R|=pins_mask;
    GPIO_PORTA_AMSEL_R&=~pins_mask;
    GPIO_PORTA_PCTL_R&=~pins_mask;
    GPIO_PORTA_AFSEL_R&=~pins_mask;
    GPIO_PORTA_DEN_R |=pins_mask;
    if(pins_level==1)
    GPIO_PORTA_DATA_R|=pins_mask;
    else
    GPIO_PORTA_DATA_R&=~pins_mask;
    }

    else if(port_index == 1)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTB_CR_R|=pins_mask;
    GPIO_PORTB_AMSEL_R&=~pins_mask;
    GPIO_PORTB_PCTL_R&=~pins_mask;
    GPIO_PORTB_AFSEL_R&=~pins_mask;
    GPIO_PORTB_DEN_R |=pins_mask;
    if(pins_level==1)
    GPIO_PORTB_DATA_R|=pins_mask;
    else
    GPIO_PORTB_DATA_R&=~pins_mask;
    }

    else if(port_index == 2)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTC_CR_R|=pins_mask;
    GPIO_PORTC_AMSEL_R&=~pins_mask;
    GPIO_PORTC_PCTL_R&=~pins_mask;
    GPIO_PORTC_AFSEL_R&=~pins_mask;
    GPIO_PORTC_DEN_R |=pins_mask;
    if(pins_level==1)
    GPIO_PORTC_DATA_R|=pins_mask;
    else
    GPIO_PORTC_DATA_R&=~pins_mask;
    }

    else if(port_index == 3)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTD_CR_R|=pins_mask;
    GPIO_PORTD_AMSEL_R&=~pins_mask;
    GPIO_PORTD_PCTL_R&=~pins_mask;
    GPIO_PORTD_AFSEL_R&=~pins_mask;
    GPIO_PORTD_DEN_R |=pins_mask;
    if(pins_level==1)
    GPIO_PORTD_DATA_R|=pins_mask;
    else
    GPIO_PORTD_DATA_R&=~pins_mask;
    }

    else if(port_index == 4)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTE_CR_R|=pins_mask;
    GPIO_PORTE_AMSEL_R&=~pins_mask;
    GPIO_PORTE_PCTL_R&=~pins_mask;
    GPIO_PORTE_AFSEL_R&=~pins_mask;
    GPIO_PORTE_DEN_R |=pins_mask;
    if(pins_level==1)
    GPIO_PORTE_DATA_R|=pins_mask;
    else
    GPIO_PORTE_DATA_R&=~pins_mask;
    }

    else if(port_index == 5)
    {
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R|=pins_mask;
    GPIO_PORTF_AMSEL_R&=~pins_mask;
    GPIO_PORTF_PCTL_R&=~pins_mask;
    GPIO_PORTF_AFSEL_R&=~pins_mask;
    GPIO_PORTF_DEN_R |=pins_mask;
    if(pins_level==1)
    GPIO_PORTF_DATA_R|=pins_mask;
    else
    GPIO_PORTF_DATA_R&=~pins_mask;
    }
    
    }
