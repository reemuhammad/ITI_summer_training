/*
 * main.c
 *
 *  Created on: Sep 8, 2021
 *      Author: DELL
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "DIO/DIO_interface.h"
#include <util/delay.h>

int main()
{
	DIO_VidSetPinDirection(Port_B,Pin_2,output);
	while(1)
	{
		DIO_VidSetPinValue(Port_B,Pin_2,high);
				_delay_ms(1000);
				DIO_VidSetPinValue(Port_B,Pin_2,low);
				_delay_ms(1000);
	}
	return 0;
}
