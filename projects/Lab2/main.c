/*
 * main.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Reem Muhammad
 */

#include<avr/io.h>
#include<util/delay.h>

#define x 2
#if(x==1)
void main(void)
{
	DDRD = 0b00000011; /* set bit 0 and 1 in PORT A as OUTPUT */
	PORTD= 0b00000011; /* output HIGH on bit 0 and 1 in PORT A */
	PORTD= 0b00000011; /* output HIGH on bit 0 and 1 in PORT A */
	_delay_ms(1000);
	PORTD= 0b00000000; /* output LOW on bit 0 and 1 in PORT A */
	_delay_ms(1000);
	while(1)
	{

	}
}

#endif

#if(x==2)
void main(void)
{
	DDRD = 0b00000011; /* set bit 0 and 1 in PORT A as OUTPUT */
	PORTD= 0b00000011; /* output HIGH on bit 0 and 1 in PORT A */

	while(1)
	{
		PORTD= 0b00000011; /* output HIGH on bit 0 and 1 in PORT A */
		_delay_ms(1000);
		PORTD= 0b00000000; /* output LOW on bit 0 and 1 in PORT A */
		_delay_ms(1000);
	}
}
#endif
