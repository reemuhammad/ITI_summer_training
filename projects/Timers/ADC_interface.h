/*
 * interface.h
 *
 *  Created on: Aug 23, 2021
 *      Author: Reem
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* Initialize ADC */
void ADC_vid_Init();
/* Read ADC channel */
u16 ADC_u8ReadChannel(u8 Copy_u8Channel);

/* ISR */
void __vector_16 (void) __attribute__((signal));
void ADC_INT_Call_Back(void (*func) (void));

/* for asynchronous reading of ADC channel */
void ADC_VidAsynch_ReadChannel(u8 Copy_u8Channel);
/* function to get the corresponding volt of maximum 5 Volt */
u16 GetMilliVolt_u16Max5V(u8 Copy_ADCH_value);
/* mapping function that gives the corresponding value of a number in different domain */
u16 Map_u16Function(u16 Copy_u16GivenValue, u16 Copy_u16FromMin, u16 Copy_u16FromMax, u16 Copy_u16NewMin, u16 Copy_u16NewMax);
typedef enum
{
	ADC_0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7
}enum_ADCchannel;

#endif /* ADC_INTERFACE_H_ */
