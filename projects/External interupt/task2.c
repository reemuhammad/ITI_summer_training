/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: REEM
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "util/delay.h"

/* A code that use a button on external interrupt 2 to change the animation of LEDS on  "falling edge sense control"  */

void task_1()
{
	/* changing the animation of LEDS */
	DIO_VidSetPortValue(Port_A,0);
	for(u8 i=0; i<8; i+=2)
	{
		DIO_VidSetPinValue(Port_A,i,high);
		_delay_ms(500);
	}

}


int main()
{

	EXTI_INT2_Call_Back(task_1);

	DIO_VidSetPortDirection(Port_A,output); /*connect the LEDS on PORT A  */

	DIO_VidSetPinDirection(Port_B,Pin_2,input); /* connect the button on pin_2 ,PORT B : the INT2 pin */
	DIO_VidSetPinValue(Port_B,Pin_2,high);   /* activate pull up resistor  */

	GIE_Vid_Enable(); /* activate the SREG pin */
	EXTI2_Vid_Init(); /* enable INT2 */

	while(1)
	{
		DIO_VidSetPortValue(Port_A,0xff); /* on normal condition turn on all the LEDS on port A */
	}
	return 0;
}



