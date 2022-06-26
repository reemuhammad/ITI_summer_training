#include<stdio.h>
/* a code to calculate the worker salary*/
int hours=0;
int salary=0;

int main()
{	
	printf("Please enter your working hours:");
	scanf("%d",&hours);
	salary=hours*50; /*every working hour worth 50 pounds */
	/*If the worker works less than 40 hours the salary will decreased*/
	if(hours<40) 
	{
		salary-= 0.1*salary;	
	}
	printf("your salary is: %d",salary); /* the result */
}