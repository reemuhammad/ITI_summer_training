#include "lib/STD_TYPES.h"
#include "UART_interface.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "util/delay.h"
/* functions to concert integer to string */
void reverse(u8* str, u16 len);
u16 intToStr(u16 Copy_u16_IntegerNumber, u8 Copy_StringArray[], u16 Copy_NumberOfDigits);

int main()
{
	ADC_vid_Init(); /* Initialize ADC */
	UART_vid_Init();	/* initialized UART as configured in UART_config.h file */
	u16 local_u16_read=0;
	u8 local_arr_string[25];
	u8 mv[]="Millivolt = ";

	while(1)
	{
		Send_vid_String(mv); /* print "Millivolt = " every new line */
		local_u16_read= ADC_u8ReadChannel(ADC_0);
		intToStr(local_u16_read, local_arr_string, 4);
		Send_vid_String( local_arr_string );
		UART_vid_Send('\r');
		_delay_ms(500);

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

