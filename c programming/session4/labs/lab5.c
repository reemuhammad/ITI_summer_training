/* a program to apply scalar multiplication 
on two arrays*/
#include<stdio.h>
int scalar_multiplication(int * ptr1, int * ptr2);

int main()
{
	int arr1[10]={0};
	int arr2[10]={0};
	/* getting the elements of the two arrays from the user */
	printf("Enter first array 10 elements: \n");
	for(int i=0; i<10; i++)
	{
		scanf("%d", &arr1[i]);
	}
	printf("Enter second array 10 elements: \n");
	for(int i=0; i<10; i++)
	{
		scanf("%d", &arr2[i]);
	}
	/* multiply and print the result */
	int result= scalar_multiplication(arr1, arr2); /*the array name is a pointer*/
	printf("The scalar multiplication of two arrays= %d", result);
}

int scalar_multiplication(int * ptr1, int * ptr2)
{
	int result=0;
	for(int i=0; i<10; i++)
	{
		result+= ptr1[i] * ptr2[i];  /* we can access the array by this format of pointers*/
	}
	return result;
}