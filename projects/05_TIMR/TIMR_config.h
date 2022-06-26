/*
 * TIMR_config.h
 *
 *  Created on: Aug 24, 2021
 *      Author: DELL
 */

#ifndef TIMR_CONFIG_H_
#define TIMR_CONFIG_H_

/* PRESCALER */
/* Choose one of the following:

    NO_PRESCALER
    PRESCALER_DIVIDE_BY_8
    PRESCALER_DIVIDE_BY_64
    PRESCALER_DIVIDE_BY_256
    PRESCALER_DIVIDE_BY_1024
    EXT_CLK_FALLING_EDGE
    EXT_CLK_RISING_EDGE

*/
#define PRESCALER						  PRESCALER_DIVIDE_BY_8

/* Choose which timers you want to use :
  for each timer choose either:         ENABLE_TIMER     or     DISABLE_TIMER
 */

#define TIMER_0				ENABLE_TIMER
#define TIMER_1				ENABLE_TIMER
#define TIMER_2				DISABLE_TIMER
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
#if TIMER_0 == ENABLE_TIMER
/*  Wave generation mode */
/* Choose one of the following:

    Normal
    PWM_Phase_Correct
    CTC
    Fast_PWM

 */
#define Wave_generation_mode				Fast_PWM

/* Compare Output Mode  */
/* Choose one of the following:

 	Normal_port_operation					// OC0 disconnected

	Toggle_OC0_on_compare_match				// For a NON-PWM mode

    Clear_OC0_on_compare_match          //In Fast PWM : Non-inverting mode,
    									//In PWM Phase Correct mode:
    									//Clear OC0 on compare match when up-counting. Set OC0 on compare match when down counting.

    Set_OC0_on_compare_match			//In Fast PWM : Inverting mode
										//In PWM Phase Correct mode:
    									// Set OC0 on compare match when up-counting.
    									// Clear OC0 on compare match when down counting
 */
#define Compare_Output_Mode				Clear_OC0_on_compare_match

#define OCR0_value 							128     // value written in OCR register


/* Timer interrupt */
/* Choose one of the following:

    INT_DISABLE
    Output_Compare_Match_Int_En
    Overflow_Int_En

*/
#define TIMR_INTERRUPT					INT_DISABLE

#endif
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/********************************************************************************************************************************************************************************/
/********************************************************************************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TIMER_1 == ENABLE_TIMER
/*  Wave generation mode */
/* Choose one of the following:

    Normal
    PWM_Phase_Correct
    CTC
    Fast_PWM
	Fast_PWM_ICR
 */
#define Wave_generation_mode_TIMR_1				 Fast_PWM

/* Select  which compare units you want:
 Choose for each unit either:      			ENABLE        or         DISABLE
 */
#define Compare_Unit_A 			ENABLE
#define Compare_Unit_B 			DISABLE

#if Compare_Unit_A == ENABLE
/* Compare Output Mode for Compare unit A */
/* Choose one of the following for Compare unit A :

 	Normal_port_operation					// OC1A pin disconnected

	Toggle_OC1A_on_compare_match				// For a NON-PWM mode

    Clear_OC1A_on_compare_match          //In Fast PWM : Non-inverting mode,
    									//In PWM Phase Correct mode:
    									//Clear OC1A on compare match when up-counting. Set OC1A on compare match when down counting.

    Set_OC1A_on_compare_match			//In Fast PWM : Inverting mode
										//In PWM Phase Correct mode:
    									// Set OC1A on compare match when up-counting.
    									// Clear OC1A on compare match when down counting
 */
#define Compare_A_Output_Mode				Clear_OC1A_on_compare_match

#define OCRA_value 							500     // value written in OCR register
#endif

#if Compare_Unit_B == ENABLE
/* Compare Output Mode for Compare unit A */
/* Choose one of the following for Compare unit A :

 	Normal_port_operation					// OC1A pin disconnected

	Toggle_OC1B_on_compare_match				// For a NON-PWM mode

    Clear_OC1B_on_compare_match          //In Fast PWM : Non-inverting mode,
    									//In PWM Phase Correct mode:
    									//Clear OC1B on compare match when up-counting. Set OC1B on compare match when down counting.

    Set_OC1B_on_compare_match			//In Fast PWM : Inverting mode
										//In PWM Phase Correct mode:
    									// Set OC1B on compare match when up-counting.
    									// Clear OC1B on compare match when down counting
 */
#define Compare_B_Output_Mode				Toggle_OC1B_on_compare_match

#define OCRB_value 							600     // value written in OCR register
#endif


/* Timer interrupt */
/* Choose one of the following:

    INT_DISABLE
    Output_Compare_A_Match_Int_En
    Output_Compare_B_Match_Int_En
    Overflow_Int_En

*/
#define TIMR_INTERRUPT					INT_DISABLE

#endif
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/********************************************************************************************************************************************************************************/
/********************************************************************************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TIMER_2 == ENABLE_TIMER
/*  Wave generation mode */
/* Choose one of the following:

    Normal
    PWM_Phase_Correct
    CTC
    Fast_PWM

 */
#define Wave_generation_mode_TIMR_2				Fast_PWM

/* Compare Output Mode  */
/* Choose one of the following:

 	Normal_port_operation					// OC2 disconnected

	Toggle_OC2_on_compare_match				// For a NON-PWM mode

    Clear_OC2_on_compare_match          //In Fast PWM : Non-inverting mode,
    									//In PWM Phase Correct mode:
    									//Clear OC2 on compare match when up-counting. Set OC2 on compare match when down counting.

    Set_OC2_on_compare_match			//In Fast PWM : Inverting mode
										//In PWM Phase Correct mode:
    									// Set OC2 on compare match when up-counting.
    									// Clear OC2 on compare match when down counting
 */
#define Compare_Output_Mode_TIMR2				 Clear_OC2_on_compare_match

#define OCR2_value 							127     // value written in OCR register


/* Timer interrupt */
/* Choose one of the following:

    INT_DISABLE
    Output_Compare_Match_Int_En
    Overflow_Int_En

*/
#define TIMR_INTERRUPT					INT_DISABLE

#endif

#endif /* TIMR_CONFIG_H_ */
