/* This code takes an integer and print it
then a character and print it
then a decimal number and print it
*/
#include<stdio.h>

int integer=0;
char character=0;
float decimal=0.0;

int main(){
	printf("Enter integer value:\n");
	scanf("%d",&integer);
	printf("The integer value is: %d\n",integer);
	printf("Enter character value:\n");
	scanf(" %c",&character);     /*When using Scanf with Character, Put a Space before %c */
	printf("The character value is: %c\n",character);
	printf("Enter decimal value:\n");
	scanf("%f",&decimal);
	printf("The decimal value is: %f\n",decimal);
}