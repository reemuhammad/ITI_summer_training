/* A program that takes 10 numbers and
 prints their sum and average values*/
#include<stdio.h>
int sum=0;

int main()
{
	int arr[10]={0};
	for(int i=0; i<10; i++)
	{
		printf("please enter number %d: ", (i+1));
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	printf("sum is %d \n", sum);
	printf("average is %d \n", sum/10);
	
}