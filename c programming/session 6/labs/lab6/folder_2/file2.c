#include<stdio.h>

/* every  ../  opens the previos folder */
#include"../../std_types.h"      /* moves to 2 previos folders */
#include"../file1.h"             /* moves to the previos folder */

#include"folder_3/file3.h"		 /* moves to the next folder */


u32 main()
{
	printf("x = %d \n", x);
	printf("y = %d \n", y);
}