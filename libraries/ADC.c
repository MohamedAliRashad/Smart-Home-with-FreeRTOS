#include "ADC.h"

/*
void ADC0_channelConfig(uint8_t channel_num)
    {
		// implementation to be added here
   
    }

*/
void ADC0_init (uint8_t channel_num, triggerType trig_type)
{

    SYSCTL_RCGCADC_R |=(1 << 0);  /* enable clock to ADC0 */

    //ADC0_channelConfig(channel_num);
   
    ADC0_ACTSS_R &=~ (1 << 3);      // Disable Sample Sequencer 3 
    ADC0_EMUX_R &= ~0XF000;      //Software trigger conversionv: Set zeros in the bits from 12:15

    #if (trig_type == TIMER_TRIGGER)
        ADC0_EMUX_R |= 0x5000;       /* timer trigger conversion seq 0 */
    #endif

        ADC0_SSMUX3_R = channel_num;         /* Channel Num */
        ADC0_SSCTL3_R |= 0x06;      //one sample at a time --> if we are not reading from the interna temp. sensor. // to be remembered
        ADC0_ACTSS_R |= (1 << 3);     //enable SampleSequencer3


    #if (trig_type == TIMER_TRIGGER)

        SYSCTL_RCGCWTIMER_R |= 1;    /* enable clock to WTimer Block 0 */

        /* initialize wtimer 0 to trigger ADC at 1 sample/sec */
        WTIMER0_CTL_R = 0;           /* disable WTimer before initialization */
        WTIMER0_CFG_R = 0x04;        /* 32-bit option */
        WTIMER0_TAMR_R = 0x02;       /* periodic mode and down-counter */
        WTIMER0_TAILR_R = 16000000;  /* WTimer A interval load value reg (1 s) */
        WTIMER0_CTL_R |= 0x20;       /* timer triggers ADC */
        WTIMER0_CTL_R |= 0x01;       /* enable WTimer A after initialization */

    #endif        
        
    }
/*
void ADC0_start_conversion()
{
 /* implementation to be added here */
}
*/



float ADC0_digital_toVoltage(uint16_t digital_value){
    return ((3.3*digital_value)/4096);     
}



    
	
