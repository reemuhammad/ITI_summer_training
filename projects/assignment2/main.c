/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: DELL
 */


#include<avr/io.h>
#include<util/delay.h>
#include"bit_math.h"
#include"std_types.h"

void main(void)
{
	u32 led2=0;
	DDRD=0b11111111;
	DDRA=0b00000000;
	PORTD=0b00000000;
	while(1)
	{
	u32 button= PINA;
	switch(button)
	{
	case 0b00000000:
			PORTD=0b11111111;
			_delay_ms(500);
			PORTD=0b00000000;
			_delay_ms(500);
			break;
	case 0b00000001:
			for(u32 led=0; led<8; led++)
			{
				Set_Bit(PORTD,led);
				_delay_ms(250);
				Clr_Bit(PORTD,led);
			}
			PORTD=0b00000000;
			break;
	case 0b00000010:
			for(s32 led=7; led>=0; led--)
			{
			Set_Bit(PORTD,led);
			_delay_ms(250);
			Clr_Bit(PORTD,led);
			}
			break;
	case 0b00000011:
		led2=7;
		for(u32 led=0; led<4; led++)
		{
		Set_Bit(PORTD,led);
		Set_Bit(PORTD,led2);
		_delay_ms(300);
		Clr_Bit(PORTD,led);
		Clr_Bit(PORTD,led2);
		led2--;
		}
		break;
	case 0b00000100:
		led2=3;
			for(u32 led=4; led<8; led++)
			{
			Set_Bit(PORTD,led);
			Set_Bit(PORTD,led2);
			_delay_ms(300);
			Clr_Bit(PORTD,led);
			Clr_Bit(PORTD,led2);
			led2--;
			}
			break;
	case 0b00000101:

		for(u32 led=0; led<8; led++)
					{
						Set_Bit(PORTD,led);
						_delay_ms(250);
					}
		PORTD=0b00000000;
		break;
	case 0b00000110:
		for(u32 led=0; led<8; led++)
					{
						Set_Bit(PORTD,led);
						_delay_ms(250);
						Clr_Bit(PORTD,led);
					}
					break;
	case 0b00000111:

				for(u32 led=0,led2=7; led<3; led++)
				{
				Set_Bit(PORTD,led);
				Set_Bit(PORTD,led2);
				_delay_ms(300);
				Clr_Bit(PORTD,led);
				Clr_Bit(PORTD,led2);
				led2--;
				}
				u32 led2=3;
				for(u32 led=4; led<8; led++)
				{
				Set_Bit(PORTD,led);
				Set_Bit(PORTD,led2);
				_delay_ms(300);
				Clr_Bit(PORTD,led);
				Clr_Bit(PORTD,led2);
				led2--;
				}
				break;
	}
	}
}

