# FAN_CONTROLLER_SYSTEM-ATMEGA32

Project Description:
the project is implemented via AVR atmega32 MCU with 1 MHz internal clock frequency.

The fan is automatically turned OFF or ON with variable speed according to the temperature.
Based on the temperature read from the LM35 sensor, the MCU sets the fan speed as follows:

- If the temperature is less than 30C, the fan is turned off.
- If the temperature is greater than or equal 30C, the fan is turned on with 25% of its maximum speed.
- If the temperature is greater than or equal 60C, the fan is turned on with 50% of its maximum speed.
- If the temperature is greater than or equal 90C, the fan is turned on with 75% of its maximum speed.
- If the temperature is greater than or equal 120C, the fan is turned on with 100% of its maximum speed.
  
The fan status is continuously updated on an LCD screen with 8 bit mode.
The DC_MOTOR acts as the fan.
The speed changes by changing the duty cycle of the PWM of Timer0.

Designed based on the layered architecture model as follows:
1. Application layer
2. HAL: LCD, LM35 Temperature Sensor, DC-Motor.
3. MCAL: GPIO , ADC , PWM.
   
![OFF](https://github.com/AbdallahAhmed7/FAN_CONTROLLER_SYSTEM-ATMEGA32/assets/142527303/685e5a81-201d-457f-93f3-69b6be9e016f)

![1](https://github.com/AbdallahAhmed7/FAN_CONTROLLER_SYSTEM-ATMEGA32/assets/142527303/88e93773-fa51-446c-8f52-3fdad68ce7bf)

![2](https://github.com/AbdallahAhmed7/FAN_CONTROLLER_SYSTEM-ATMEGA32/assets/142527303/cbccd5c0-e684-4a9d-96cc-69ef667ade8a)
