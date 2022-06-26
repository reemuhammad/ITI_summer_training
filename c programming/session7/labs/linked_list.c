/* Linked list program */
#include<stdio.h>
#include"std_types.h"
#include"linked_list.h"

/* found in "linked_list.h"*/
extern u32 list_length; 
extern node * head;

void add_node(u32 value);
void print_linked_list();
void delete_node(u32 value);
void add_node_at_position(u32 value, u32 position);

void main()
{
	u8 runtime=1;
	while(runtime) /* to have infinite loop until exit is pressed */
	{				
	u32 choice;
	u32 value=0,index=0;
	/* printing the choices ID to the user */
	printf("---------------- \n"); /* a line to separate the printed screens */
	printf("To add node enter 0 \n");
	printf("To print the linked list enter 1 \n");
	printf("To exit press 2 \n");
	printf("To delete node enter 3 \n");
	printf("To add node at certain position enter 4 \n");
	printf("Your choice: ");
	scanf("%d",&choice);
	printf("---------------- \n"); /* a line to separate the printed screens */
	switch(choice)
	{
		case 0:
			printf("Please enter node value: ");
			scanf("%d",&value);
			add_node(value);
			break;
		case 1:
			print_linked_list();
			break;
		case 2:
			printf("Thank You \nGood Bye");
			runtime=0; /* close the program */
			break;
		case 3:
			printf("Please enter node value to delete: "); /* the value of the data in the node */
			scanf("%d",&value);
			delete_node(value);
			break;
		case 4:
			printf("Please enter node value: ");
			scanf("%d",&value);
			printf("Please enter node index: "); /* index starts from ( 1 ) */
			scanf("%d",&index);
			add_node_at_position(value,index);
			break;
		default:
			printf("Invalid choice. Please try again. \n"); /* choose other choice */
			break;
	}
	}
}

