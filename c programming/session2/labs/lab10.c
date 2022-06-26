#include<stdio.h>
/* printing the multiplication table of a number*/
int main()
{
	char no =0;
	printf("Enter the number to display the multiplication table: ");
	scanf("%d",&no);
	for(int i=1; i<=12; i++)
	{
		printf("%d X %d = %d \n",no,i,(no*i));
	}
	
}