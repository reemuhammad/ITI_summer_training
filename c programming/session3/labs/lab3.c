#include<stdio.h>
/*A code that takes 10 numbers and store them in an array
then prints the in reversed order*/

int main()
{
	int arr[10]={0};
	for(int i=0; i<10; i++)
	{
		printf("please enter number %d: ", (i+1));
		scanf("%d",&arr[i]);
	}
	printf("Values in reversed order: \n"); /* By changing the start value and the condition in the loop*/
		for(int i=9; i>=0; i--)
	{
		printf("%d \n", arr[i]);
	}
	
}