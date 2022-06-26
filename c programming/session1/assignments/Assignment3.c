/*
A code that that takes two numbers and print their summation, subtraction,
anding, oring & Xoring
*/
#include<stdio.h>

char a=0 , b=0;

int main(){
	printf("Please enter number a: ");  
	scanf("%d",&a); /*Note: scanf moves the cursor to a new line after scanning directly*/
	printf("Please enter number b: ");
	scanf("%d",&b);
	printf("a + b = %d \n",a+b);
	printf("a - b = %d \n",a-b);
	printf("a & b = %d \n",a&b);  /* AND */
	printf("a | b = %d \n",a|b);  /* OR  */
	printf("a ^ b = %d \n",a^b);  /* XOR */
}