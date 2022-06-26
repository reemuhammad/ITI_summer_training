/* a function that swaps 2 global variables */
#include<stdio.h>

void Swap(int no1, int no2); /* function decleration */

int x=10;
int y=20;

int main()
{
	printf("X before swap: %d \n",x);
	printf("Y before swap: %d \n \n \n",y);
	Swap(x,y);    /* function call*/
	printf("X after swap: %d \n",x);
	printf("Y after swap: %d \n",y);
}

void Swap(int no1, int no2)  /* function prototyoe */
{
	int store=0;
	store= x;
	x= y;
	y= store;
}