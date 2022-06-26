#include<stdio.h>
#include"std_types.h"
#include"lab7.h"  /* contains functions like macro */

u32 main()
{
	u32 x=5,y=1,z=3;
	Set_Bit(x,1);  /* function like macro that set bit 1 in variable x */
	printf("x= 5 \n by setting bit 1 in x, then x= %d \n",x);
	Toggle_Bit(y,2); /* function like macro that toggle bit 2 in variable y */
	printf("y= 1 \n by toggling bit 2 in y, then y= %d \n",y);
	Clr_Bit(z,0);  /* function like macro that clear bit 0 in variable z */
	printf("z= 3 \n by clearing bit 0 in z, then z= %d",z);
}