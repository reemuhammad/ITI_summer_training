/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: REEM
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "util/delay.h"
#include "CLCD_config.h"
#include "CLCD_INTERFACE.h"
#include "GIE_interface.h"
/* The following libraries are for using malloc and snprintf functions to convert int to string*/
#include <stdlib.h>
#include <stdio.h>
#include "ADC_private.h"
void task()   /* ADC interrupt ISR */
{
	static u8 state=1;
	DIO_VidSetPinValue(Port_B,Pin_0,state);
	state = !state;
}
int main()
{
	GIE_Vid_Enable(); /* activate the SREG pin , Config: ADC_Interrupt_Enable*/
	ADC_INT_Call_Back(task);
	DIO_VidSetPinDirection(Port_B,Pin_0,output);
	/* Setting up LCD pins  */
	DIO_VidSetPortDirection(CLCD_DATA_PORT,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,Pin_0,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,Pin_1,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,Pin_2,output);
	/* initialize LCD */
	CLCD_VidInit();
	/* set the potentiometer as input */
	DIO_VidSetPinDirection(Port_A,Pin_0,input);
	/* initialize ADC */
	ADC_vid_Init();
	s32 local_u8ReadADC;
	u8 print_arr[]="V = ";
	while(1)
	{
		//ADC_VidAsynch_ReadChannel(0);
		CLCD_VidWriteString(print_arr); /*  print "V = "  */
		local_u8ReadADC=ADC_u8ReadChannel(ADC_0);
	    /* CONVERTING THE VOLT VALUE TO STRING TO DISPLAY IT ON LCD */
	    u32 Local_u832Resultlength = snprintf( '\0' , 0, "%d", local_u8ReadADC ); /* KNOWING THE LENGTH OF THE STRING */
	    u8* Local_u8ResultString = malloc( Local_u832Resultlength + 1 ); /* DYNAMIC MEMORY ALLOCATION FOR STRING SIZE */
	    snprintf( Local_u8ResultString, Local_u832Resultlength + 1, "%d", local_u8ReadADC ); /* CONVERTING NUMBER TO STRING */

	    CLCD_VidWriteString(Local_u8ResultString); /* PRINTING THE RESULT STRING */
	    free(Local_u8ResultString); /* FREE THE MEMORY SPACE FOR FURTHER SEVERAL OPERATIONS */
	    _delay_ms(1000);
	    CLCD_VidSendCommand(1); /* clear LCD screen */

	}
	return 0;
}



