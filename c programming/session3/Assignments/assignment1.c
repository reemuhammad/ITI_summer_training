/* A program to get the maximum and minimum values of four number */
#include<stdio.h>
int Get_Max_of_4();
int Get_Min_of_4();

int arr[4]={0}; /*global variable so we don't need to pass arguments to the functions*/

int main()
{	
	printf("Enter 4 values: \n");
	for(int i=0; i<4; i++)
	{
		scanf("%d",&arr[i]);   /*saving the four values in array*/
	}
	printf("The maximum number is: %d \n",Get_Max_of_4());  /* The return of the function is the value we want*/
	printf("The minimum number is: %d",Get_Min_of_4());
}

int Get_Max_of_4()
{
	int max=arr[0];  /* let the maximum value is the first element at first*/
	/* Make 3 comparisons only*/
	for(int i=1; i<4; i++)
	{
		if(arr[i]> max)
		{
			max=arr[i];
		}
	}
	return max;
}

int Get_Min_of_4()
{
	int min=arr[0];  /* let the minimum value is the first element at first*/
	/* Make 3 comparisons only*/
	for(int i=1; i<4; i++)
	{
		if(arr[i]< min)
		{
			min=arr[i];
		}
	}
	return min;
}