#include <stdio.h>
#include "std_types.h"
#include "clinic_management_system.h"
#include<stdlib.h>
/* ------------------CMS: CLINIC MANAGEMENT SYSTEM------------------ */

/* Global variables */

new_patient * head= NULL; /* head represents the start of the list */
u32 reservations[5]={empty,empty,empty,empty,empty}; /* for saving appointments */



void main()
{
	u32 Local_u32Mode=0;
	/* Choose either Admin or User mode */
	while(Local_u32Mode != 3) /* keeps running until "Exit program" is chosen */
	{
	printf("Please choose a mode: \n 1) Admin mode \n 2) User mode \n 3) Exit program \n \n Your choice: ");
	scanf("%d", &Local_u32Mode);
	switch(Local_u32Mode)
	{
		case 1:
		/* Enter the admin mode, if the password is entered incorrectly
		for 3 times the function returns 3 and the program closes */
			Local_u32Mode = CMS_u8_admin_mode(); 
			break;
		case 2:
			CMS_vid_user_mode(); /* Enter the user mode */
			break;
		case 3: /* close the whole program */
			break;
		default:
			printf("Wrong entry. Choose from 1 to 3 \n"); /* repeat until appropirate entry is chosen */
			break;
	}
	}
	
}

u8 CMS_u8_admin_mode()
{
	u8 Local_flag=0;
	u32 Local_u32Pass=0;
	while(Local_flag < 3) /* a flag until the correct password is entered, number of tries = 3 */
	{
		printf(" \n Enter the password: ");
		scanf("%d",&Local_u32Pass);
		if(Local_u32Pass == 1234) /* The correct password for admin mode is 1234 */
		{
			u32 Local_u32Feature=0;
			printf("\n Welcome."); /* Printed once on entering the right password */
			while(Local_u32Feature <5) /* keeps running until choice 5) is chosen*/
			{
				/* choose a feature in admin mode */
			printf("\n You can choose between: \n");
			printf("1) Add new patient record \n");
			printf("2) Edit patient record \n");
			printf("3) Reserve a slot with a doctor \n");
			printf("4) Cancel reservation \n");
			printf("5) Back to main menu \n \n Your choice: ");
			scanf("%d", &Local_u32Feature);
				/* Perform the feature function */
				switch(Local_u32Feature)
				{
				case 1:
					CMS_vid_add_new_patient();
					break;
				case 2:
					CMS_vid_edit_patient();
					break;
				case 3:
					CMS_vid_reserve_reservation();
					break;
				case 4:
					CMS_vid_cancel_reservation();
					break;
				case 5:
					break; /* Back to choose mode menu */
				default:
					printf("Wrong entry. Choose from 1 to 5 \n"); /* repeat until appropirate entry is chosen */
					Local_u32Feature =0;
					break;
				}	
			}
			Local_flag=4; /* set the flag to leave the loop */
		}
		else 
		{
			printf("Wrong password.\n"); 
			Local_flag++; /* a try is used */
		}
	}
	if(Local_flag == 3) /* the password is entered incorrect for 3 conseutive times */
	{
		printf("Wrong password for 3 times. Try again later \n"); /* The program will close after this */
	}
	return Local_flag;
}

void CMS_vid_user_mode()
{
	u32 Local_u32View=0;
	printf("\n Welcome."); /* printed once on entering the mode */
	while(Local_u32View < 3)
	{
	/* Choose a feature */
	printf(" \n You can choose between: \n");
	printf("1) View patient record \n");
	printf("2) View today's reservation \n");
	printf("3) Back to main menu \n \n Your choice: ");
	scanf("%d", &Local_u32View);
		switch(Local_u32View)
		{
			case 1:
				CMS_vid_view_patient_record();
				break;
			case 2:
				CMS_vid_view_reservations_today();
				break;
			case 3:
				break;
			default:
				printf("Wrong entry. Choose from 1 to 3 \n"); /* repeat until appropirate entry is chosen */
				Local_u32View =0;
				break;
		}
	}	
	
}

