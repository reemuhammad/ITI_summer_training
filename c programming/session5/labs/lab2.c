/* session 5: lab 2 */
/* printing the size of different data types*/
#include<stdio.h>

int main()
{
	/* using function sizeof() which returns no. of bytes */
 printf("size of unsigned int: %d bytes \n", sizeof(unsigned int));
 printf("size of signed int: %d bytes \n", sizeof(signed int));
 printf("size of unsigned char: %d bytes \n", sizeof(unsigned char));
 printf("size of signed char: %d bytes \n", sizeof(signed char));
 printf("size of double: %d bytes \n", sizeof(double));
 printf("size of float: %d bytes \n", sizeof(float));
 printf("size of long double: %d bytes \n", sizeof(long double));
 printf("size of short int: %d bytes \n", sizeof(short int));
 printf("size of long int: %d bytes \n", sizeof(long int));
 
  /*Note: there is NO long float , short comes with int only */
}