#include "DIO_interface.h"
#include "SPI_interface.h"
#include "util/delay.h"

int main()
{
	DIO_VidSetPinDirection(Port_B,Pin_3,output); 	/* Slave Select 1 */
	DIO_VidSetPinDirection(Port_B,Pin_4,output);  	/* Slave Select 2 */
	DIO_VidSetPinDirection(Port_B,Pin_5,output);	/* MOSI */
	DIO_VidSetPinDirection(Port_B,Pin_6,input);		/* MISO */
	DIO_VidSetPinDirection(Port_B,Pin_7,output);	/* SCK */

	SPI_Void_Init_Master(); 						/* initialize SPI as master */
	while(1)
	{
		/* Select slave 2 */
		DIO_VidSetPinValue(Port_B,Pin_3,high);
		DIO_VidSetPinValue(Port_B,Pin_4,low);
		SPI_u8_TransmitReceive(0x24);
		_delay_ms(800);
		/* Select slave 1 */
		DIO_VidSetPinValue(Port_B,Pin_4,high);
		DIO_VidSetPinValue(Port_B,Pin_3,low);
		SPI_u8_TransmitReceive(0x4C);
		_delay_ms(800);
	}
	return 0;
}
