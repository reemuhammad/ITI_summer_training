/* adding 10 elements of an array by accessing it with pointer*/
#include<stdio.h>
int add_10_numbers(int * ptr); /* the only argument is a pointer to the array*/

int main()
{
	int arr[10];
	printf("Enter 10 numbers: \n");
	for(int i=0; i<10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int sum = add_10_numbers(arr); /*array name is pointer */
	printf("Summation of them = %d", sum);
}

int add_10_numbers(int * ptr) 
{
	int sum = 0;
	for(int i=0; i<10; i++)
	{
		sum+= ptr[i]; /* ptr[i] works as arr[i]*/
	}
	return sum;
}