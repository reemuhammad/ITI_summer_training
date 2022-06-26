#include "lib/STD_TYPES.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "GIE_interface.h"


/*RECIEVE COMPLETE INTERRUPT:
IF THE UART RECEIVED 0: TURN ON YELLOW LED
IF THE UART RECEIVED 1: TURN ON BLUE LED
IF THE UART RECEIVED 2: TURN ON RED LED
IF THE UART RECEIVED ANY OTHER CHARACTER: TURN OFF ALL LEDS */

void RECIEVE_COMPLETE_ISR()
{
	switch(UDR)
	{
	case '0':
		DIO_VidSetPinValue(Port_C,Pin_0,high);
		break;
	case '1':
		DIO_VidSetPinValue(Port_C,Pin_1,high);
		break;
	case '2':
		DIO_VidSetPinValue(Port_C,Pin_2,high);
		break;
	default:
		DIO_VidSetPinValue(Port_C,Pin_0,low);
		DIO_VidSetPinValue(Port_C,Pin_1,low);
		DIO_VidSetPinValue(Port_C,Pin_2,low);
		break;
	}

}

int main()
{
	/* Set up LEDS */
	DIO_VidSetPinDirection(Port_C,Pin_0,output);
	DIO_VidSetPinDirection(Port_C,Pin_1,output);
	DIO_VidSetPinDirection(Port_C,Pin_2,output);

	RX_INT_Call_Back(RECIEVE_COMPLETE_ISR);  /* call back the ISR on receive complete */
	GIE_Vid_Enable(); /* enable the SREG bit : Enable interrupts */
	UART_vid_Init(); /* initialized UART as configured in UART_config.h file */


	while(1)
	{
		UART_vid_Receive(); /* keep receiving data */
	}
	return 0;
}
