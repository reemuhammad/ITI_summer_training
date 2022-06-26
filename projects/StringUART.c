#include "lib/STD_TYPES.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "util/delay.h"


int main()
{
	UART_vid_Init(); /* initialized UART as configured in UART_config.h file */
	u8 data[35];	/* array for saving the string */
	while(1)
	{
		Recieve_u8_String(data); /* receive a string of characters that ends with '\r' and save it in array data */
		Send_vid_String(data);	/* send the saved string in array data */
		UART_vid_Send('\r');	/* send caariage return character to print a new line */

	}
	return 0;
}