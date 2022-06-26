/*
 * main.c
 *
 *  Created on: Aug 29, 2021
 *      Author: DELL
 */

#include "lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "Timer_private.h"
#include "Timer_interface.h"
#include "ADC_interface.h"
#include "util/delay.h"
#include "Timer_config.h"
#include "GIE_interface.h"

/* controlling a servo using a potentiometer */

int main(){

	u16 ADC_value=0;
	u16 OCR_value=0; /*variable for the value written in On Compare Register */

	/* connect the potentiometer to channel 5*/
	DIO_VidSetPinDirection(Port_A,ADC_5,input); /* set the channel pin as input */

	ADC_vid_Init(); /* initialize ADC as configured in ADC_config.h file */

	DIO_VidSetPinDirection(Port_D,Pin_5,output); /* set 0C1A pin as output and connect the servo to it */

	Timer1_16bit_vid_Init(Fast_PWM_ICR_Top,UnitA_Clear_OC0_on_compare_match);  /* initialize timer 1 in Non-inverting mode */

	Timer_vid_Write_u16reg(ICR,20000);  /* set the period of servo */


	while(1)
	{
		ADC_value = ADC_u8ReadChannel(ADC_5); /* get the digital value o the signal */
		OCR_value = Map_u16Function(ADC_value,0,1023,1000,2000); /* get the corresponding OCR value for the input signal */
		Timer_vid_Write_u16reg(UnitA_OCR,OCR_value); /* set the duty cycle */
		_delay_ms(1000);
	}
	return 0;
}

