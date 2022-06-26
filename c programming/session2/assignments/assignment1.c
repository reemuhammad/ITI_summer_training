/* A code that takes 10 numbers from the user then ask him to enter another one
to search if it is found on the given list or not */
#include<stdio.h>

int main()
{
	int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n10=0; /*Defining 10 variables for the received numbers*/
	int search=0; /*vaiable for the value to search*/
	int place=0; 
	
	/* Scanning the numbers*/
	printf("Enter number 1: ");
	scanf("%d",&n1);
	printf("Enter number 2: ");
	scanf("%d",&n2);
	printf("Enter number 3: ");
	scanf("%d",&n3);
	printf("Enter number 4: ");
	scanf("%d",&n4);
	printf("Enter number 5: ");
	scanf("%d",&n5);
	printf("Enter number 6: ");
	scanf("%d",&n6);
	printf("Enter number 7: ");
	scanf("%d",&n7);
	printf("Enter number 8: ");
	scanf("%d",&n8);
	printf("Enter number 9: ");
	scanf("%d",&n9);
	printf("Enter number 10: ");
	scanf("%d",&n10);
	
	printf("Enter the value to search: ");
	scanf("%d",&search);
	
	/*Searching for the number*/
	if(search == n1)
	{
		place=1;
	}
	else if(search == n2)
	{
		place=2;
	}
	else if(search == n3)
	{
		place=3;
	}
	else if(search == n4)
	{
		place=4;
	}
	else if(search == n5)
	{
		place=5;
	}
	else if(search == n6)
	{
		place=6;
	}
	else if(search == n7)
	{
		place=7;
	}
	else if(search == n8)
	{
		place=8;
	}
	else if(search == n9)
	{
		place=9;
	}
	else if(search == n10)
	{
		place=10;
	}
	else 
	{
		place=0;
	}
	
	/* Printing the result*/
	if(place != 0)
	{
		printf("Value does exist at element number %d",place);
	}
	else if(place == 0)
	{
		printf("Number does not exist");
	}
	
}