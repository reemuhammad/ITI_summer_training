#include<stdio.h>
/* A code that ask the user to enter his ID and then print his name*/

int id=0;

int main()
{
	printf("Please enter your id: ");
	scanf("%d",&id);
	switch(id)
	{
		case 1234:
			printf("Welcome Ahmed");
			break;
		case 5678:
			printf("Welcome Youssef");
			break;
		case 1145:
			printf("Welcome Mina");
			break;
		default :
			printf("Wrong ID"); /* If the entered Id is not found then print that is wrong */
			break;
	}
}