void CMS_vid_add_new_patient()
{
	static new_patient * ptr=NULL;
	new_patient * patient = (new_patient*) malloc(sizeof(new_patient)); /*dynamic memort allocation: create a new patient record */
	patient->next=NULL; /* save the new patient record in the end of the list */
	
	if(head == NULL) /* the length of the list is zero: at the start */
	{
		head = patient;
	}
	else
	{
		ptr = head;
		while(ptr->next !=NULL) /* null means it reached last element*/
		{
			ptr=ptr->next;
		}
		ptr->next=patient;
	}
	
	
	/* Recording the basic information of a new patient */
	printf("Please enter patient name: ");
	scanf(" %s",&patient->name); /* to scan a string */
	
	printf("Please enter patient age: ");
	scanf("%d",&patient->age);
	
	u32 local_u32_gender =10;
	printf("Please enter patient gender: \n 1)male \n 2)female \n Gender: "); /* enter 1 for male or enter 2 for female */
	scanf("%d",&local_u32_gender);
	if(local_u32_gender == 1)
	{
		patient->gender = male; /* defined in enum */
	}
	else if(local_u32_gender == 2)
	{
		patient->gender = female; /* defined in enum */
	}
	
	u32 local_u32_id=0;
	printf("Please enter patient ID: ");
	scanf("%d",&local_u32_id);
	/* Search if the given ID already exists */
	ptr = head; /* start seraching from the beginning of the patients' list */
	while(ptr != NULL) /* keep searching until we reach the end of the list */
	{
		if(ptr->id == local_u32_id) /* The ID exists */
		{
			printf("This ID is already reserved.\nPlease enter another ID: ");
			scanf("%d",&local_u32_id); /* enter another ID */
			ptr = head; /* search agaian from the beginning if the new given ID exists */
		}
		else
		{
			ptr =ptr->next; /* move to the next recorded patient data to check */
		}
	}
	patient->id = local_u32_id; /* save the ID after checking it is unique */	
}

void CMS_vid_edit_patient()
{
	static new_patient * ptr=NULL;
	u32 local_u32_id=0, flag=0;
	printf("Please enter patient ID to edit his data: ");
	scanf("%d",&local_u32_id);
	/* Search if the given ID already exists */
	ptr = head; /* start seraching from the beginning of the patients' list */
	while((ptr != NULL) && (flag == 0)) /* keep searching until we reach the end of the list */
	{
		if(ptr->id == local_u32_id) /* The ID exists */
		{
			u32 local_u32_edit =0;
			u32 local_u32_gender =10; /* declared here because we can not declare a variable inside a switch */
			printf("Choose what you want to edit: \n");
			printf(" 1) Name \n 2) Age \n 3) Gender \n \n Your choice: ");
			scanf("%d", &local_u32_edit);
			switch(local_u32_edit)
			{
				/* perform the edit */
				case 1:
					printf("Name after edit: ");
					scanf(" %s",&ptr->name); /* to scan a string */
					break;
				case 2:
					printf("Age after edit: ");
					scanf("%d",&ptr->age);
					break;
				case 3:
					printf("\n 1)male \n 2)female \n Gender after edit: "); /* enter 1 for male or enter 2 for female */
					scanf("%d",&local_u32_gender);
					if(local_u32_gender == 1)
					{
						ptr->gender = male; /* defined in enum */
					}
					else if(local_u32_gender == 2)
					{
						ptr->gender = female; /* defined in enum */
					}
					break;
			}
			flag = 1; 
		}
		else
		{
			ptr =ptr->next; /* move to the next recorded patient data to comapre the ID */
		}
	}
	if(flag == 0) /* We reached the end of the list and the ID doesn't exist */
	{
		printf("Incorrect ID. \n");
	}
}

