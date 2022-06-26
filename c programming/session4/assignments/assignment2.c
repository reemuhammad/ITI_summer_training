#include<stdio.h>

int main()
{
	int x=2, y=4, z=6; /* setting 3 variables */
	/* setting pointers to the 3 variables*/
	int *p=&x;
	int *q=&y;
	int *r=&z;
	/* printing the values of the variables and the pointers  */
	printf("x = %d \n y = %d \n z = %d \n",x,y,z);
	printf("p = %d \n q = %d \n r = %d \n",p,q,r);
	printf("*p = %d \n *q = %d \n *r = %d \n",*p,*q,*r);
	/*swapping the pointers*/
	printf("Swapping pointers: ");
	int *store = r;
	r = p;
	p = q;
	q = store;
	/* printing the result */
	printf("x = %d \n y = %d \n z = %d \n",x,y,z);
	printf("p = %d \n q = %d \n r = %d \n",p,q,r);
	printf("*p = %d \n *q = %d \n *r = %d \n",*p,*q,*r);
}