#include<stdio.h>
/* printing the factorial of a number*/
int main()
{	
	int no=1, fact=1;
	printf("Enter an integer: ");
	scanf("%d",&no);
	if(no==0)
	{
		fact=1; /* Special case factorial zero is one*/
	}
	for( int i=1; i<=no; i++)
	{
		fact*=i;
	}
	printf("Factorial= %d",fact);
}