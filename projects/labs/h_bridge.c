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
void motor_forward(u8 Copy_u8Port,u8 Copy_u8Direction, u8 Copy_u8OtherDirection);
void motor_backward(u8 Copy_u8Port, u8 Copy_u8Direction, u8 Copy_u8OtherDirection);

/* A code that turn the motor in the forward direction for two seconds
  and then in the opposite direction for another two seconds using H-bridge */
int main(void)
{

		DIO_VidSetPinDirection(Port_A,Pin_0,output); /* set pin 0 in PORT A as output */
		DIO_VidSetPinDirection(Port_A,Pin_1,output); /* set pin 1 in PORT A as output */
		/* turn the motor off at first*/
		DIO_VidSetPinValue(Port_A,Pin_0,low);
		DIO_VidSetPinValue(Port_A,Pin_1,low);

		while(1)
		{
			motor_forward(Port_A,Pin_0,Pin_1);
			_delay_ms(2000);
			motor_backward(Port_A,Pin_1,Pin_0);
			_delay_ms(2000);
		}
	return 0;
}

/* functions that turn off the other direction and turn on the desired one */
void motor_forward(u8 Copy_u8Port,u8 Copy_u8Direction, u8 Copy_u8OtherDirection)
{
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8OtherDirection,low);
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8Direction,high);
}
void motor_backward(u8 Copy_u8Port,u8 Copy_u8Direction, u8 Copy_u8OtherDirection)
{
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8OtherDirection,low);
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8Direction,high);
}
