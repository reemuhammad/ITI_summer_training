#include<stdio.h>
/* bubble sort program */
void bubble_sort(int arr[10]);  /*function to bubble sort*/

int main()
{
	int arr[10]={0}; /* array of 10 elements */
	/* scanning the numbers */
	for(int i=0; i<10; i++)
	{
		printf("please enter number %d: ", (i+1));
		scanf("%d",&arr[i]);
	}
	printf("Values after sorting: \n");
	bubble_sort(arr);
	/* printing the result*/
	for(int i=0; i<10; i++)
	{
		printf("%d \n", arr[i]);
	}
}

void bubble_sort(int arr[10])
{
	for(int i=0; i<10-1; i++) /*9 iterations to sort 10 elements */
	{
		/* moving every element to its right place,
		the number of comparisons decrease every itiration*/
		for(int j=0; j<(10-i-1); j++) 
		{
			if(arr[j]> arr[j+1])
			{
				int store=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=store;
			}
			
		}
	}
}