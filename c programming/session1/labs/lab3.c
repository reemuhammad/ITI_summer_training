/* Performing operations on two given numbers from the user*/
#include<stdio.h>

int a=0, b=0;  /*variables for the two numbers*/

int main(){
	printf("Enter number 1:\n");
	scanf("%d",&a);
	printf("Enter number 2:\n");
	scanf("%d",&b);
	printf("no.1 + no.2 = %d\n", a+b);
	printf("no.1 - no.2 = %d\n", a-b);
	printf("no.1 * no.2 = %d\n", a*b);
	printf("no.1 / no.2 = %d\n", a/b);
	printf("no.1 %% no.2 = %d\n", a%b); /*NOTE: to print "%" we must write %% */
	printf("no.1++ = %d\n", a++);  /* print a then add 1*/
	printf("--no.2 = %d\n", --b);  /* subtract 1 from b then print it*/
}