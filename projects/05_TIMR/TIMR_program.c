/*
 * TIMR_program.c
 *
 *  Created on: Aug 24, 2021
 *      Author: DELL
 */

#include"lib/STD_TYPES.H"
#include"lib/BIT_MATH.H"
#include "TIMR_interface.h"
#include "TIMR_private.h"
#include "TIMR_config.h"

void TIMR0_VidInit(void)
{
#if TIMER_0 == ENABLE_TIMER
	/* Select mode */
#if Wave_generation_mode == Normal
	CLEAR_BIT(TCCR0,TCCR0_WGM00_PIN);
	CLEAR_BIT(TCCR0,TCCR0_WGM01_PIN);
#elif Wave_generation_mode == CTC
	CLEAR_BIT(TCCR0,TCCR0_WGM00_PIN);
	SET_BIT(TCCR0,TCCR0_WGM01_PIN);
#elif Wave_generation_mode == PWM_Phase_Correct
	SET_BIT(TCCR0,TCCR0_WGM00_PIN);
	CLEAR_BIT(TCCR0,TCCR0_WGM01_PIN);
#elif Wave_generation_mode == Fast_PWM
	SET_BIT(TCCR0,TCCR0_WGM00_PIN);
	SET_BIT(TCCR0,TCCR0_WGM01_PIN);
#endif
/* ------------------------------------------------------------------- */
	/* Compare Output Mode */
#if Compare_Output_Mode	== Normal_port_operation
	CLEAR_BIT(TCCR0,TCCR0_COM00_PIN );
	CLEAR_BIT(TCCR0,TCCR0_COM01_PIN);
#elif Compare_Output_Mode	==	Toggle_OC0_on_compare_match
	SET_BIT(TCCR0,TCCR0_COM00_PIN );
	CLEAR_BIT(TCCR0,TCCR0_COM01_PIN);
#elif Compare_Output_Mode	== Clear_OC0_on_compare_match				//Non-inverting mode for pwm
	CLEAR_BIT(TCCR0,TCCR0_COM00_PIN );
	SET_BIT(TCCR0,TCCR0_COM01_PIN);
#elif Compare_Output_Mode	== Set_OC0_on_compare_match					//Inverting mode for pwm
	SET_BIT(TCCR0,TCCR0_COM00_PIN );
	SET_BIT(TCCR0,TCCR0_COM01_PIN);
#endif
	/* Timer interrupt enable */
#if 	TIMR_INTERRUPT	==	INT_DISABLE
	CLEAR_BIT(TIMSK,TIMSK_OCIE0_PIN);
	CLEAR_BIT(TIMSK,TIMSK_TOIE0_PIN);
#endif
#if 	TIMR_INTERRUPT	==	Output_Compare_Match_Int_En
	SET_BIT(TIMSK,TIMSK_OCIE0_PIN);
#endif
#if 	TIMR_INTERRUPT	==	Overflow_Int_En
	SET_BIT(TIMSK,TIMSK_TOIE0_PIN);
#endif
/* ------------------------------------------------------------------- */
	/* OCR */
	OCR0= OCR0_value;   /* 250 gives 4000 count to get 1 sec */
/* ------------------------------------------------------------------- */
	/* PRESCALER */
#if PRESCALER == NO_PRESCALER
	SET_BIT(TCCR0,TCCR0_CS00_PIN);
	CLEAR_BIT(TCCR0,TCCR0_CS01_PIN);
	CLEAR_BIT(TCCR0,TCCR0_CS02_PIN);
#elif	PRESCALER == PRESCALER_DIVIDE_BY_8
	CLEAR_BIT(TCCR0,TCCR0_CS00_PIN);
	SET_BIT(TCCR0,TCCR0_CS01_PIN);
	CLEAR_BIT(TCCR0,TCCR0_CS02_PIN);
#elif	PRESCALER == PRESCALER_DIVIDE_BY_64
	SET_BIT(TCCR0,TCCR0_CS00_PIN);
	SET_BIT(TCCR0,TCCR0_CS01_PIN);
	CLEAR_BIT(TCCR0,TCCR0_CS02_PIN);
#elif	PRESCALER == PRESCALER_DIVIDE_BY_256
	CLEAR_BIT(TCCR0,TCCR0_CS00_PIN);
	CLEAR_BIT(TCCR0,TCCR0_CS01_PIN);
	SET_BIT(TCCR0,TCCR0_CS02_PIN);
#elif	PRESCALER == PRESCALER_DIVIDE_BY_1024
	SET_BIT(TCCR0,TCCR0_CS00_PIN);
	CLEAR_BIT(TCCR0,TCCR0_CS01_PIN);
	SET_BIT(TCCR0,TCCR0_CS02_PIN);
#elif	PRESCALER == EXT_CLK_FALLING_EDGE
	CLEAR_BIT(TCCR0,TCCR0_CS00_PIN);
	SET_BIT(TCCR0,TCCR0_CS01_PIN);
	SET_BIT(TCCR0,TCCR0_CS02_PIN);
#elif	PRESCALER == EXT_CLK_RISING_EDGE
	SET_BIT(TCCR0,TCCR0_CS00_PIN);
	SET_BIT(TCCR0,TCCR0_CS01_PIN);
	SET_BIT(TCCR0,TCCR0_CS02_PIN);
#endif
#endif
}
/***************************************************************************************************************************************************/
/* ------------------------------------------------------ISR------------------------------------------------------ */
static void (* TIMR0_CTC_SetCallBackfunc) (void) =NULL;   /* pointer to timer 0 compare match ISR */
static void (* TIMR0_OvF_SetCallBackfunc) (void) =NULL;	  /* pointer to timer 0 Overflow ISR */

