#include<stdio.h>
/* using pointer to change a value of variable*/

int main()
{
	int x=10;
	printf("X before change is %d \n",x); 
	int *ptr=&x; /*defining a pointer */
	*ptr=20;
	printf("X after change is %d",x);
}