/*
 * main.c
 *
 *  Created on: Aug 31, 2021
 *      Author: DELL
 */
#include "lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "I2C_interface.h"
#include "util/delay.h"




int main()
{
	DIO_VidSetPinDirection(Port_A,Pin_0,output);
	DIO_VidSetPortDirection(Port_B,output);
	TWI_voidInitMaster(0);
	u8 read=0;
	u8 read_port[8]={0};
	while(1)
	{
		EEPROM_write(0x51,0x00,0x01);
		_delay_ms(1000);
		EEPROM_read(0x51,0x00,&read);
		/* print the value we read on PORT A */
		DIO_VidSetPinValue(Port_A,Pin_0,read);
		EEPROM_writeBlock(0x51,10,0x24,0x01);
		_delay_ms(1000);
		EEPROM_readBlock(0x51,6,0x24,read_port);
		for(u8 i=0; i<8;i++)
		{DIO_VidSetPinValue(Port_B,i,read_port[i]);}
	}
	return 0;
}


