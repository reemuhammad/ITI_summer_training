#include<stdio.h>
#include"std_types.h"

/* global struct seen by the function prototype */
typedef struct grades  /* typedef allows defing a new struvt by only writing "student" */
{
	u32 math;
	u32 language;
	u32 physics;
	u32 chemistry;
	
}student; /* to save the grades of each student */

void show_grades(u32 id, student arr[10]); /* prints the grades of one student*/

u32 main()
{
	student class[10]={{10,30,40,41},{50,45,45,30},{42,39,36,41},
	{28,32,35,29},{50,49,48,50},{43,44,48,47},
	{50,48,46,47},{50,48,45,47},{29,35,32,38},{50,50,49,50}
	}; /* array of type struct for the grades of a class of 10 students */
	
	u32 id;
	printf("Please enter student ID: ");
	scanf(" %d", &id);
	/* IDs are numbered from 0 to 9 for the 10 students */
	if( (id>9) || (id<0) )
	{
		printf("Student ID is not correct");
	}
	else
	{
		show_grades(id,class);
	}
	
}

void show_grades(u32 id, student arr[10])
{
	/* accessing struct elements in an array */
	printf("Math grade: %d \n", arr[id].math);
	printf("Language grade: %d \n", arr[id].language);
	printf("Physics grade: %d \n", arr[id].physics);
	printf("Chemistry grade: %d \n", arr[id].chemistry);
}