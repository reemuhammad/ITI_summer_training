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
int main(void)
{
		u8 button1= 0;
		u8 * Pu8PortValue= (u8 *) 0x100;
		DIO_VidSetPinDirection(Port_A,Pin_0,output); /* set led on pin 0 in PORT A as output */
		DIO_VidSetPinDirection(Port_D,Pin_0,input); /* take input from switch on pin 0 PORT D */
		DIO_VidSetPinValue(Port_A,Pin_0,low);

		DIO_VidSetPortDirection(Port_B,output); /* set PORT B as output */
		DIO_VidSetPortDirection(Port_C,input); /* set PORT B as input */
		DIO_VidSetPortValue(Port_B,0x00);
		while(1)
		{
			DIO_VidGetPinValue(Port_D,Pin_0,&button1); /* if the switch is pressed, blink the led */
			if(button1 == 1)
			{
				DIO_VidSetPinValue(Port_A,Pin_0,high);
				_delay_ms(500);
				DIO_VidSetPinValue(Port_A,Pin_0,low);
				_delay_ms(500);
			}
			else
			{
				DIO_VidSetPinValue(Port_A,Pin_0,low);
			}
			DIO_VidGetPortValue(Port_C,Pu8PortValue);
			if( * Pu8PortValue == 0b00010101) /* if the 3 switches on PORT C are switched turn on 3 leds on PORT B*/
			{
				DIO_VidSetPortValue(Port_B,0b01001001);
			}
			else
			{
				DIO_VidSetPortValue(Port_B,0x00);
			}
		}

	return 0;
}
