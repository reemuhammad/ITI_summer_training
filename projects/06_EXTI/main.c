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

/* A code that use a button on external interrupt 0 and another button on external interrupt 1
  to toggle 2 different LEDS with "on change sense control"  */

void task_1()
{
	TOGGLE_BIT(PORTA,Pin_0); /* toggle first LED */
}

void task_2()
{
	TOGGLE_BIT(PORTA,Pin_2); /* toggle second LED */
}

int main()
{
	EXTI_INT0_Call_Back(task_1);
	EXTI_INT1_Call_Back(task_2);

	/* set LEDS pins as outputs */
	DIO_VidSetPinDirection(Port_A,Pin_0,output);
	DIO_VidSetPinDirection(Port_A,Pin_2,output);
	/* initialize the LEDS with LOW */
	DIO_VidSetPinValue(Port_A,Pin_0,low);
	DIO_VidSetPinValue(Port_A,Pin_2,low);

	DIO_VidSetPinDirection(Port_D,Pin_2,input); /* connect the button on pin_2 ,PORT D : the INT0 pin */
	DIO_VidSetPinValue(Port_D,Pin_2,high);   /* activate pull up resistor  */
	DIO_VidSetPinDirection(Port_D,Pin_3,input); /* connect the button on pin_3 ,PORT D : the INT1 pin */
	DIO_VidSetPinValue(Port_D,Pin_3,high);   /* activate pull up resistor  */

	GIE_Vid_Enable(); /* activate the SREG pin */
	EXTI0_Vid_Init(); /* enable INT0 */
	EXTI1_Vid_Init(); /* enable INT1 */

	DIO_VidSetPinValue(Port_A,Pin_2,low);
	DIO_VidSetPinValue(Port_A,Pin_0,low);

	while(1)
	{

	}
	return 0;
}
