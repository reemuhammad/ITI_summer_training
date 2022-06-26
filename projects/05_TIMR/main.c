/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: DELL
 */

#include"lib/STD_TYPES.H"
#include"lib/BIT_MATH.H"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMR_interface.h"
#include "GIE_interface.h"
#include "CLCD_config.h"
#include "CLCD_INTERFACE.h"
#include "ADC_interface.h"
#include "util/delay.h"
int main()
{
	DIO_VidSetPinDirection(Port_B,Pin_3,output);    /* Set OC0 PIN as output */
	TIMR0_VidInit();								/* Configured in PWM PHASE CORRECT mode */

	DIO_VidSetPinDirection(Port_D,Pin_5,output);	/* Set OC1A PIN as output */
	DIO_VidSetPinDirection(Port_D,Pin_4,output);	/* Set OC1B PIN as output */
	TIMR1_VidInit();								/* Configured in CTC mode */
	DIO_VidSetPinDirection(Port_D,Pin_7,output);

	/* Setting up LCD pins  */
		/*DIO_VidSetPortDirection(CLCD_DATA_PORT,output);
		DIO_VidSetPinDirection(CLCD_CCTRL_PORT,Pin_0,output);
		DIO_VidSetPinDirection(CLCD_CCTRL_PORT,Pin_1,output);
		DIO_VidSetPinDirection(CLCD_CCTRL_PORT,Pin_2,output);*/
		/* initialize LCD */
		//CLCD_VidInit();
		/* set the potentiometer as input */
		//DIO_VidSetPinDirection(Port_A,Pin_0,input);
		/* initialize ADC */
		//ADC_vid_Init();
		//u8 local_u8ReadADC=0;


	while(1)
	{
		//local_u8ReadADC=ADC_u8ReadChannel(0);
		//TIMR2_VidInit(local_u8ReadADC);
		//_delay_ms(100);
	}
	return 0;
}
