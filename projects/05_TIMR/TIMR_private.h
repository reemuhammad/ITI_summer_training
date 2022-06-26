/*
 * TIMR_private.h
 *
 *  Created on: Aug 24, 2021
 *      Author: DELL
 */


#ifndef TIMR_PRIVATE_H_
#define TIMR_PRIVATE_H_

#define TIMSK			*((volatile u8 * ) 0x59)	/* Timer counter interrupt mask */
#define TIMSK_OCIE0_PIN 		1					/* Timer output compare match interrupt enable */
#define TIMSK_TOIE0_PIN 		0
#define TIMSK_OCIE2_PIN			7
#define TIMSK_TOIE2_PIN			6
#define TIMSK_TOIE1_PIN			2
#define TIMSK_OCIE1B_PIN		3
#define TIMSK_OCIE1A_PIN		4

#define TIFR			*((volatile u8 * ) 0x58)	/* Timer interrupt flag register */
#define TIFR_OCF0_PIN 			1					/* Output compare flag */
#define TIFR_OCF2_PIN 			7

/* -----------------------------------TIMER 0-----------------------------------*/
#define TCCR0  			*((volatile u8 * ) 0x53)  	/* Timer counter control register */
#define TCCR0_WGM00_PIN			6				  	/* Wave generation mode bit 0 */
#define TCCR0_WGM01_PIN 		3				 	/* Wave generation mode bit 1 */
#define TCCR0_COM00_PIN 		4                 	/* Compare match output bit 0 */
#define TCCR0_COM01_PIN 		5					/* Compare match output bit 1 */
#define TCCR0_CS00_PIN			0				 	/* Timer clock select bit 0 */
#define TCCR0_CS01_PIN			1					/* Timer clock select bit 1 */
#define TCCR0_CS02_PIN			2					/* Timer clock select bit 2 */

#define OCR0			*((volatile u8 * ) 0x5C)	/* Output compare register */

/* -----------------------------------TIMER 2-----------------------------------*/
#define TCCR2  			*((volatile u8 * ) 0x45)  	/* Timer counter control register */
#define TCCR2_WGM20_PIN			6				  	/* Wave generation mode bit 0 */
#define TCCR2_WGM21_PIN 		3				 	/* Wave generation mode bit 1 */
#define TCCR2_COM20_PIN 		4                 	/* Compare match output bit 0 */
#define TCCR2_COM21_PIN 		5					/* Compare match output bit 1 */
#define TCCR2_CS20_PIN			0				 	/* Timer clock select bit 0 */
#define TCCR2_CS21_PIN			1					/* Timer clock select bit 1 */
#define TCCR2_CS22_PIN			2					/* Timer clock select bit 2 */

#define OCR2			*((volatile u8 * ) 0x43)	/* Output compare register */
/* -----------------------------------TIMER 1-----------------------------------*/

#define TCCR1A 			*((volatile u8 * ) 0x4F)
#define TCCR1A_COM1A1_PIN	7			 /* Compare match output bit */
#define TCCR1A_COM1A0_PIN	6            /* Compare match output bit */
#define TCCR1A_COM1B1_PIN	5            /* Compare match output bit */
#define TCCR1A_COM1B0_PIN	4            /* Compare match output bit */
#define TCCR1A_FOC1A_PIN	3
#define TCCR1A_FOC1B_PIN	2
#define TCCR1A_WGM11_PIN	1            /* Wave generation bit */
#define TCCR1A_WGM10_PIN	0            /* Wave generation bit */

#define TCCR1B			*((volatile u8 * ) 0x4E)
#define TCCR1B_ICNC1_PIN    7
#define TCCR1B_ICES1_PIN    6
#define TCCR1B_WGM13_PIN    4             /* Wave generation bit */
#define TCCR1B_WGM12_PIN    3             /* Wave generation bit */
#define TCCR1B_CS12_PIN     2             /* Timer clock select */
#define TCCR1B_CS11_PIN     1             /* Timer clock select */
#define TCCR1B_CS10_PIN     0             /* Timer clock select */

#define OCR1AH			*((volatile u8 * ) 0x4B)
#define OCR1AL			*((volatile u16 * ) 0x4A)
#define OCR1BH			*((volatile u8 * ) 0x49)
#define OCR1BL			*((volatile u8 * ) 0x48)
#define ICR1			*((volatile u16 * ) 0x46)
/* ------------------------------For configuration------------------------------ */
/* Choose which timers you want to use :*/
#define ENABLE_TIMER 			 0
#define DISABLE_TIMER			 1

/*  Wave generation mode */
#define Normal					0
#define PWM_Phase_Correct		1
#define CTC						2
#define Fast_PWM				3
#define Fast_PWM_ICR			4

/* Compare Output Mode for NON-PWM mode */
#define Normal_port_operation				0

#define Toggle_OC0_on_compare_match			1
#define Clear_OC0_on_compare_match			2
#define Set_OC0_on_compare_match 			3


#define Toggle_OC1A_on_compare_match	    1
#define Clear_OC1A_on_compare_match  		2
#define Set_OC1A_on_compare_match	        3


#define Toggle_OC1B_on_compare_match	    1
#define Clear_OC1B_on_compare_match  		2
#define Set_OC1B_on_compare_match           3

#define Toggle_OC2_on_compare_match	        1
#define Clear_OC2_on_compare_match  		2
#define Set_OC2_on_compare_match            3

/* for choosing compare units A or B in timer 1 */
#define ENABLE								0
#define DISABLE								1

/* Prescaler */
#define NO_PRESCALER						0
#define PRESCALER_DIVIDE_BY_8               1
#define PRESCALER_DIVIDE_BY_64              2
#define PRESCALER_DIVIDE_BY_256             3
#define PRESCALER_DIVIDE_BY_1024			4
#define EXT_CLK_FALLING_EDGE				5
#define EXT_CLK_RISING_EDGE					6

/* Timer interrupt */
#define INT_DISABLE							0
#define Output_Compare_Match_Int_En			1
#define Overflow_Int_En						2
#define Output_Compare_A_Match_Int_En		3   		/* for timer 1 */
#define Output_Compare_B_Match_Int_En		4			/* for timer 1 */
#endif /* TIMR_PRIVATE_H_ */
