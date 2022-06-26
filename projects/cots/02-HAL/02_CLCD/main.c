/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: DELL
 */

#include "lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_INTERFACE.h"
#include "CLCD_config.h"
#include <util/delay.h>

int main ()
{
	/* Setting up the pins */
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_E_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT,output);
	/* LCD INITIALIZATION */
	CLCD_VidInit();

	u8 local_u8ArrToArabicNameLetter_1[8]=  /* BYTES TO DRAW FIRST ARABIC LETTER IN MY NAME */
	{
			  0x00,
			  0x00,
			  0x01,
			  0x01,
			  0x03,
			  0x06,
			  0x0C,
			  0x18
	};
	u8 local_u8ArrToArabicNameLetter_2[8]=  /* BYTES TO DRAW SECOND ARABIC LETTER IN MY NAME */
	{
			  0x00,
			  0x00,
			  0x01,
			  0x01,
			  0x1F,
			  0x00,
			  0x0E,
			  0x00
	};
	u8 local_u8ArrToArabicNameLetter_3[8]=  /* BYTES TO DRAW THIRD ARABIC LETTER IN MY NAME */
	{
			  0x00,
			  0x00,
			  0x07,
			  0x05,
			  0x1F,
			  0x10,
			  0x10,
			  0x10
	};

	/* Save every special character in a unique location to avoid overwriting */
	/* Print the name from right to left */

	CLCD_VidWriteSpecialCharacter( local_u8ArrToArabicNameLetter_1, 0, 0, 13);

	CLCD_VidWriteSpecialCharacter( local_u8ArrToArabicNameLetter_2, 1, 0, 12);

	CLCD_VidWriteSpecialCharacter( local_u8ArrToArabicNameLetter_3, 2, 0, 11);


	while(1)
	{

	}
	return 0;
}

