/*A program that draw a pyramid of stars with height entered by the user*/
#include<stdio.h>

int stars=1;

int main()
{
	int rows=0;
	printf("Please enter the height of the pyramid: ");
	scanf("%d",&rows);
	
	for( ; rows > 0; rows--)  
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