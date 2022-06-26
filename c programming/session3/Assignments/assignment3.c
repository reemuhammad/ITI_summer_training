/* Finding the maximum and minimum of 10 values*/
#include<stdio.h>

int main()
{
	int arr[10]={0};
	printf("please enter number 1: \n");
	scanf("%d",&arr[0]);
	/* let the maximum and minimum values be the first element at first
	 ---- I didn't assign them to zero so that the code works in case the user entered
	negative numbers */
	int max=arr[0]; 
	int min=arr[0]; 
	
	for(int i=1; i<10; i++)
	{
		printf("please enter number %d: \n",(i+1));
		scanf("%d",&arr[i]);
		if(arr[i]> max)
		{
			max=arr[i];
		}
		if(arr[i]< min)
		{
			min=arr[i];
		}
	}
	printf("The maximum number is: %d \n", max);  
	printf("The minimum number is: %d", min);
}

