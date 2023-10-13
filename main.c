
/*
 * main.c
 *
 *  Created on: Oct 11, 2023
 *      Author: ABD ALLAH

 */

#include "ADC.h"
#include "PWM_TIMER0.h"
#include "lm35_sensor.h"
#include "lcd.h"
#include "DC_MOTOR.h"


volatile uint8 temperature;

int main(void){



	ADC_ConfigType configuration={INTERNAL,PRESCALER_8};
	ADC_init(&configuration);

	LCD_init();
	DcMotor_Init();

	LCD_displayStringRowColumn(1,3,"Temp=   C");

	while(1){

		temperature=LM35_getTemperature();
		if(temperature<30){
			DcMotor_Rotate(STOP,0);
			LCD_displayStringRowColumn(0,1,"FAN IS OFF      ");
            LCD_moveCursor(1,8);
            LCD_intgerToString(temperature);
            LCD_displayCharacter(' ');
		}
		 if (temperature>=30 && temperature<60){
			DcMotor_Rotate(CW,25);
			LCD_displayStringRowColumn(0,1,"FAN IS ON (25%)");
			LCD_moveCursor(1,8);
            LCD_intgerToString(temperature);
            LCD_displayCharacter(' ');
		}
		 if (temperature>=60 && temperature<90){
			DcMotor_Rotate(CW,50);
			LCD_displayStringRowColumn(0,1,"FAN IS ON (50%)");
			LCD_moveCursor(1,8);
            LCD_intgerToString(temperature);
            LCD_displayCharacter(' ');

		}
		 if (temperature>=90 && temperature<120){
			DcMotor_Rotate(CW,75);
			LCD_displayStringRowColumn(0,1,"FAN IS ON (75%)");
			LCD_moveCursor(1,8);
            LCD_intgerToString(temperature);
           if(temperature<100){ LCD_displayCharacter(' ');}
		}
		 if (temperature>=120){
			DcMotor_Rotate(CW,100);
			LCD_displayStringRowColumn(0,1,"FAN IS ON (100%)");
			LCD_moveCursor(1,8);
            LCD_intgerToString(temperature);
		}
	}



}

