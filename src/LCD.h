#ifndef LCD_H /* Include guard */
#define LCD_H

#include <stdint.h>
#include "../libraries/tm4c123gh6pm.h"
#include "../libraries/PORT.h"

/*LCD DRIVERS*/
void LCD_init();

void LCD_command(char com);

void LCD_data(char data);

#endif /* LCD_H */
