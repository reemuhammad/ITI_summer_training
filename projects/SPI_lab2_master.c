#include "DIO_interface.h"
#include "SPI_interface.h"
#include "util/delay.h"

int main()
{
	DIO_VidSetPinDirection(Port_B,Pin_4,output);  	/* Slave Select setup */
	DIO_VidSetPinDirection(Port_B,Pin_5,output);	/* MOSI */
	DIO_VidSetPinDirection(Port_B,Pin_6,input);		/* MISO */
	DIO_VidSetPinDirection(Port_B,Pin_7,output);	/* SCK */

	DIO_VidSetPinDirection(Port_C,Pin_0,input);
	DIO_VidSetPinValue(Port_C,Pin_0,high); 			/* activate internal pull up resistor */

	SPI_Void_Init_Master(); 						/* initialize SPI as master */
	DIO_VidSetPinValue(Port_B,Pin_4,low);			/* Slave Select */

	u8 button_read=0;		/* to read the button state */
	while(1)
	{
		DIO_VidGetPinValue(Port_C,Pin_0,&button_read);
		if(button_read == low)
		{
			SPI_u8_TransmitReceive('0');
		}
		else if(button_read == high)
		{
			SPI_u8_TransmitReceive('1');
		}

		_delay_ms(250);
	}
	return 0;
}
