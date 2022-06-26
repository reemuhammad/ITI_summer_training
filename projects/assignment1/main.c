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
	/* using 2 common cathode 7-segments  */
	/* the left 7-segment */
	DDRD=0b01111111; /* hardware connection is: from A to G on PORT D from pin 0 to 6 */
	PORTD=0b00000000; /* no output at the start */
	/* the right 7-segment */
	DDRC=0b01111111; /* hardware connection is: from A to G on PORT C from pin 0 to 6 */
	PORTC=0b00000000; /* no output at the start */

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

	/* Leds setup */
	for(u32 pin=0; pin<3; pin++)
	{
		Set_Bit(DDRA,pin); /* set led as output */
		Clr_Bit(PORTA,pin); /* turn off at the start */
	}

  while(1)
  {
	  Set_Bit(PORTA,2); /* turn on green led */
	  /* displaying number 10 at first */
	  PORTD=seven_segment[1];
	  PORTC=seven_segment[0];
	  _delay_ms(1000); /* wait for 1 second */
	  	 for(u32 counter=9; counter>0; counter--)
	  	 {
	  		 PORTD=seven_segment[0]; /* write 0 on the left 7-segment */
	  		 PORTC=seven_segment[counter]; /* display the number on the right 7-segment */
	  		 _delay_ms(1000); /* wait for 1 second */
	  	 }
	  Clr_Bit(PORTA,2); /* turn off after 10 seconds */

	  Set_Bit(PORTA,1); /* turn on yellow led */
	  for(u32 counter=3; counter>0; counter--)
	  	  	 {
	  	  		 PORTD=seven_segment[0]; /* write 0 on the left 7-segment */
	  	  		 PORTC=seven_segment[counter]; /* display the number on the right 7-segment */
	  	  		 _delay_ms(1000); /* wait for 1 second */
	  	  	 }
	  Clr_Bit(PORTA,1); /* turn off after 10 seconds */

	  Set_Bit(PORTA,0); /* turn on red led */
	  /* displaying number 10 at first */
	  	  PORTD=seven_segment[1];
	  	  PORTC=seven_segment[0];
	  	  _delay_ms(1000); /* wait for 1 second */
	  	  	 for(u32 counter=9; counter>0; counter--)
	  	  	 {
	  	  		 PORTD=seven_segment[0]; /* write 0 on the left 7-segment */
	  	  		 PORTC=seven_segment[counter]; /* display the number on the right 7-segment */
	  	  		 _delay_ms(1000); /* wait for 1 second */
	  	  	 }
	  Clr_Bit(PORTA,0); /* turn off after 10 seconds */


  }
}
