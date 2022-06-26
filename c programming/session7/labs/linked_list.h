/* The file body lies between the file guard lines
 that make sure the file is defined
only 1 time if it is included many times */
#ifndef linked_list
#define linked_list

#include<stdlib.h>

struct NODE 
{
	u32 data;
	struct NODE * next; /* pointer to struct of the same type*/
};

typedef struct NODE node;
u32 list_length=0;
node * head= NULL; /* head represents the start of the list */

void add_node(u32 value)
{
	static node * ptr=NULL;
	node * new_node = (node *) malloc(sizeof(node)); /*dynamic memort allocation*/
	new_node->data= value;
	new_node->next=NULL;
	if(list_length==0)
	{
		head = new_node;
		list_length++;
	}
	else
	{
		ptr = head;
		while(ptr->next !=NULL) /* null means it reached last element*/
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
		list_length++;
	}
}

void print_linked_list()
{
	node * ptr=NULL;
	if(head==NULL)
	{
		printf("List is empty \n");
	}
	else
	{
		ptr=head;
		for(u32 counter=1; counter<=list_length; counter++)
		{
			printf("Node Number %d = ",counter);
			if(ptr != NULL) /* null means it reached last element*/
			{
				printf("%d \n",ptr->data);
				ptr=ptr->next;
			}
		}
	}
}

void delete_node(u32 value)
{
	node * ptr=NULL;
	node * temp=NULL;
	u32 flag=1; 
	if(list_length==0)
	{
		printf("list is empty \n"); /* nothing to delete */
	}
	else
	{
		ptr=head;
		while(flag)
		{
			if(ptr->data == value)
		{ 
				if(head->data==value) /* if element is found at the start*/
				{
				head=head->next;
				}
				else 
				{
				temp->next= ptr->next;
				}
			free(ptr);
			list_length--;
			flag=0; /* to exit the while loop */
		}
			else /* move to next element to check */
			{
			temp=ptr;
			ptr= ptr->next;
			}
		}
	}
	
}
void add_node_at_position(u32 value, u32 position)
{
	node * ptr=NULL, * last=NULL;
	node * new_node = (node *) malloc(sizeof(node)); /*dynamic memort allocation*/
	new_node->data= value;
	new_node->next=NULL;
	if(list_length==0)
	{
		head = new_node;
		list_length++;
	}
	else
	{
		ptr=head;
		for(u32 pos=1; pos<position; pos++)
		{
			last=ptr;
			ptr= ptr->next;
		}
		new_node->next = ptr; /* save the next postition after adding*/
		last-> next= new_node; /* add new node to list */
		list_length++;
	}
}
#endif