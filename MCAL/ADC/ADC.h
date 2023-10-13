
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"


#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum{

	AREF,VCC,RESERVED,INTERNAL

}ADC_ReferenceVolatge;

typedef enum{

	PRESCALER2,PRESCALER_2,PRESCALER_4,PRESCALER_8,PRESCALER_16,PRESCALER_32,PRESCALER_64,PRESCALER_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */

