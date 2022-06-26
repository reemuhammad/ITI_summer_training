/*
 * main.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Reem
 */

#include<avr/io.h>
#include<util/delay.h>
#include"bit_math.h"
#include"std_types.h"

#define x 1
#if(x==1)

void main()
{
	DDRD=0b11111111;
	PORTD= 0b00000000;
	while(1)
	{
		for(u32 bit_counter=0 ; bit_counter<8; bit_counter++ )
		{
			PORTD= 0b00000000;
			_delay_ms(500);
			Set_Bit(PORTD,bit_counter);
			_delay_ms(500);
		}
		for(u32 bit_counter=7 ; bit_counter>=0; bit_counter-- )
		{
			PORTD= 0b00000000;
			_delay_ms(500);
			Set_Bit(PORTD,bit_counter);
			_delay_ms(500);
		}
	}
}
#endif

#if(x==2)
void main()
{
	Set_Bit(PORTA,0);
	DDRD=0b11111111;
	PORTD= 0b00000000;
	while(1)
	{
		if(PINA == 0b00000001)
		{
			PORTD= 255;
		}
		else if(PINA == 0b00000000)
				{
					PORTD= 0;
				}
	}
}
#endif
