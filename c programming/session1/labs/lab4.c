#include<stdio.h>

/* a code that performs Bitwise operations on numbers 7 and 4 */
int main(){
	char x=7, y=4;
	printf("z= x & y= %d\n",x&y ); /* ANDD */
	printf("k= x | y= %d\n",x|y ); /* OR */
	printf("m= x ^ y= %d\n",x^y ); /* XOR */
	printf("L= x>>1= %d\n",x>>1 ); /*right shift operator*/
	printf("N= y<<2= %d\n",y<<2);  /*left shift operator*/
}