#include "DIO.h"

uint8_t DIO_ReadPort(uint8_t port_index, uint8_t pins_mask)
{
    uint8_t pins_level;
    switch (port_index)
    {
    case 0:
        pins_level = GPIO_PORTA_DATA_R & pins_mask;
        break; //port A
    case 1:
        pins_level = GPIO_PORTB_DATA_R & pins_mask;
        break; //port B
    case 2:
        pins_level = GPIO_PORTC_DATA_R & pins_mask;
        break; //port C
    case 3:
        pins_level = GPIO_PORTD_DATA_R & pins_mask;
        break; //port D
    case 4:
        pins_level = GPIO_PORTE_DATA_R & pins_mask;
        break; //port E
    case 5:
        pins_level = GPIO_PORTF_DATA_R & pins_mask;
        break; //port F
    }

    return pins_level;
}

void DIO_WritePort(uint8_t port_index, uint8_t pins_mask, Dio_LevelType pins_level)
{
    if (pins_level == STD_LOW)
    {
        switch (port_index)
        {
        case 0:
            GPIO_PORTA_DATA_R = GPIO_PORTA_DATA_R & ~pins_mask;
            break; //port A
        case 1:
            GPIO_PORTB_DATA_R = GPIO_PORTB_DATA_R & ~pins_mask;
            break; //port B
        case 2:
            GPIO_PORTC_DATA_R = GPIO_PORTC_DATA_R & ~pins_mask;
            break; //port C
        case 3:
            GPIO_PORTD_DATA_R = GPIO_PORTD_DATA_R & ~pins_mask;
            break; //port D
        case 4:
            GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R & ~pins_mask;
            break; //port E
        case 5:
            GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R & ~pins_mask;
            break; //port F
        }
    }
    else if (pins_level == STD_HIGH)
    {
        switch (port_index)
        {
        case 0:
            GPIO_PORTA_DATA_R = GPIO_PORTA_DATA_R | pins_mask;
            break; //port A
        case 1:
            GPIO_PORTB_DATA_R = GPIO_PORTB_DATA_R | pins_mask;
            break; //port B
        case 2:
            GPIO_PORTC_DATA_R = GPIO_PORTC_DATA_R | pins_mask;
            break; //port C
        case 3:
            GPIO_PORTD_DATA_R = GPIO_PORTD_DATA_R | pins_mask;
            break; //port D
        case 4:
            GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R | pins_mask;
            break; //port E
        case 5:
            GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R | pins_mask;
            break; //port F
        }
    }
}

void DIO_FlipPort(uint8_t port_index, uint8_t pins_mask)
{
    switch (port_index)
    {
    case 0:
        GPIO_PORTA_DATA_R = GPIO_PORTA_DATA_R ^ pins_mask;
        break; //port A
    case 1:
        GPIO_PORTB_DATA_R = GPIO_PORTB_DATA_R ^ pins_mask;
        break; //port B
    case 2:
        GPIO_PORTC_DATA_R = GPIO_PORTC_DATA_R ^ pins_mask;
        break; //port C
    case 3:
        GPIO_PORTD_DATA_R = GPIO_PORTD_DATA_R ^ pins_mask;
        break; //port D
    case 4:
        GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R ^ pins_mask;
        break; //port E
    case 5:
        GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ pins_mask;
        break; //port F
    }
}