void CMS_vid_reserve_reservation()
{
	static u32 local_u32_EmptyAppointments=5; /* number of empty appointments at first is 5 */
	u32 local_u32_id=0, local_u32_appointment=0, flag=0;;
	static new_patient * ptr=NULL;
	printf("The available reservations appointments are: \n");
	if(reservations[0] == empty)
	{
		printf("1)From 2 PM to 2:30 Pm \n");
	}
	if(reservations[1] == empty)
	{
		printf("2)From 2:30 PM to 3 Pm \n");
	}
	if(reservations[2] == empty)
	{
		printf("3)From 3 PM to 3:30 Pm \n");
	}
	if(reservations[3] == empty)
	{
		printf("4)From 4 PM to 4:30 Pm \n");
	}
	if(reservations[4] == empty)
	{
		printf("5)From 4:30 PM to 5 Pm \n");
	}
	if(local_u32_EmptyAppointments == 0)
	{
		printf("No empty appointments today. \n");
	}
	else if(local_u32_EmptyAppointments >0)	
	{
	printf("\nEnter the patient ID to reserve an appointment: ");
	scanf("%d",&local_u32_id);
	/* Search if the given ID already exists */
	ptr = head; /* start seraching from the beginning of the patients' list */
		while((ptr != NULL) && (flag == 0)) /* keep searching until we reach the end of the list */
		{
			if(ptr->id == local_u32_id) /* The ID exists */
			{
				printf("Choose the desired time: ");
				scanf("%d",&local_u32_appointment);
				reservations[local_u32_appointment - 1] = local_u32_id; /* reserve an appointment */
				local_u32_EmptyAppointments--; /* number of empty appointments decreased */
				flag = 1;
			}
			else
			{
				ptr =ptr->next; /* move to the next recorded patient data to comapre the ID */
			}
		}
		if(flag == 0) /* We reached the end of the list and the ID doesn't exist */
		{
			printf("Incorrect ID. \n");
		}
	
	}
}

void CMS_vid_cancel_reservation()
{
	u32 local_u32_id=0;
	u8 local_u8_cancel=0;
	printf("Enter ID of the patient to cancel today's reservation: ");
	scanf("%d",&local_u32_id);
	for( u8 local_u8_slot=0 ; local_u8_slot<5; local_u8_slot++)
	{
		if(reservations[local_u8_slot] == local_u32_id) /* the patient's appointment is found */
		{
			reservations[local_u8_slot] = empty; /* cancel reservation */
			local_u8_cancel = 1; /*a flag that the process is completed  */
			local_u8_slot = 5;
		}
	}
	if(local_u8_cancel == 0) /* no matching id was found to cancel */
	{
		printf("There is no reservation for this ID to cancel.\n");
	}
}

void CMS_vid_view_patient_record()
{
	static new_patient * ptr=NULL;
	u32 local_u32_id=0, flag=0;
	printf("Please enter patient ID to view his basic information: ");
	scanf("%d",&local_u32_id);
	/* Search if the given ID already exists */
	ptr = head; /* start seraching from the beginning of the patients' list */
	while((ptr != NULL) && (flag == 0)) /* keep searching until we reach the end of the list */
	{
		if(ptr->id == local_u32_id) /* The ID exists */
		{
			/* Printing the patient information */
			printf("Name: %s \n",ptr->name);
			printf("Age: %d \n",ptr->age);
			if(ptr->gender == male)
			{
				printf("Gender: male \n");
			}
			else if(ptr->gender == female)
			{
				printf("Gender: female \n");
			}
		flag =1; /* process completed, leave the searching loop*/
		}
		else
		{
			ptr =ptr->next; /* move to the next recorded patient data to search for the ID */
		}
	}
	if(flag == 0) /* We reached the end of the list and the ID doesn't exist */
	{
		printf("Incorrect ID. No patient is recorded with this ID. \n");
	}
}

void CMS_vid_view_reservations_today()
{
	u8 local_u8_empty_day =1;
	printf("Today's reservations are: \n");
	/* check if very appointment is empty or not */
	if(reservations[0] != empty)
	{
		printf("From 2 PM to 2:30 Pm, Patient ID: %d \n",reservations[0]);
		local_u8_empty_day =0; /* not an empty day */
	}
	if(reservations[1] != empty)
	{
		printf("From 2:30 PM to 3 Pm, Patient ID: %d \n",reservations[1]);
		local_u8_empty_day =0; /* not an empty day */
	}
	if(reservations[2] != empty)
	{
		printf("From 3 PM to 3:30 Pm, Patient ID: %d \n",reservations[2]);
		local_u8_empty_day =0; /* not an empty day */
	}
	if(reservations[3] != empty)
	{
		printf("From 4 PM to 4:30 Pm, Patient ID: %d \n",reservations[3]);
		local_u8_empty_day =0; /* not an empty day */
	}
	if(reservations[4] != empty)
	{
		printf("From 4:30 PM to 5 Pm, Patient ID: %d \n",reservations[4]);
		local_u8_empty_day =0; /* not an empty day */
	}
	if(local_u8_empty_day == 1) /* empty day */
	{
		printf("There is no reservations for today \n.");
	}
}