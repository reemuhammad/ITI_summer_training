/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: DELL
 */
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "GIE_interface.h"
#include "util/delay.h"

/* Communication using SPI */
/* This is the master code:
 * The master MC sends '0' and waits for a time, then '1' and waits again
 * Green led connected on the master MC toggles every time on completing the transmission using the SPI interrupt
 * In the slave code : it will wait for the received data and turn on a LED on receiving '0' and turn it off on receiving '1'*/

void SPI_INT_ISR()
{
	static u8 toggle=low;
	if(toggle == low)
	{
		toggle=high;
	}
	else if(toggle == high)
	{
		toggle=low;
	}
	DIO_VidSetPinValue(Port_A,Pin_4,toggle);
}

u8 button_read=0; 		/*Global variable for saving the received value after transmission*/

int main()
{
	GIE_Vid_Enable();
	DIO_VidSetPinDirection(Port_B,Pin_4,output);  	/* Slave Select setup */
	DIO_VidSetPinDirection(Port_B,Pin_5,output);	/* MOSI */
	DIO_VidSetPinDirection(Port_B,Pin_6,input);		/* MISO */
	DIO_VidSetPinDirection(Port_B,Pin_7,output);	/* SCK */

	DIO_VidSetPinDirection(Port_A,Pin_4,output);
	SPI_INT_Call_Back(SPI_INT_ISR,&button_read);

	SPI_Void_Init_Master(); 						/* initialize SPI as master */
	DIO_VidSetPinValue(Port_B,Pin_4,low);			/* Slave Select */

	while(1)
	{
		SPI_void_Transmit('0');
		_delay_ms(800);
		SPI_void_Transmit('1');
		_delay_ms(800);
	}
	return 0;
}
