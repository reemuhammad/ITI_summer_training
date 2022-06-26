/* a test code to make intermediate (.i)
assembly (.asm) , object (.o) & executable (.exe) files*/

#include<stdio.h>
#include"std_types.h"

u32 main() /* entry point is the main function of type int: 32 bytes*/
{
	printf("My name is Reem Muhammad");
	
}

/* 	
	write in cmd command: 
		objdump -D lab5.o 
	to open the object file 
	
	write lab5.i or lab5.asm in cmd 
	open them with notepad 
	to open intermediate or assembly files
*/