#include<stdio.h>
/* a program with a function that adds and subtracts 2 numbers using pointers*/
void add(int n1, int n2, int* sum, int* sub); 

int main()
{
	int sum=0, sub=0;
	int n1,n2;
	printf("Please Enter Value 1 : ");
	scanf("%d", &n1);
	printf("Please Enter Value 2 :  ");
	scanf("%d", &n2);
	add(n1,n2,&sum,&sub);  /*give the function the 2 numbers and pointers to the sum and sub variables*/
	printf("The result of Summation is: %d \n", sum);
	printf("The result of Subtraction is: %d", sub);
}

void add(int n1, int n2, int* sum, int* sub)
{
	/* changing the value of sum and sub by accessing it through the pointers*/
	*sum= (n1+n2);
	*sub= (n1-n2);
}