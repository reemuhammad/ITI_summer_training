/* A program that prints the maximum of three given numbers*/
#include<stdio.h>

int main()
{
	int n1=0, n2=0, n3=0;
	int max=0;
	
	/* entering the numbers*/
	printf("Enter number 1: ");
	scanf("%d",&n1);
	printf("Enter number 2: ");
	scanf("%d",&n2);
	printf("Enter number 3: ");
	scanf("%d",&n3);
	
	/* Checking which is bigger */
	if(n1 > n2)
	{
		if(n1 > n3)
		{
			max = n1;
		}
		else
		{
			max = n3;
		}
	}
	else if(n2 > n1)
	{
		if(n2 > n3)
		{
			max = n2;
		}
		else
		{
			max = n3;
		}
	}
	
	printf("Maximum number is %d",max); /* the result */
}