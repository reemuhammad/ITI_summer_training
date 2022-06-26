/*
 * main.c
 *
 *  Created on: Sep 2, 2021
 *      Author: DELL
 */

#include "lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "I2C_interface.h"
#include "EEPROM_interface.h"
#include "util/delay.h"


/* This code uses the I2C protocol "TWI in ATmega" to access External EEPROM */

int main()
{
	DIO_VidSetPinDirection(Port_A,Pin_0,output);  	/* set direction for a test pin as output */
	DIO_VidSetPortDirection(Port_B,output);		 	/* set direction for a test port as output */
	TWI_voidInitMaster(0); 							/* Initialize TWI protocol where the MC is the master*/
	u8 read=0; 										/* variable to read a byte value in the EEPROM */
	u8 read_block[8]={0};							/* variable to read values in a block  in the EEPROM */
	while(1)
	{
		/* Write 0x01 in address byte 0x00, and set the address of the EEPROM s 0x51 */
		EEPROM_write(0x51,0x00,0x01);
		_delay_ms(1000);
		/* Read the value in address byte 0x00 */
		EEPROM_read(0x51,0x00,&read);
		/* print the value we read on Pin 0 in PORT A */
		DIO_VidSetPinValue(Port_A,Pin_0,read);
		/* Write value 0x01 in successive 10 bytes starting from address 0x24 */
		EEPROM_writeBlock(0x51,10,0x24,0x01);
		_delay_ms(1000);
		/* Write the value in successive 6 bytes starting from address 0x24 */
		EEPROM_readBlock(0x51,6,0x24,read_block);
		/* Test the read values by writing them on PORT B --->>>expected to write HIGH "1" on 6 pins only */
		for(u8 i=0; i<8;i++)
		{DIO_VidSetPinValue(Port_B,i,read_block[i]);}
	}
	return 0;
}



