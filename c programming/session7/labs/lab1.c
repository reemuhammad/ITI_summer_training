#include<stdio.h>
#include<stdlib.h>
#include"std_types.h"
void bubble_sort( u32 *ptr );  /*function to bubble sort*/

u32 size;
void main()
{
	u32 * ptr=NULL ;  /* to avoid wild pointer problem */
	printf("enter no. of elements: ");
	scanf("%d",&size);
	/* dynamic memory allocation, casting the return of malloc (void pointer)
	to type (u32 *), argument of malloc is number of bytes */
	ptr= (u32 *) malloc(size*4);  
	for(u32 i=0; i<size; i++)
	{
		printf("please enter number %d: ", (i+1));
		scanf("%d",&ptr[i]); /*the pointer acts in the same way we acess array*/
	}
	printf("Values after sorting: \n");
	bubble_sort(ptr);
	/* printing the result*/
	for(u32 i=0; i<size; i++)
	{
		printf("%d \n", ptr[i]);
	}
	
}

void bubble_sort( u32 *ptr )
{
	for(u32 i=0; i<size-1; i++) /*9 iterations to sort 10 elements */
	{
		/* moving every element to its right place,
		the number of comparisons decrease every itiration*/
		for(u32 j=0; j<(size-i-1); j++) 
		{
			if(ptr[j]> ptr[j+1])
			{
				u32 store=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=store;
			}
			
		}
	}
}