void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)                          /* timer 0 compare match ISR */
{
	if(TIMR0_CTC_SetCallBackfunc != NULL)
	{
		TIMR0_CTC_SetCallBackfunc();
	}
}

void TIMR0_CTC_SetCallBack(void (*Copy_pCallBackFunc) (void))	/* timer 0 compare match call back function */
{
	if(Copy_pCallBackFunc != NULL)
	{
		TIMR0_CTC_SetCallBackfunc = Copy_pCallBackFunc;
	}
}
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)						/* timer 0 Overflow ISR */
{
	if(TIMR0_OvF_SetCallBackfunc != NULL)
	{
		TIMR0_OvF_SetCallBackfunc();
	}
}
void TIMR0_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void))  /* timer 0 Overflow call back function  */
{
	if(Copy_pCallBackFunc != NULL)
		{
		TIMR0_OvF_SetCallBackfunc = Copy_pCallBackFunc;
		}
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void TIMR2_VidInit(u8 value)
{
#if TIMER_2 == ENABLE_TIMER
	/* Select mode */
#if Wave_generation_mode_TIMR_2	 == Normal
	CLEAR_BIT(TCCR2,TCCR2_WGM20_PIN);
	CLEAR_BIT(TCCR2,TCCR2_WGM21_PIN);
#elif Wave_generation_mode_TIMR_2	 == CTC
	CLEAR_BIT(TCCR2,TCCR2_WGM20_PIN);
	SET_BIT(TCCR2,TCCR2_WGM21_PIN);
#elif Wave_generation_mode_TIMR_2	 == PWM_Phase_Correct
	SET_BIT(TCCR2,TCCR2_WGM20_PIN);
	CLEAR_BIT(TCCR2,TCCR2_WGM21_PIN);
#elif Wave_generation_mode_TIMR_2	 == Fast_PWM
	SET_BIT(TCCR2,TCCR2_WGM20_PIN);
	SET_BIT(TCCR2,TCCR2_WGM21_PIN);
#endif
/* ------------------------------------------------------------------- */
	/* Compare Output Mode for NON-PWM mode */
#if Compare_Output_Mode_TIMR2	== Normal_port_operation
	CLEAR_BIT(TCCR2,TCCR2_COM20_PIN );
	CLEAR_BIT(TCCR2,TCCR2_COM21_PIN);
#elif Compare_Output_Mode_TIMR2	==	Toggle_OC2_on_compare_match
	SET_BIT(TCCR2,TCCR2_COM20_PIN );
	CLEAR_BIT(TCCR2,TCCR2_COM21_PIN);
#elif Compare_Output_Mode_TIMR2	== Clear_OC2_on_compare_match   /* Non-inverting mode */
	CLEAR_BIT(TCCR2,TCCR2_COM20_PIN );
	SET_BIT(TCCR2,TCCR2_COM21_PIN);
#elif Compare_Output_Mode_TIMR2	== Set_OC2_on_compare_match		/* Inverting mode */
	SET_BIT(TCCR2,TCCR2_COM20_PIN );
	SET_BIT(TCCR2,TCCR2_COM21_PIN);
#endif
	/* Timer interrupt enable */
#if 	TIMR_INTERRUPT	==	INT_DISABLE
	CLEAR_BIT(TIMSK,TIMSK_OCIE2_PIN);
	CLEAR_BIT(TIMSK,TIMSK_TOIE2_PIN);
#endif
#if 	TIMR_INTERRUPT	==	Output_Compare_Match_Int_En
	SET_BIT(TIMSK,TIMSK_OCIE2_PIN);
#endif
#if 	TIMR_INTERRUPT	==	Overflow_Int_En
	SET_BIT(TIMSK,TIMSK_TOIE2_PIN);
#endif
/* ------------------------------------------------------------------- */
	/* OCR */
	OCR2= value;   /* 4000 count to get 1 sec */
/* ------------------------------------------------------------------- */
	/* PRESCALER */
#if PRESCALER == NO_PRESCALER
	SET_BIT(TCCR2,TCCR2_CS20_PIN);
	CLEAR_BIT(TCCR2,TCCR2_CS21_PIN);
	CLEAR_BIT(TCCR2,TCCR2_CS22_PIN);
#elif	PRESCALER == PRESCALER_DIVIDE_BY_8
	CLEAR_BIT(TCCR2,TCCR2_CS20_PIN);
	SET_BIT(TCCR2,TCCR2_CS21_PIN);
	CLEAR_BIT(TCCR2,TCCR2_CS22_PIN);
#elif	PRESCALER == PRESCALER_DIVIDE_BY_64
	SET_BIT(TCCR2,TCCR2_CS20_PIN);
	SET_BIT(TCCR2,TCCR2_CS21_PIN);
	CLEAR_BIT(TCCR2,TCCR2_CS22_PIN);
#elif	PRESCALER == PRESCALER_DIVIDE_BY_256
	CLEAR_BIT(TCCR2,TCCR2_CS20_PIN);
	CLEAR_BIT(TCCR2,TCCR2_CS21_PIN);
	SET_BIT(TCCR2,TCCR2_CS22_PIN);
#elif	PRESCALER == PRESCALER_DIVIDE_BY_1024
	SET_BIT(TCCR2,TCCR2_CS20_PIN);
	CLEAR_BIT(TCCR2,TCCR2_CS21_PIN);
	SET_BIT(TCCR2,TCCR2_CS22_PIN);
#elif	PRESCALER == EXT_CLK_FALLING_EDGE
	CLEAR_BIT(TCCR2,TCCR2_CS20_PIN);
	SET_BIT(TCCR2,TCCR2_CS21_PIN);
	SET_BIT(TCCR2,TCCR2_CS22_PIN);
#elif	PRESCALER == EXT_CLK_RISING_EDGE
	SET_BIT(TCCR2,TCCR2_CS20_PIN);
	SET_BIT(TCCR2,TCCR2_CS21_PIN);
	SET_BIT(TCCR2,TCCR2_CS22_PIN);
#endif
#endif
}
/***************************************************************************************************************************************************/
/* ------------------------------------------------------ISR------------------------------------------------------ */
static void (* TIMR2_CTC_SetCallBackfunc) (void) =NULL;   /* pointer to timer 2 compare match ISR */
static void (* TIMR2_OvF_SetCallBackfunc) (void) =NULL;	  /* pointer to timer 2 Overflow ISR */

void __vector_4(void) __attribute__ ((signal));
void __vector_4(void)                          /* timer 2 compare match ISR */
{
	if(TIMR2_CTC_SetCallBackfunc != NULL)
	{
		TIMR2_CTC_SetCallBackfunc();
	}
}

void TIMR2_CTC_SetCallBack(void (*Copy_pCallBackFunc) (void))	/* timer 2 compare match call back function */
{
	if(Copy_pCallBackFunc != NULL)
	{
		TIMR2_CTC_SetCallBackfunc = Copy_pCallBackFunc;
	}
}
void __vector_5(void) __attribute__ ((signal));
void __vector_5(void)						/* timer 0 Overflow ISR */
{
	if(TIMR0_OvF_SetCallBackfunc != NULL)
	{
		TIMR0_OvF_SetCallBackfunc();
	}
}
void TIMR2_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void))  /* timer 2 Overflow call back function  */
{
	if(Copy_pCallBackFunc != NULL)
		{
		TIMR2_OvF_SetCallBackfunc = Copy_pCallBackFunc;
		}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void TIMR1_VidInit(void)
{
#if TIMER_1 == ENABLE_TIMER
	/* Select mode */
	#if Wave_generation_mode_TIMR_1	 == Normal
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10_PIN);
		CLEAR_BIT(TCCR1A,TCCR1A_WGM11_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_WGM12_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_WGM13_PIN);
	#elif Wave_generation_mode_TIMR_1	 == CTC
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10_PIN);
		CLEAR_BIT(TCCR1A,TCCR1A_WGM11_PIN);
		SET_BIT(TCCR1B,TCCR1B_WGM12_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_WGM13_PIN);
	#elif Wave_generation_mode_TIMR_1	 == PWM_Phase_Correct
		SET_BIT(TCCR1A,TCCR1A_WGM10_PIN);
		SET_BIT(TCCR1A,TCCR1A_WGM11_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_WGM12_PIN);
		SET_BIT(TCCR1B,TCCR1B_WGM13_PIN);
	#elif Wave_generation_mode_TIMR_1	 == Fast_PWM
		SET_BIT(TCCR1A,TCCR1A_WGM10_PIN);
		SET_BIT(TCCR1A,TCCR1A_WGM11_PIN);
		SET_BIT(TCCR1B,TCCR1B_WGM12_PIN);
		SET_BIT(TCCR1B,TCCR1B_WGM13_PIN);
	#elif Wave_generation_mode_TIMR_1	 == Fast_PWM_ICR
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10_PIN);
		SET_BIT(TCCR1A,TCCR1A_WGM11_PIN);
		SET_BIT(TCCR1B,TCCR1B_WGM12_PIN);
		SET_BIT(TCCR1B,TCCR1B_WGM13_PIN);
		ICR1 = 20000 ;
	#endif
	/* ------------------------------------------------------------------- */
		/* Compare Output Mode  */
		/* COMPARE UNIT A */
	#if Compare_Unit_A == ENABLE
	#if Compare_A_Output_Mode	== Normal_port_operation
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0_PIN );
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1_PIN);
	#elif Compare_A_Output_Mode	==	Toggle_OC1A_on_compare_match
		SET_BIT(TCCR1A,TCCR1A_COM1A0_PIN );
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1_PIN);
	#elif Compare_A_Output_Mode	== Clear_OC1A_on_compare_match				//Non-inverting mode for pwm
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0_PIN );
		SET_BIT(TCCR1A,TCCR1A_COM1A1_PIN);
	#elif Compare_A_Output_Mode	== Set_OC1A_on_compare_match					//Inverting mode for pwm
		SET_BIT(TCCR1A,TCCR1A_COM1A0_PIN );
		SET_BIT(TCCR1A,TCCR1A_COM1A1_PIN);
	#endif
		/*OCR1AH = OCRA_value >> 8 ;
		OCR1AL= (u8) OCRA_value ;*/
		OCR1AL = (u16) OCRA_value;
		//OCR1AL = 500;
	#endif
	/* ------------------------------------------------------------------- */
		/* COMPARE UNIT B */
	#if Compare_Unit_B == ENABLE
	#if Compare_B_Output_Mode	== Normal_port_operation
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0_PIN );
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B1_PIN);
	#elif Compare_B_Output_Mode	==	Toggle_OC1B_on_compare_match
		SET_BIT(TCCR1A,TCCR1A_COM1B0_PIN );
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B1_PIN);
	#elif Compare_B_Output_Mode	== Clear_OC1B_on_compare_match				//Non-inverting mode for pwm
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0_PIN );
		SET_BIT(TCCR1A,TCCR1A_COM1B1_PIN);
	#elif Compare_B_Output_Mode	== Set_OC1B_on_compare_match					//Inverting mode for pwm
		SET_BIT(TCCR1A,TCCR1A_COM1B0_PIN );
		SET_BIT(TCCR1A,TCCR1A_COM1B1_PIN);
	#endif
		OCR1BH = OCRB_value >> 8;
		OCR1BL= (u8) OCRB_value;
	#endif

	/* ------------------------------------------------------------------- */
		/* Timer interrupt enable */
	#if 	TIMR_INTERRUPT	==	INT_DISABLE
		CLEAR_BIT(TIMSK,TIMSK_TOIE1_PIN);
		CLEAR_BIT(TIMSK,TIMSK_OCIE1B_PIN);
		CLEAR_BIT(TIMSK,TIMSK_OCIE1A_PIN);
	#endif
	#if 	TIMR_INTERRUPT	==	Output_Compare_A_Match_Int_En
		SET_BIT(TIMSK,TIMSK_OCIE1A_PIN);
	#endif
	#if 	TIMR_INTERRUPT	==	Output_Compare_B_Match_Int_En
		SET_BIT(TIMSK,TIMSK_OCIE1B_PIN);
	#endif
	#if 	TIMR_INTERRUPT	==	Overflow_Int_En
		SET_BIT(TIMSK,TIMSK_TOIE1_PIN);
	#endif
	/* ------------------------------------------------------------------- */
		/* PRESCALER */
	#if PRESCALER == NO_PRESCALER
		SET_BIT(TCCR1B,TCCR1B_CS10_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12_PIN);
	#elif	PRESCALER == PRESCALER_DIVIDE_BY_8
		CLEAR_BIT(TCCR1B,TCCR1B_CS10_PIN);
		SET_BIT(TCCR1B,TCCR1B_CS11_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12_PIN);
	#elif	PRESCALER == PRESCALER_DIVIDE_BY_64
		SET_BIT(TCCR1B,TCCR1B_CS10_PIN);
		SET_BIT(TCCR1B,TCCR1B_CS11_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12_PIN);
	#elif	PRESCALER == PRESCALER_DIVIDE_BY_256
		CLEAR_BIT(TCCR1B,TCCR1B_CS10_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11_PIN);
		SET_BIT(TCCR1B,TCCR1B_CS12_PIN);
	#elif	PRESCALER == PRESCALER_DIVIDE_BY_1024
		SET_BIT(TCCR1B,TCCR1B_CS10_PIN);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11_PIN);
		SET_BIT(TCCR1B,TCCR1B_CS12_PIN);
	#elif	PRESCALER == EXT_CLK_FALLING_EDGE
		CLEAR_BIT(TCCR1B,TCCR1B_CS10_PIN);
		SET_BIT(TCCR1B,TCCR1B_CS11_PIN);
		SET_BIT(TCCR1B,TCCR1B_CS12_PIN);
	#elif	PRESCALER == EXT_CLK_RISING_EDGE
		SET_BIT(TCCR1B,TCCR1B_CS10_PIN);
		SET_BIT(TCCR1B,TCCR1B_CS11_PIN);
		SET_BIT(TCCR1B,TCCR1B_CS12_PIN);
	#endif
