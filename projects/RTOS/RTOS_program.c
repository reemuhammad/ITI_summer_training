/*
 * RTOS_program.c
 *
 *  Created on: Sep 6, 2021
 *      Author: DELL
 */

#include "lib/BIT_MATH.h"
#include "lib/STD_TYPES.h"
#include "GIE_interface.h"
#include "Timer_private.h"
#include "Timer_interface.h"

#include "RTOS_config.h"
#include "RTOS_private.h"
#include "RTOS_interface.h"

TaskControlBlock_t TaskBlocksArray[RTOS_TaskNum] ={{NULL}};
void RTOS_voidStart(void)
{
	/* initialize timer 0 on CTC mode and write 125  on 0CR0 , enable interrupt, set the prescaler on 64  */
	Timer_8bit_vid_Init(timer0,CTC,Toggle_OC0_on_compare_match);
	Timer_vid_Write_u8_OCR(timer0,125);
	Timer_vid_Interrupt(timer0,Output_Compare_Match_Int,Enable);

	/* Set call back of algorithm */
	TIMR0_CTC_SetCallBack(voidAlgorithm);
	/* global enable for the interrupts */
	GIE_Vid_Enable();

}

u8 RTOS_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (* func) (void))
{
	u8 Local_u8Error= OK;
	if((Copy_u8Priority < RTOS_TaskNum) && (func != NULL))
	{
		TaskBlocksArray[Copy_u8Priority].periodictiy= Copy_u16Periodicity;
		TaskBlocksArray[Copy_u8Priority].TaskFunc= func;
		TaskBlocksArray[Copy_u8Priority].RunMe= 0;
		TaskBlocksArray[Copy_u8Priority].TaskCounter= 0;
	}
	else
	{
		Local_u8Error= NOT_OK;
	}
	return Local_u8Error;
}


static void voidAlgorithm(void)
{
	/* check on all the tasks using for loop */
	for(u8 i=0; i<RTOS_TaskNum; i++)
	{
		/* check if task exists */
		if(TaskBlocksArray[i].TaskFunc != NULL)
		{
			/* check if  the counter == 0 */
			if(TaskBlocksArray[i].TaskCounter == 0)
			{
				/* set the flag */
				TaskBlocksArray[i].RunMe= 1;
				/* update counter to periodictiy again  */
				TaskBlocksArray[i].TaskCounter = TaskBlocksArray[i].periodictiy;
			}
			else
			{
				/* decrement the counter */
				TaskBlocksArray[i].TaskCounter--;
			}
		}
	}
}

void RTOS_voidDispather(void)
{
	/* check on all the tasks using for loop */
		for(u8 i=0; i<RTOS_TaskNum; i++)
		{
			/* check if task exists */
			if(TaskBlocksArray[i].TaskFunc != NULL)
			{
				/* check if the flag is set */
				if(TaskBlocksArray[i].RunMe == 1)
				{
					/* Clear the flag */
					TaskBlocksArray[i].RunMe= 0;
					/* Run task */
					TaskBlocksArray[i].TaskFunc();
				}
			}
		}
}

static void voidSleep(void)
{

}

