/*
 * ADC_confg.h
 *
 *  Created on: Aug 23, 2021
 *      Author: Reem
 */

#ifndef ADC_CONFG_H_
#define ADC_CONFG_H_

/*   CHOOSE PRESCALER   */
#define PRESCALER 			128            			/* <<<<<<<<<<<<<<<<<< CHOOSE HERE <<<<<<<<<<<<<<<<<<*/

/*   SELECT REFERENCE   */
#define Voltage_Reference_Selection    AVCC			/* <<<<<<<<<<<<<<<<<< CHOOSE HERE <<<<<<<<<<<<<<<<<<*/

/*   ACTIVATE LEFT OR RIGHT ADJUST   */
#define  ADC_DATA_REGISTER   right_adjust			/* <<<<<<<<<<<<<<<<<< CHOOSE HERE <<<<<<<<<<<<<<<<<<*/

/*    ADC Interrupt    */
#define  ADC_Interrupt 		ADC_Interrupt_Disable	/* <<<<<<<<<<<<<<<<<< CHOOSE HERE <<<<<<<<<<<<<<<<<<*/

/*  Auto Trigger adjustment	 */
#define Auto_Trigger        Auto_Trigger_Disable  	/* <<<<<<<<<<<<<<<<<< CHOOSE HERE <<<<<<<<<<<<<<<<<<*/

/* AUTO TRIGGER MODE */
/*-----------ONLY IF AUTO TRIGGER IS ENABLED-----------*/
#define Auto_Trigger_Mode			Analog_Comparator   /* <<<<<<<<<<<<<<<<<< CHOOSE HERE <<<<<<<<<<<<<<<<<<*/

#endif /* ADC_CONFG_H_ */
