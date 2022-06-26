
#include "lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "Timer_private.h"
#include "Timer_interface.h"
#include "CLCD_INTERFACE.h"
#include "CLCD_config.h"
#include "util/delay.h"
#include "Timer_config.h"
#include "GIE_interface.h"


/* functions to convert integer to string */
void reverse(u8* str, u16 len);
u16 intToStr(u16 Copy_u16_IntegerNumber, u8 Copy_StringArray[], u16 Copy_NumberOfDigits);


u16 Global_Period=0, Global_Ontime=0;
void Capture_Signal()
{

	static u16 local_u16first_capture =0, local_u16second_capture =0, local_u16third_capture =0;
	static u8 local_u8interrupt_counter =1;

	if(local_u8interrupt_counter == 1 )
	{
		local_u16first_capture =  GetCaptureUnit();
		/* set ICU interrupt on falling edge for next time */
		Timer_vid_Interrupt(timer1,Input_Capture_Int,Enable_falling_edge_trigger); 
		local_u8interrupt_counter++ ;
	}
	else if(local_u8interrupt_counter == 2 )
	{
		local_u16second_capture =  GetCaptureUnit();
		/* Prescaler is 8, and MC frequncy = 8000000, we print the time in Milli Seconds*/
		Global_Ontime = ((local_u16second_capture - local_u16first_capture)* 8)/8000;
		/* set ICU interrupt on rising edge for next time */
		Timer_vid_Interrupt(timer1,Input_Capture_Int,Enable_rising_edge_trigger);
		local_u8interrupt_counter++ ;
	}
	else if(local_u8interrupt_counter == 3)
	{
		local_u16third_capture = GetCaptureUnit();
		/* Prescaler is 8, and MC frequncy = 8000000, we print the time in Milli Seconds*/
		Global_Period = ((local_u16third_capture - local_u16first_capture)*8)/8000;;
		/* Disable ICU interrupt */
		Timer_vid_Interrupt(timer1,Input_Capture_Int,Disable);
		local_u8interrupt_counter=1 ;

	}


}
int main(){

	/* set LCD pins as output */
	DIO_VidSetPortDirection(CLCD_DATA_PORT,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_E_PIN,output);
	/* strings for printing the Period and OnTime on LCD */
	u8 stringArrayPeriod[30];
	u8 stringArrayOntime[30];
	/* set the ISR of ICU INT with Capture_Signal() function */
	TIMR1_ICU_SetCallBack(Capture_Signal);
	/* initialize LCD as configured in the configuration file */
	CLCD_VidInit();
	/* set ICU interrupt settings: rising edge is the trigger at first */
	Timer_vid_Interrupt(timer1,Input_Capture_Int,Enable_rising_edge_trigger);
	/* initialize Timer 1 in normal mode */
	Timer1_16bit_vid_Init(Normal,UnitA_Normal_port_operation);
	/* enable the SREG pin to enable global interrupts */
	GIE_Vid_Enable();
	/* texts that will be printed on LCD */
	u8 arrText1[]="Period=";
	u8 arrText2[]="OnTime=";
	u8 arrText3[]=" ms";
	while(1)
	{
		/* print the period in milli seconds on the first line */
		CLCD_VidGoToXY(0,0);
		CLCD_VidWriteString(arrText1);
		intToStr(Global_Period,stringArrayPeriod,5);
		CLCD_VidWriteString(stringArrayPeriod);
		CLCD_VidWriteString(arrText3);
		/* print the OnTime in milli seconds on the second line */
		CLCD_VidGoToXY(1,0);
		CLCD_VidWriteString(arrText2);
		intToStr(Global_Ontime,stringArrayOntime,5);
		CLCD_VidWriteString(stringArrayOntime);
		CLCD_VidWriteString(arrText3);
		_delay_ms(1000);
		/* Clear LCD screen */
		CLCD_VidSendCommand(1);

	}
	return 0;
}

/* function that reverse elements of string */
void reverse(u8* Copy_StringArray, u16 Copy_StringLength)
{
	u8 i = 0, j = (Copy_StringLength - 1) , temp;
	while (i < j) {
		temp = Copy_StringArray[i];
		Copy_StringArray[i] = Copy_StringArray[j];
		Copy_StringArray[j] = temp;
		i++;
		j--;
	}
}

/* function that converts an integer number to string */
u16 intToStr(u16 Copy_u16_IntegerNumber, u8 Copy_StringArray[], u16 Copy_NumberOfDigits)
{
	u16 i = 0;
	while (Copy_u16_IntegerNumber) {
		Copy_StringArray[i++] = (Copy_u16_IntegerNumber % 10) + '0';
		Copy_u16_IntegerNumber = Copy_u16_IntegerNumber / 10;
	}

	/* If number of digits required is more, then
	 add 0s at the beginning */
	while (i < Copy_NumberOfDigits)
		Copy_StringArray[i++] = '0';

	reverse(Copy_StringArray, i);
	Copy_StringArray[i] = '\0';
	return i;
}
