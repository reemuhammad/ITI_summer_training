#include<stdio.h>
/* Ask the user to enter 10 numbers and 
to choose a value to searh in them
and the code will tell if it esixts or not and how many times*/

int main()
{
	int arr[10]={0};
	int counter=0, search=0;
	/*getting the 10 numbers */
	for(int i=0; i<10; i++)
	{
		printf("please enter number %d: ", (i+1));
		scanf("%d",&arr[i]);
	}
	printf("Enter value to search: ");
	scanf("%d",&search);
	
	/* linear search*/
	for(int i=0; i<10; i++)
	{
		if(arr[i]==search)
		{
			counter++;
		}
	}
	/* the result */
	if(counter==0)
	{
		printf("Value does not exist");
	}
	else
	{
		printf("Value exists %d times", counter);
	}
}