#endif
}
/***************************************************************************************************************************************************/
/* ------------------------------------------------------ISR------------------------------------------------------ */
static void (* TIMR1_CTCA_SetCallBackfunc) (void) =NULL;   /* pointer to timer 1 compare match A ISR */
static void (* TIMR1_CTCB_SetCallBackfunc) (void) =NULL;   /* pointer to timer 1 compare match A ISR */
static void (* TIMR1_OvF_SetCallBackfunc) (void) =NULL;	  /* pointer to timer 1 Overflow ISR */

void __vector_7(void) __attribute__ ((signal));
void __vector_7(void)                          /* timer 1 compare match A ISR */
{
	if(TIMR1_CTCA_SetCallBackfunc != NULL)
	{
		TIMR1_CTCA_SetCallBackfunc();
	}
}

void TIMR1_CTCA_SetCallBack(void (*Copy_pCallBackFunc) (void))	/* timer 1 compare match A call back function */
{
	if(Copy_pCallBackFunc != NULL)
	{
		TIMR1_CTCA_SetCallBackfunc = Copy_pCallBackFunc;
	}
}


void __vector_8(void) __attribute__ ((signal));
void __vector_8(void)                          /* timer 1 compare match B ISR */
{
	if(TIMR1_CTCB_SetCallBackfunc != NULL)
	{
		TIMR1_CTCB_SetCallBackfunc();
	}
}

void TIMR1_CTCB_SetCallBack(void (*Copy_pCallBackFunc) (void))	/* timer 1 compare match B call back function */
{
	if(Copy_pCallBackFunc != NULL)
	{
		TIMR1_CTCB_SetCallBackfunc = Copy_pCallBackFunc;
	}
}


void __vector_9(void) __attribute__ ((signal));
void __vector_9(void)						/* timer 1 Overflow ISR */
{
	if(TIMR1_OvF_SetCallBackfunc != NULL)
	{
		TIMR1_OvF_SetCallBackfunc();
	}
}
void TIMR1_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void))  /* timer 1 Overflow call back function  */
{
	if(Copy_pCallBackFunc != NULL)
		{
		TIMR1_OvF_SetCallBackfunc = Copy_pCallBackFunc;
		}
}
