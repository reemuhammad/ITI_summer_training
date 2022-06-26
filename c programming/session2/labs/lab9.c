#include<stdio.h>

int main()
{
	char answer=0;
	printf("Enter the answer of 3 x 4 = "); /* asks for the correct answer */
	scanf("%d",&answer);
	while(answer!=12)
	{
		printf("Not correct. Please try again: "); /*will keep asking for the answer until it is entered right */
		scanf("%d",&answer);
	}
	printf("Thank You.");
}
