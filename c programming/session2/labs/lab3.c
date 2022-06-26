#include<stdio.h>
/* A code to take number and print is it even or odd*/
int main()
{
	char num=0;
	printf("Please enter number:");
	scanf("%d",&num);
	if(num%2==0)  /* if the reminder of dividing by 2 is zero then it is even number*/
	{
		printf("number is even");
	}
	else  /* if the reminder of dividing by 2 is not zero then it is an odd number*/
	{
		printf("number is odd");
	}
}