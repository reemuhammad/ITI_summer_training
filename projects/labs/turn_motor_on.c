/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: REEM MUHAMMAD
 */
#include"lib/STD_TYPES.H"
#include"lib/BIT_MATH.H"
#include"DIO_interface.h"
#include<util/delay.h>


/* A code that turn on the motor when a switch is pressed
 * and turn it off when the switch is released  */
int main(void)
{
	DIO_VidSetPinDirection(Port_B,Pin_0,input); /* set pin 0 in PORT B as input */
	DIO_VidSetPinDirection(Port_B,Pin_1,output); /* set pin 1 in PORT B as output */

	DIO_VidSetPinValue(Port_B,Pin_1,low); /* turn off motor at first */
	/* Set internal pull up transistor on the button , connect the button to ground */
	DIO_VidSetPinValue(Port_B,Pin_0,high);

		while(1)
		{
			u8 button=0;
			DIO_VidGetPinValue(Port_B,Pin_0,&button);
			if(button == high) /* not pressed */
			{
				DIO_VidSetPinValue(Port_B,Pin_1,low); /* turn off motor */
			}
			else if(button == low) /* pressed */
			{
				DIO_VidSetPinValue(Port_B,Pin_1,high); /* turn on motor */
			}
		}
	return 0;
}
