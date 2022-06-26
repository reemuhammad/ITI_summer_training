/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: DELL
 */
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "util/delay.h"

/* Communication using SPI */
/* This is the slave code:
 * The master MC sends '0' and waits for a time, then '1' and waits again
 * In the slave code : it will wait for the received data and turn on a LED on receiving '0' and turn it off on receiving '1'*/

int main()
{
	DIO_VidSetPinDirection(Port_B,Pin_4,input);  		/* Slave Select setup */
	DIO_VidSetPinDirection(Port_B,Pin_5,input);			/* MOSI */
	DIO_VidSetPinDirection(Port_B,Pin_6,output);		/* MISO */
	DIO_VidSetPinDirection(Port_B,Pin_7,input);			/* SCK */

	DIO_VidSetPinDirection(Port_C,Pin_0,output);

	SPI_Void_Init_Slave(); 						/* initialize SPI as slave */
	u8 button_read=0; /* to save the received data */
	while(1)
	{
		button_read = SPI_u8_TransmitReceive(0xff);
		if(button_read == '0')
		{
			DIO_VidSetPinValue(Port_C,Pin_0,high);
		}
		else if(button_read == '1')
		{
			DIO_VidSetPinValue(Port_C,Pin_0,low);
		}
	}
	return 0;
}
