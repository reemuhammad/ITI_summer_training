/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: REEM
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "util/delay.h"

int main()
{
	/* setting up LEDS pins */
	DIO_VidSetPinDirection(Port_B,Pin_0,output);
	DIO_VidSetPinDirection(Port_B,Pin_1,output);
	DIO_VidSetPinDirection(Port_B,Pin_2,output);

	/* set the potentiometer as input */
	DIO_VidSetPinDirection(Port_A,Pin_0,input);
	/* initialize ADC */
	ADC_vid_Init();
	s32 local_u8ReadADC;

	while(1)
	{
		local_u8ReadADC=ADC_u8ReadChannel(ADC_0); /* read the volt value */
		if(local_u8ReadADC < 1.5)
		{
			DIO_VidSetPinValue(Port_B,Pin_0,high); /* turn on red led */
			DIO_VidSetPinValue(Port_B,Pin_1,low);
			DIO_VidSetPinValue(Port_B,Pin_2,low);
		}
		else if(local_u8ReadADC < 3)
		{
			DIO_VidSetPinValue(Port_B,Pin_1,high); /* turn on yellow led */
			DIO_VidSetPinValue(Port_B,Pin_0,low);
			DIO_VidSetPinValue(Port_B,Pin_2,low);
		}
		else
		{
			DIO_VidSetPinValue(Port_B,Pin_2,high); /* turn on green led */
			DIO_VidSetPinValue(Port_B,Pin_1,low);
			DIO_VidSetPinValue(Port_B,Pin_0,low);
		}
	}
	return 0;
}


