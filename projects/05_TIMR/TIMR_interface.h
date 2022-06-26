/*
 * TIMR_interface.h
 *
 *  Created on: Aug 24, 2021
 *      Author: DELL
 */

#ifndef TIMR_INTERFACE_H_
#define TIMR_INTERFACE_H_

void TIMR0_VidInit(void);       /* Initialize timer 0 as configured in TIMR_config.h file */
void TIMR0_CTC_SetCallBack(void (*Copy_pCallBackFunc) (void));  /* Call Back Function for Timer 0 Compare match ISR */
void TIMR0_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* Call Back Function for Timer 0 Over Flow ISR*/

void TIMR2_VidInit(u8 value);		/* Initialize timer 2 as configured in TIMR_config.h file */
void TIMR2_CTC_SetCallBack(void (*Copy_pCallBackFunc) (void));  /* Call Back Function for Timer 2 Compare match ISR */
void TIMR2_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* Call Back Function for Timer 2 Over Flow ISR*/

void TIMR1_VidInit(void);		/* Initialize timer 1 as configured in TIMR_config.h file */
void TIMR1_CTCA_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* Call Back Function for Timer 1 Compare match A ISR */
void TIMR1_CTCB_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* Call Back Function for Timer 1 Compare match B ISR */
void TIMR1_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* Call Back Function for Timer 1 Over Flow ISR*/

void TIMR0_Set_OCR();  /* FOR DUTY CYCLE----NOT DEFINED YET*/
#endif /* TIMR_INTERFACE_H_ */
