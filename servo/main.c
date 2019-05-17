#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "PWM.h"



void SystemInit(void){
}





void delay_milli(uint32_t n)
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++)
{}
}

void fade_LED(void)
{
    uint16_t i;
    for(i = 0; i < (5000 - 1); i++)
    {
        PWM_set_dutyCycle(i);
        delay_milli(500);

    }
}
int main()
{
    servoMotor(0);
  //  PortF_PIN(3);
    delay_milli(1000);

    servoMotor(90);

     delay_milli(1000);

     servoMotor(-90);
     delay_milli(1000);



     servoMotor(0);


while (1)
{


   // fade_LED();
   // PWM_set_dutyCycle(4167);


}

}
