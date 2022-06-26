/* Displaying numbers on seven segment
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Reem
 */

#include<avr/io.h>
#include<util/delay.h>
#include"bit_math.h"
#include"std_types.h"

void main(void)
{
	/* using a common cathode 7-segment  */
	DDRD=0b01111111; /* hardware connection is: from A to G on PORT D from pin 0 to 6 */
	PORTD=0b00000000; /* no output at the start */
	u32 seven_segment[10]=   /* array for the table of displaying numbers on 7-segment */
	{
			0b00111111,
			0b00000110,
			0b01011011,
			0b01001111,
			0b01100110,
			0b01101101,
			0b01111101,
			0b00000111,
			0b01111111,
			0b01101111
	};

  while(1)
  {
	  	 for(u32 counter=0; counter<10; counter++)
	  	 {
	  		 PORTD=seven_segment[counter]; /* display the number on connecting to PORT D */
	  		 _delay_ms(1000); /* wait for 1 second */
	  	 }
  }
}
