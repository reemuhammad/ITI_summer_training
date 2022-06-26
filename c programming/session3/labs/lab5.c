/* A program that makes the user choose number of elements 
and enter the elements in any order and the program will 
sort them */
#include<stdio.h>

int main()
{
	int arr[10]={0};   /* The number of given elements should be less than 10*/
	int num=0;
	printf("please enter the number of elements: ");
	scanf("%d",&num);
	/* scanning the numbers */
	for(int i=0; i<num; i++)
	{
		printf("please enter number %d: ", (i+1));
		scanf("%d",&arr[i]);
	}
	
	printf("Values after sorting: \n");
	/* Bubble sort */
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<(num-i-1); j++)
		{
			if(arr[j]> arr[j+1])
			{
				int store=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=store;
			}
			
		}
	}
	/* printing the result*/
	for(int i=0; i<num; i++)
	{
		printf("%d \n", arr[i]);
	}
}