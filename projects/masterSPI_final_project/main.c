/*
 * main.c
 *
 *  Created on: Sep 9, 2021
 *      Author: DELL
 */


#include "lib/BIT_MATH.h"
#include "lib/STD_TYPES.h"
#include "DIO/DIO_interface.h"
#include "SPI/SPI_interface.h"
#include "util/delay.h"
#include "GIE_interface.h"

u8 noUse=0;
u8 data=0;
void fun()
{
	data= SPI_u8_TransmitReceive(1);
}

int main()
{
	GIE_Vid_Enable();
		DIO_VidSetPinDirection(Port_B,Pin_4,output);  	/* Slave Select setup */
		DIO_VidSetPinDirection(Port_B,Pin_5,output);	/* MOSI */
		DIO_VidSetPinDirection(Port_B,Pin_6,input);		/* MISO */
		DIO_VidSetPinDirection(Port_B,Pin_7,output);	/* SCK */
		DIO_VidSetPinValue(Port_B,Pin_4,low);			/* Slave Select */

	//SPI_INT_Call_Back(fun,&noUse);
	DIO_VidSetPinDirection(Port_A,Pin_0,output);
	SPI_Void_Init_Master();
	while(1)
	{
		data= SPI_u8_TransmitReceive('F');

		if (data == 'A')
		{
			DIO_VidSetPinValue(Port_A,Pin_0,high);
		}
		else
		{
			DIO_VidSetPinValue(Port_A,Pin_0,low);
		}
		_delay_ms(500);
	}
	return 0;
}
