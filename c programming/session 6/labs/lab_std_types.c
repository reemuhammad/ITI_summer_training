#include<stdio.h>
#include"std_types.h"

/* entry point */
int main()
{
	/* using function sizeof() which returns no. of bytes */
 printf("size of unsigned char: %d bytes \n", sizeof(u8));
 printf("size of unsigned short int: %d bytes \n", sizeof(u16));
 printf("size of unsigned long int: %d bytes \n", sizeof(u32));
 printf("size of signed char: %d bytes \n", sizeof(s8));
 printf("size of signed short int: %d bytes \n", sizeof(s16));
 printf("size of signed long int: %d bytes \n", sizeof(s32));
 printf("size of float: %d bytes \n", sizeof(f32));
 printf("size of double: %d bytes \n", sizeof(f64));
 
}