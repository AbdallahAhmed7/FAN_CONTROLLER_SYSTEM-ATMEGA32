


#include  "ADC.h"
#include "avr/io.h"
#include "common_macros.h"

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
//choose reference volt at the bit6 and bit7  in ADMUX
	ADMUX = 0;
	ADMUX= (ADMUX & 0x3F) | ( (Config_Ptr->ref_volt) <<6 );
    ADCSRA &=~(1<<ADIE); //DISABLE INT
    ADCSRA= (ADCSRA & 0xF8) | (Config_Ptr->prescaler); // choose Prescaler
    ADCSRA|=(1<<ADEN);   // ENABLE ADC

}


uint16 ADC_readChannel(uint8 channel_num)
{
	 channel_num &= 0x07;
	 ADMUX= (ADMUX & 0xE0) | (channel_num); //set channel
	 SET_BIT(ADCSRA,ADSC); //start conversion

	 while (BIT_IS_CLEAR(ADCSRA,ADIF)); //POLLING UNTIL FLAG=1

	 SET_BIT(ADCSRA,ADIF);//CLEAR FLAG

	 return ADC; //RETURN DATA

}


