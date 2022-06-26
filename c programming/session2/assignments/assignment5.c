/*A program to check the ID and password of a person, with maximum
number of three tries for entering the correct password*/

#include<stdio.h>

int main()
{
	int id=0,pass=0;
	printf("Please Enter your ID: ");
	scanf("%d",&id);
	
	/* Check if the ID exists in the database*/
	if(id == 1234)
	{
		printf("Please Enter Password: ");
		for(int try=0; try<3; try++)
		{
			scanf("%d",&pass);
			if(pass == 7788)
			{
				printf("Welcome Ahmed");  
				try=3; /*If the password is correct exists the loop and end program*/
			}
			else
			{
				printf("Try again: "); /*giving the user three chances*/
			}
		}
		if(pass != 7788)
		{
			printf("Incorrect password for 3 times. No more tries");
		}
	}
	else if(id == 5678)
	{
		printf("Please Enter Password: ");
		for(int try=0; try<3; try++)
		{
			scanf("%d",&pass);
			if(pass == 5566)
			{
				printf("Welcome Amr");
				try=3; /*If the password is correct exists the loop and end program*/
			}
			else
			{
				printf("Try again: "); /*giving the user three chances*/
			}
		}
		if(pass != 5566)
		{
			printf("Incorrect password for 3 times. No more tries");
		}
	}
	else if(id == 9870)
	{
		printf("Please Enter Password: ");
		for(int try=0; try<3; try++)
		{
			scanf("%d",&pass);
			if(pass == 1122)
			{
				printf("Welcome Wael");
				try=3; /*If the password is correct exists the loop and end program*/
			}
			else
			{
				printf("Try again: "); /*giving the user three chances*/
			}
		}
		if(pass != 1122)
		{
			printf("Incorrect password for 3 times. No more tries");
		}
	}
	else
	{
		printf("You are not registered"); /* ID is not found */
	}
	
}