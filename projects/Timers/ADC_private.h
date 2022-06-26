/*
 * ADC_private.h
 *
 *  Created on: Aug 23, 2021
 *      Author: Reem
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX     	 *( (volatile u8 *) 0x27)
#define ADMUX_REFS1			7
#define ADMUX_REFS0			6
#define ADMUX_ADLAR			5
#define ADMUX_MUX4			4
#define ADMUX_MUX3			3
#define ADMUX_MUX2			2
#define ADMUX_MUX1			1
#define ADMUX_MUX0			0

#define ADCSRA		*( (volatile u8 *) 0x26)
#define ADCSRA_ADEN                7
#define ADCSRA_ADSC                6
#define ADCSRA_ADATE               5
#define ADCSRA_ADIF                4
#define ADCSRA_ADIE                3
#define ADCSRA_ADPS2               2
#define ADCSRA_ADPS1               1
#define ADCSRA_ADPS0               0

#define ADCH		*( (volatile u8 *) 0x25)
#define ADCL		*( (volatile u8 *) 0x24)

#define ADC_read	*( (volatile u16 *) 0x24)

#define SFIOR 		*( (volatile u8 *) 0x50)
#define SFIOR_ADTS2 				7
#define SFIOR_ADTS1 				6
#define SFIOR_ADTS0					5



/*   SELECT REFERENCE   */
#define  AREF				0
#define  AVCC				1
#define  Internal_2_56V		2

/*   ACTIVATE LEFT OR RIGHT ADJUST   */
#define  left_adjust  		1
#define  right_adjust		0

/*    ADC Interrupt    */
#define  ADC_Interrupt_Disable		0
#define  ADC_Interrupt_Enable		1

/*  Auto Trigger adjustment	 */
#define Auto_Trigger_Enable          1
#define Auto_Trigger_Disable         0

/* AUTO TRIGGER MODE */
/*-----------ONLY IF AUTO TRIGGER IS ENABLED-----------*/
#define Free_Running_mode							0
#define Analog_Comparator							1
#define External_Interrupt_Request_0				2
#define Timer_Counter0_Compare_Match				3
#define Timer_Counter0_Overflow						4
#define Timer_Counter1_Compare_Match_B				5
#define Timer_Counter1_Overflow						6
#define Timer_Counter1_Capture_Even					7
#endif /* ADC_PRIVATE_H_ */
