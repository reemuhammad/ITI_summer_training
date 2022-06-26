#include<stdio.h>
/*A code that takes two numbers and print the maximum value */
int Get_Max(int no1, int no2); /* function decleration */

int no1=0, no2=0, max=0; 

int main()
{
	printf("Please enter value 1: ");
	scanf("%d",&no1);
	printf("Please enter value 2: ");
	scanf("%d",&no2);
	max = Get_Max(no1,no2);  /* call function and save its return value*/
	printf("Result is: %d",max);
}

int Get_Max(int no1, int no2)  /* function prototyoe */
{
	if(no1 > no2)
	{
		max=no1;
	}
	else if(no1 < no2)
	{
		max=no2;
	}
	return max;
}