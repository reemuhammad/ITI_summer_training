/* A calculator program */ 
#include<stdio.h>

/* Decleration of the operations functions */
int add();
int subtract();
int not();
int Xor();
int reminder();
int increment();

int n1=0, n2=0; /*Global variables for the two operands*/

int main()
{
	/*Printing the operations ID table*/
	printf(" Operations ID: \n");
	printf(" 1: Add \n 2: Subtract \n");
	printf(" 7: Not \n 8: Xor \n");
	printf(" 9: Reminder \n 10: Increment \n");
	
	int id=0, result=0;
	printf("Please enter operation ID: ");
	scanf("%d", &id);
	/* Calling the chosen function*/
	switch(id)
	{
		case 1:
			result=add();
			break;
		case 2:
			result=subtract();
			break;
		case 7:
			result=not();
			break;
		case 8:
			result=Xor();
			break;
		case 9:
			result=reminder();
			break;
		case 10:
			result=increment();
			break;
	}
	printf("The result is: %d",result);
	
}

/*Functions definitions*/

int add()
{
	printf("Please enter 2 operands: \n");
	scanf("%d", &n1);
	scanf("%d", &n2);
	return (n1+n2);
}
int subtract()
{
	printf("Please enter 2 operands: \n");
	scanf("%d", &n1);
	scanf("%d", &n2);
	return (n1-n2);
}
int not()
{
	printf("Please enter 1 operand: \n");
	scanf("%d", &n1);
	return (~n1);
}
int Xor()
{
	printf("Please enter 2 operands: \n");
	scanf("%d", &n1);
	scanf("%d", &n2);
	return (n1 ^ n2);
}
int reminder()
{
	printf("Please enter 2 operands: \n");
	scanf("%d", &n1);
	scanf("%d", &n2);
	return (n1%n2);
}
int increment()
{
	printf("Please enter 1 operand: \n");
	scanf("%d", &n1);
	return ++n1;
}