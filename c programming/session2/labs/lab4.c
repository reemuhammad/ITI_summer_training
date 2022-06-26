#include<stdio.h>
/* Takes the grade and print the rating*/
char grade=0;

int main()
{
	printf("Please enter number: ");
	scanf("%d",&grade);
	
	/* Finfing the rating depending on the range 
	that the grade lies in*/
	
	if(grade <50)
	{
		printf("Your rating is failed");
	}
	else if(grade <65)
	{
		printf("Your rating is Normal");
	}
	else if(grade <75)
	{
		printf("Your rating is Good");
	}
	else if(grade <85)
	{
		printf("Your rating is Very Good");
	}
	else
	{
		printf("Your rating is Excellent");
	}
}