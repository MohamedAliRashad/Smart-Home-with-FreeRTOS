#ifndef DIO_H /* Include guard */
#define DIO_H

// include Registers Header
#include "tm4c123gh6pm.h"
#include <stdint.h>

typedef enum Dio_LevelType
{
    STD_LOW = 0,
    STD_HIGH = 1
} Dio_LevelType;

/*
Enum is used to assign names to integer values

Example: 
    
    enum State {Working = 1, Failed = 0};
    State Cairo = Working;
    cout << Cairo;

    Output: 1 

In our case we will be using Enum to assign STD_LOW to 0 value 
And STD_HIGH to 1, So we can use the the names instead of the values.
*/

uint8_t DIO_ReadPort(uint8_t port_index, uint8_t pins_mask);

/*
Description: Return the value chosen by the port_index.

Paramaters:

    1- port_index for choosing the port.
    2- pins_mask for choosing the pins that wants it's value.

Return:
    pins_level{
        STD_LOW 0
        STD_HIGH 1
    }
*/

void DIO_WritePort(uint8_t port_index, uint8_t pins_mask, Dio_LevelType pins_level);

/*
Description: Change the value of the selected pins through make them STD_HIGH 1 or STD_LOW 0 

Paramaters:
    
    1- port_index for choosing the port.
    2- pins_mask for choosing the pins that needs to be changed.

Return:
    Nothing
*/

void DIO_FlipPort(uint8_t port_index, uint8_t pins_mask);

/*
Description: Toggle the values of the pins selected.

Paramaters:
    1- port_index for choosing the port.
    2- pins_mask for choosing the pins that will be toggled.

Return:
    Nothing    

*/

#endif /* DIO_H */
