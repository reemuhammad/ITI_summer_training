/*
 * ADC_program.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Reem
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_confg.h"
#include "ADC_interface.h"

#define NULL 			0
void ADC_vid_Init()
{
	/*   SELECT REFERENCE   */
	if(Voltage_Reference_Selection == AVCC)
	{
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLEAR_BIT(ADMUX, ADMUX_REFS1);
	}
	else if(Voltage_Reference_Selection == AREF)
	{
		CLEAR_BIT(ADMUX, ADMUX_REFS0);
		CLEAR_BIT(ADMUX, ADMUX_REFS1);
	}
	else if(Voltage_Reference_Selection == Internal_2_56V )
	{
		SET_BIT(ADMUX, ADMUX_REFS0);
		SET_BIT(ADMUX, ADMUX_REFS1);
	}

	////////////////////////////////////////////////////////////

	/*   ACTIVATE ADJUST   */
	if(ADC_DATA_REGISTER  == left_adjust)
	{
		SET_BIT(ADMUX, ADMUX_ADLAR);
	}
	else if(ADC_DATA_REGISTER  == right_adjust)
	{
		CLEAR_BIT(ADMUX, ADMUX_ADLAR);
	}

	////////////////////////////////////////////////////////////

	/* 	PRESCALAR SELECTION */
	if(PRESCALER == 128)
	{
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	}
	else if(PRESCALER == 64)
	{
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA, ADCSRA_ADPS0);
	}
	else if(PRESCALER == 32)
	{
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	CLEAR_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	}
	else if(PRESCALER == 16)
	{
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	CLEAR_BIT(ADCSRA, ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA, ADCSRA_ADPS0);
	}
	else if(PRESCALER == 8)
	{
	CLEAR_BIT(ADCSRA, ADCSRA_ADPS2);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	}
	else if(PRESCALER == 4)
	{
	CLEAR_BIT(ADCSRA, ADCSRA_ADPS2);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA, ADCSRA_ADPS0);
	}
	else if(PRESCALER == 2)
	{
	CLEAR_BIT(ADCSRA, ADCSRA_ADPS2);
	CLEAR_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	}

	////////////////////////////////////////////////////////////

	/*      ADC_Interrupt 	  */
	if(ADC_Interrupt  == ADC_Interrupt_Enable)
	{
		SET_BIT(ADCSRA, ADCSRA_ADIE);  /* remember to call the GIE: activate the SREG pin in order to enable interrupts */
	}
	else if(ADC_Interrupt  == ADC_Interrupt_Disable)
	{
		CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
	}

	////////////////////////////////////////////////////////////

	/*		 Auto Trigger adjustment	 */
	if(Auto_Trigger  ==  Auto_Trigger_Enable)
	{
		SET_BIT(ADCSRA, ADCSRA_ADATE);
		/* SET AUTO TRIGGER MODE */
		if(Auto_Trigger_Mode == Free_Running_mode)
		{
			CLEAR_BIT(SFIOR, SFIOR_ADTS2);
			CLEAR_BIT(SFIOR, SFIOR_ADTS1);
			CLEAR_BIT(SFIOR, SFIOR_ADTS0);
			SET_BIT(ADCSRA, ADCSRA_ADSC);   /* only needed one time */
		}
		else if(Auto_Trigger_Mode == Analog_Comparator)
		{
			CLEAR_BIT(SFIOR, SFIOR_ADTS2);
			CLEAR_BIT(SFIOR, SFIOR_ADTS1);
			SET_BIT(SFIOR, SFIOR_ADTS0);
		}
		else if(Auto_Trigger_Mode == External_Interrupt_Request_0)
		{
			CLEAR_BIT(SFIOR, SFIOR_ADTS2);
			SET_BIT(SFIOR, SFIOR_ADTS1);
			CLEAR_BIT(SFIOR, SFIOR_ADTS0);
		}
		else if(Auto_Trigger_Mode == Timer_Counter0_Compare_Match)
		{
			CLEAR_BIT(SFIOR, SFIOR_ADTS2);
			SET_BIT(SFIOR, SFIOR_ADTS1);
			SET_BIT(SFIOR, SFIOR_ADTS0);
		}
		else if(Auto_Trigger_Mode == Timer_Counter0_Overflow)
		{
			SET_BIT(SFIOR, SFIOR_ADTS2);
			CLEAR_BIT(SFIOR, SFIOR_ADTS1);
			CLEAR_BIT(SFIOR, SFIOR_ADTS0);
		}
		else if(Auto_Trigger_Mode == Timer_Counter1_Compare_Match_B)
		{
			SET_BIT(SFIOR, SFIOR_ADTS2);
			CLEAR_BIT(SFIOR, SFIOR_ADTS1);
			SET_BIT(SFIOR, SFIOR_ADTS0);
		}
		else if(Auto_Trigger_Mode == Timer_Counter1_Overflow)
		{
			SET_BIT(SFIOR, SFIOR_ADTS2);
			SET_BIT(SFIOR, SFIOR_ADTS1);
			CLEAR_BIT(SFIOR, SFIOR_ADTS0);
		}
		else if(Auto_Trigger_Mode == Timer_Counter1_Capture_Even)
		{
			SET_BIT(SFIOR, SFIOR_ADTS2);
			SET_BIT(SFIOR, SFIOR_ADTS1);
			SET_BIT(SFIOR, SFIOR_ADTS0);
		}
	}
	else if(Auto_Trigger  ==  Auto_Trigger_Disable)
	{
		CLEAR_BIT(ADCSRA, ADCSRA_ADATE);
	}

	////////////////////////////////////////////////////////////

	/*  ENABLE MODULE */
	SET_BIT(ADCSRA, ADCSRA_ADEN);

}

u16 ADC_u8ReadChannel(u8 Copy_u8Channel)
{
	/* CHOOSE CHANNEL */
	ADMUX &= 0b11100000; /* Clear the 5 bits at first*/
	ADMUX |= Copy_u8Channel; /* choose the channel */

	/* START CONVERSION */
	if(Auto_Trigger  ==  Auto_Trigger_Disable )
	{
		SET_BIT(ADCSRA, ADCSRA_ADSC);
	}

	/* WAIT TILL CONVERSION IS COMPLETE */
	while( ! GET_BIT(ADCSRA, ADCSRA_ADIF) );

	/* CLEAR THE FLAG BY WRITING 1 TO IT */
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	u16 volt=  (ADCH*5000UL)/255UL;
	return volt;
}


/*      ADC_Interrupt ,  ISR    */
void (* ADC_INT_func) (void) = NULL;

void ADC_INT_Call_Back(void (*func) (void))  /* In main: define a function for the task and call it back using this function  */
{
	ADC_INT_func = func;
}

void __vector_16 (void)
{
	if(ADC_INT_func != NULL )
		ADC_INT_func();
}

void ADC_VidAsynch_ReadChannel(u8 Copy_u8Channel)
{
	/* CHOOSE CHANNEL */
		ADMUX &= 0b11100000; /* Clear the 5 bits at first*/
		ADMUX |= Copy_u8Channel; /* choose the channel */

		/* START CONVERSION */
		if(Auto_Trigger  ==  Auto_Trigger_Disable )
		{
			SET_BIT(ADCSRA, ADCSRA_ADSC);
		}
}
