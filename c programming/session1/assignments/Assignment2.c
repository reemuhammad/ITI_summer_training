/* A code that scans three numbers from the user 
then print them in reversed order each in a single line*/

#include<stdio.h>

char no1=0 , no2=0 , no3=0;

int main(){
	printf("Please enter number 1:");
	scanf("%d",&no1);
	printf("Please enter number 2:");
	scanf(" %c",&no2);
	printf("Please enter number 3:");
	scanf("%d",&no3);
	printf("number 3: %d\nnumber 2: %c\nnumber 3: %d",no3,no2,no1);
	/* NOTE: we can use %d or %c with number characters */
}