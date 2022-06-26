/*
 * interface.h
 *
 *  Created on: Aug 23, 2021
 *      Author: Reem
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_vid_Init();
u16 ADC_u8ReadChannel(u8 Copy_u8Channel);
/* ISR */
void __vector_16 (void) __attribute__((signal));
void ADC_INT_Call_Back(void (*func) (void));
void ADC_VidAsynch_ReadChannel(u8 Copy_u8Channel);
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
