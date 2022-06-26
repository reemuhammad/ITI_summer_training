#include<stdio.h>
/* add 2 numbers with pointers */
int add(int* n1, int* n2); /* the arguments are pointers to the numbers*/

int main()
{
	int n1,n2;
	printf("Please Enter Value 1 : ");
	scanf("%d", &n1);
	printf("Please Enter Value 2 : ");
	scanf("%d", &n2);
	printf("The result: %d",add(&n1,&n2));
	
}

int add(int* n1, int* n2)
{
	return (*n1+*n2); /* adds the value the n1 points to with the value n2 points to */
}