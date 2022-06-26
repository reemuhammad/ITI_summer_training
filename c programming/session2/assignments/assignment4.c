/*A non-ending program that calculates the summation of two numbers*/
#include<stdio.h>

int main()
{
	int n1=0, n2=0;
	while(1) /* The condition is always a true value so it is an infinte loop*/
	{
		printf("Please enter first number ");
		scanf("%d",&n1);
		printf("Please enter second number ");
		scanf("%d",&n2);
		printf("The result is %d \n",(n1+n2));
	}
}