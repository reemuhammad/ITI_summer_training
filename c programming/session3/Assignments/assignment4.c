#include<stdio.h>
/* A program that calculates the statistics of three classes*/
int no_passed(int arr[]); /*returns the number of students who passed*/
int no_failed(int arr[]); /*returns number of students who failed : got lower than grade:50*/
int highest_grade(int arr[]);
int lowest_grade(int arr[]);
int average_grade(int arr[]);

/* Grades of three classes*/
int class1[10]={100,90,47,75,76,73,62,84,88,94};
int class2[10]={70,48,49,93,67,68,98,86,83,77};
int class3[10]={58,42,67,96,85,75,93,83,88,81};

int main()
{
	printf("School statistics: \n");
	/* printing every operation for the three classes*/
	printf("Number of students who passed: \n");
	printf("In class 1: %d \n", no_passed(class1));
	printf("In class 2: %d \n", no_passed(class2));
	printf("In class 3: %d \n \n", no_passed(class3));
	
	printf("Number of students who failed: \n");
	printf("In class 1: %d \n", no_failed(class1));
	printf("In class 2: %d \n", no_failed(class2));
	printf("In class 3: %d \n \n", no_failed(class3));
	
	printf("Highest grade: \n");
	printf("In class 1: %d \n", highest_grade(class1));
	printf("In class 2: %d \n", highest_grade(class2));
	printf("In class 3: %d \n \n", highest_grade(class3));
	
	printf("lowest grade: \n");
	printf("In class 1: %d \n", lowest_grade(class1));
	printf("In class 2: %d \n", lowest_grade(class2));
	printf("In class 3: %d \n \n", lowest_grade(class3));
	
	printf("average grade: \n");
	printf("In class 1: %d \n", average_grade(class1));
	printf("In class 2: %d \n", average_grade(class2));
	printf("In class 3: %d \n", average_grade(class3));
}

/*Functions defintions */
int no_passed(int arr[])
{
	int pass=0;
	for(int i=0; i<10; i++)
	{
		if(arr[i]>50)
		{
			pass++;
		}
	}
	return pass;
}

int no_failed(int arr[])
{
	return (10-no_passed(arr));  /* subtract the passed number from 10 */
}

int highest_grade(int arr[])
{
	int max=0;
	for(int i=0; i<10; i++)
	{
		if(arr[i]> max)
		{
			max=arr[i];
		}
	}
	return max;
}

int lowest_grade(int arr[])
{
	int min=100;
	for(int i=0; i<10; i++)
	{
	if(arr[i]< min)
		{
			min=arr[i];
		}
	}
	return min;
}

int average_grade(int arr[])
{
	int sum=0,average=0;
	for(int i=0; i<10; i++)
	{
		sum+=arr[i];
	}
	average=sum/10;
	return average;
}