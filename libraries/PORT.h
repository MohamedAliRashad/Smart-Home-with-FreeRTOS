#ifndef PORT_H /* Include guard */
#define PORT_H

// include Registers Header
#include "tm4c123gh6pm.h"
#include <stdint.h>

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

#define SET_BIT(p, n) ((p) |= (1 << (n)))
#define CLEAR_BIT(p, n) ((p) &= ~((1) << (n)))

typedef enum
{
    PORT_PIN_IN = 0,
    PORT_PIN_OUT = 1
} Port_PinDirectionType;

/*
Enum is used to assign names to integer values

Example: 
    
    enum State {Working = 1, Failed = 0};
    State Cairo = Working;
    cout << Cairo;

    Output: 1 

In our case we will be using Enum to assign PORT_PIN_IN to 0 value 
And PORT_PIN_OUT to 1, So we can use the the names instead of the values.
*/

void Port_Init(uint8_t port_index);

/*
Description: Initialize port based on selected port_index (0 to 5) by:
    1- Enabling the clock
    2- Unlocking the port
    3- Making the selected mode digital

Parameters:
    port_index for choosing the required Port.

Return:
    Nothing
*/

void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, Port_PinDirectionType pins_direction);

/*
Description: Change the direction of the selected pins (INPUT or OUTPUT).

Parameters:
    1- port_index for selecting which port we will work with.
    2- pins_mask for selecting the pins we want to configure.
    3- pins_direction to configure them INPUT or OUTPUT.

Return:
    Nothing
*/

void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask, uint8_t enable);

/*
Description: Make the Pins chosen pulled up internally with resistance.

Parameters:

    1- port_index for selecting which port we will work with
    2- pins_mask for selecting the pins we want to configure
    example: (0b00001111) means the first 4 pins will be pulled up if the enable pin set to 1
    3- enable: 1 => Connect the selected pins to internal pull-up resistors 
               0 => Not Connected

Return:
    Nothing
*/

void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask, uint8_t enable);

/*
Description: Make the Pins chosen pulled down internally with resistance.

Parameters:

    1- port_index for selecting which port we will work with
    2- pins_mask for selecting the pins we want to configure
    example: (0b00001111) means the first 4 pins was chosen to work with
    3- enable: 1 => Connect the selected pins to internal pull-down resistors 
               0 => Not Connected

Return:
    Nothing
*/

#endif /* PORT_H */
