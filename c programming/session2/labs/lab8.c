#include<stdio.h>
/* finding the sum and average of 10 given numbers
by the user */
int main()
{
	printf("Enter the 10 numbers \n");
	int sum=0;
	int no=0;
	for(int i=1; i<=10; i++)
	{
		scanf("%d",&no);
		sum+= no;
	}
	printf("sum is: %d\n", sum);
	printf("average is: %d", sum/10);
}