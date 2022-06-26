/* A code to draw a pyramid of 6 rows with "*" signs */

#include<stdio.h>

int stars=1;

int main(){
	
	for( int rows=6; rows > 0; rows--)     /*The only input we need is the numbr of rows*/
	{
		for(int spaces= rows-1; spaces>0; spaces--)    /*prints the required spaces for each row*/
		{
			printf(" ");
		}
		for(int star_counter= stars; star_counter>0; star_counter--)  /*prints the stars for each row*/
		{
			printf("*");
		}
		stars= stars +2; 
		printf("\n");
	}
	
}
