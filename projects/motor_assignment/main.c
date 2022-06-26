/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: DELL
 */

#include"lib/STD_TYPES.H"
#include"lib/BIT_MATH.H"
#include "CLCD_config.h"
#include"DIO_interface.h"
#include "CLCD_INTERFACE.h"
#include<util/delay.h>

void motor_right(u8 Copy_u8Port,u8 Copy_u8Direction, u8 Copy_u8OtherDirection);
void motor_left(u8 Copy_u8Port, u8 Copy_u8Direction, u8 Copy_u8OtherDirection);

int main(void)
{
	/* Setting up the LCD pins */
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RS_PIN,output);
			DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RW_PIN,output);
			DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_E_PIN,output);
			DIO_VidSetPortDirection(CLCD_DATA_PORT,output);
	/* LCD INITIALIZATION */
		CLCD_VidInit();
	/* Setting up the switches and the motor pins */
		DIO_VidSetPinDirection(Port_B,Pin_0,input); /* set pin 0 in PORT B as input */
		DIO_VidSetPinDirection(Port_B,Pin_1,input); /* set pin 1 in PORT B as input */
		DIO_VidSetPinDirection(Port_A,Pin_0,output); /* set pin 0 in PORT A as output */
		DIO_VidSetPinDirection(Port_A,Pin_1,output); /* set pin 1 in PORT A as output */
	/* Set internal pull up transistor on the button , connect the button to ground */
		DIO_VidSetPinValue(Port_B,Pin_0,high);
		DIO_VidSetPinValue(Port_B,Pin_1,high);
	/* turn the motor off at first*/
		DIO_VidSetPinValue(Port_A,Pin_0,low);
		DIO_VidSetPinValue(Port_A,Pin_1,low);

		u8 local_u8arr1[]="right";
		u8 local_u8arr2[]="left";
		u8 local_u8arr3[]="wrong !!";

	while(1)
	{
		u8 local_u8button1=0;
		u8 local_u8button2=0;
		DIO_VidGetPinValue(Port_B,Pin_0,&local_u8button1); /* read value of switch 1 */
		DIO_VidGetPinValue(Port_B,Pin_1,&local_u8button2); /* read value of switch 2 */
		if((local_u8button1 == low) && (local_u8button2 == high)) /* switch 1 is pressed and switch 2 is not */
		{
			/* clear LCD display */
			CLCD_VidSendCommand(1);
			motor_right(Port_A,Pin_0,Pin_1); /* motor turns right */
			CLCD_VidWriteString(local_u8arr1); /* print "right" on LCD */
		}
		if((local_u8button2 == low) && (local_u8button1 == high)) /* switch 2 is pressed and switch 1 is not */
		{
			/* clear LCD display */
			CLCD_VidSendCommand(1);
			motor_left(Port_A,Pin_1,Pin_0); /* motor turns left */
			CLCD_VidWriteString(local_u8arr2); /* print "left" on LCD */
		}
		if((local_u8button2 == low) && (local_u8button1 == low)) /* both of the switches are pressed */
		{
			/* clear LCD display */
			CLCD_VidSendCommand(1);
			/* turn both motors off */
			DIO_VidSetPinValue(Port_A,Pin_0,low);
			DIO_VidSetPinValue(Port_A,Pin_1,low);
			CLCD_VidWriteString(local_u8arr3); /* print "wrong !!" on LCD */
		}

	}
}

/* functions that turn off the other direction and turn on the desired one */
void motor_right(u8 Copy_u8Port,u8 Copy_u8Direction, u8 Copy_u8OtherDirection)
{
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8OtherDirection,low);
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8Direction,high);
}
void motor_left(u8 Copy_u8Port,u8 Copy_u8Direction, u8 Copy_u8OtherDirection)
{
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8OtherDirection,low);
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8Direction,high);
}
