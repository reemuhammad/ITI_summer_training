#include "lib/STD_TYPES.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "util/delay.h"


int main()
{
	/* Set up LEDS */
	DIO_VidSetPortDirection(Port_C,output);
	UART_vid_Init(); /* initialized UART as configured in UART_config.h file */
	u8 data=0;
	while(1)
	{
		data =UART_u8_Receive();
		/* change LED animation based on recieved data */
		switch (data)
		{
		case '0':
			DIO_VidSetPortValue(Port_C,0xff);
			break;
		case '1':
			DIO_VidSetPortValue(Port_C,0x00);
			for(u8 i=0; i<8; i++)
			{
				DIO_VidSetPinValue(Port_C,i,high);
				_delay_ms(350);
			}
			break;
		case '2':
			DIO_VidSetPortValue(Port_C,0x00);
			for(u8 i=0; i<4; i++)
			{
				DIO_VidSetPinValue(Port_C,i,high);
				DIO_VidSetPinValue(Port_C,7-i,high);
				_delay_ms(200);
			}
			break;
		case '3':
			DIO_VidSetPortValue(Port_C,0x00);
			for(u8 i=0; i<8; i++)
			{
				DIO_VidSetPinValue(Port_C,i,high);
				_delay_ms(500);
				DIO_VidSetPinValue(Port_C,i,low);
			}
			break;
		case '4':
			DIO_VidSetPortValue(Port_C,0b10101010);
			break;
		case '5':
			DIO_VidSetPortValue(Port_C,0x00);
			for(u8 i=0; i<3; i++)
			{
				DIO_VidSetPinValue(Port_C,i,high);
			}
			break;
		case '6':
			DIO_VidSetPortValue(Port_C,0x00);
			for(u8 i=7; i>2; i--)
			{
				DIO_VidSetPinValue(Port_C,i,high);
			}
			break;
		case '7':
			for(u8 i=0; i<4; i++)
			{
			DIO_VidSetPortValue(Port_C,0xff);
			_delay_ms(100);
			DIO_VidSetPortValue(Port_C,0x00);
			_delay_ms(100);
			}
			break;
		default:
			DIO_VidSetPortValue(Port_C,0x00);
			break;
		}
	}
	return 0;
}

