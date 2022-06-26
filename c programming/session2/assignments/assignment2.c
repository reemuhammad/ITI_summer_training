/* A program to check the ID and passwords*/
#include<stdio.h>

int main()
{
	int id=0,pass=0;
	printf("Enter your id: ");
	scanf("%d",&id);
	/* Checking if the ID exists in the database*/
	if(id == 1234)
	{
		printf("Enter your password: ");
		scanf("%d",&pass);
		if(pass == 1111)
		{
			printf("Welcome Ahmed"); /*Printing the name of the person*/
		}
		else
		{
			printf("Incorrect Password");
		}
	}
	else if(id == 5678)
	{
		printf("Enter your password: ");
		scanf("%d",&pass);
		if(pass == 2222)
		{
			printf("Welcome Youssef");
		}
		else
		{
			printf("Incorrect Password");
		}
	}
	else if(id == 1145)
	{
		printf("Enter your password: ");
		scanf("%d",&pass);
		if(pass == 3333)
		{
			printf("Welcome Mina");
		}
		else
		{
			printf("Incorrect Password");
		}
	}
	else
	{
		printf("Incorrect ID"); /*If the id does not exist in the database*/
	}
}
