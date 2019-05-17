#include "PWM.h"

void servoMotor(int8_t ang){
	
	//init
	uint8_t val;
	
	Enable_PWM_clk();
	PWM_PORT_config();
	PWM_Init();
	PWM_set_dutyCycle(uint32_t dutyCycle);
	
		if (ang <= 90 || ang >= -90){
			val = 1 + ((ang * 0.5)/90);			// angle [-90:90] to duty cycle [0:1]
		}
		else {
			val = 0.5;
		}
	
	val = 1 + ((ang * 0.5)/90);	    // angle [-90:90] to duty cycle [0:1]
	
  PWM_set_dutyCycle(val);
	
}
