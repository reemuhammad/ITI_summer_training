#include<stdio.h>
#include"std_types.h"

typedef struct 
{
	u16 x;
	u32 y;
	u16 z;
	u32 k;
	
}mystruct1; /* unoptimized struct */

typedef struct 
{
	u32 y;
	u16 x;   /* changing the arangement to fill every 4 bytes with variables */
	u16 z;
	u32 k;
	
}mystruct2; /* optimized struct */

u32 main()
{
	printf("Size of struct before optimization: %d bytes\n",sizeof(mystruct1));
	/* optimizing reduces the amount of memory used */
	printf("Size of struct after optimization: %d bytes\n",sizeof(mystruct2));
}