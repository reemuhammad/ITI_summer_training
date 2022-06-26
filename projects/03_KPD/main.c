/*
 * main.c
 *
 *  Created on: Aug 18, 2021
 *      Author: DELL
 */

#include "lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_INTERFACE.h"
#include "CLCD_config.h"
#include <util/delay.h>
#include "KPD_config.h"
#include "KPD_interface.h"
/* The following libraries are for using malloc and snprintf functions to convert int to string*/
#include <stdlib.h>
#include <stdio.h>


/* ----------THIS CODE IS A CALCULATOR PROGRAM FOR TWO 1-DIGIT NUMBERS---------- */
int main ()
{
	/* Setting up the pins for LCD */
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_E_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT,output);
	/* LCD INITIALIZATION */
	CLCD_VidInit();

	/* setting up keypad port : 4 pins are output and 4 pins are input */
	DIO_VidSetPortDirection(KPD_u8PORT,0b00001111);
	/* Necessary action: activating internal pull up resistors by writing high on them */
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW0_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW1_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW2_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW3_PIN,high);

	while(1)
	{
		u8 Local_u8KPDResult = NOT_PRESSED, Local_u8operation_line =0;
		u8 Local_u8FirstOperand=0, Local_u8SecondOperand=0, Local_u8Operation=0 ;

		/* accept entries until '=' is pressed */
		while ( Local_u8KPDResult != '=')
		{
			Local_u8KPDResult = KPD_u8GetPresssedKey();

			/* IF A KEY IS PRESSED: SAVE ITS VALUE IN THE CORRECT POSITION OF OPERATION LINE
	 	 	 AS: 0)FIRST OPERAND , 1)OPERATION SIGN , 2)SECOND OPERAND  */
			if(Local_u8KPDResult != NOT_PRESSED)
			{
				switch(Local_u8operation_line)
				{
				case 0:
					Local_u8FirstOperand = Local_u8KPDResult - '0';  /* Converting character to number */
					/* Clear LCD display at the start */
					CLCD_VidSendCommand(1);
					break;
				case 1:
					Local_u8Operation = Local_u8KPDResult ;
					break;
				case 2:
					Local_u8SecondOperand = Local_u8KPDResult - '0'; /* Converting character to number */
					break;
				}
				CLCD_VidSendData(Local_u8KPDResult); /* printing the pressed key on LCD */
				Local_u8operation_line++; /* move to the next postion in operation line */
			}
		}

		/* PROCESSING THE MATHEMATICAL OPERATION */
		switch (Local_u8Operation)
		{
		case '+':
			Local_u8Operation = Local_u8FirstOperand + Local_u8SecondOperand;
			break;
		case '-':
			Local_u8Operation = Local_u8FirstOperand - Local_u8SecondOperand;
			break;
		case '*':
			Local_u8Operation = Local_u8FirstOperand * Local_u8SecondOperand;
			break;
		case '/':
			Local_u8Operation = Local_u8FirstOperand / Local_u8SecondOperand;
			break;
		}
		/* CONVERTING THE RESULT NUMBER TO STRING TO DISPLAY IT ON LCD */
		u32 Local_u832Resultlength = snprintf( '\0' , 0, "%d", Local_u8Operation ); /* KNOWING THE LENGTH OF THE STRING */
		u8* Local_u8ResultString = malloc( Local_u832Resultlength + 1 ); /* DYNAMIC MEMORY ALLOCATION FOR STRING SIZE */
		snprintf( Local_u8ResultString, Local_u832Resultlength + 1, "%d", Local_u8Operation ); /* CONVERTING NUMBER TO STRING */

		CLCD_VidWriteString(Local_u8ResultString); /* PRINTING THE RESULT STRING */
		free(Local_u8ResultString); /* FREE THE MEMORY SPACE FOR FURTHER SEVERAL OPERATIONS */
		Local_u8KPDResult = NOT_PRESSED; /* GET READY FOR ANOTHER OPERATION */
	}
	return 0;
}



