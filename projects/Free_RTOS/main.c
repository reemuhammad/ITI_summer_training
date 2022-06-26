/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: DELL
 */
#include "lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "F-RTOS/FreeRTOS.h"
#include "F-RTOS/task.h"
#include "CLCD_INTERFACE.h"
/* create object of semaphore */
xSemaphoreHandle LCD_semap;
#define code 1

#if code == 1

void Task1( void * p);
void Task2( void * p);
void Task3( void * p);
void Task4( void * p);

int main()
{

	DIO_VidSetPortDirection(Port_D,output);
	CLCD_VidInit();

	xTaskCreate(Task1, /* function address*/
			NULL,	/* function name, NULL because we don't want it*/
			100, /* stack depth */
			NULL,	/* pointer to void , will be passed to the task */
			1,	/* priority */
			NULL); /* handle task, used with other functions like delete task */

	xTaskCreate(Task2, /* function address*/
				NULL,	/* function name, NULL because we don't want it*/
				100, /* stack depth */
				NULL,	/* pointer to void , will be passed to the task */
				0,	/* priority */
				NULL); /* handle task, used with other functions like delete task */

	xTaskCreate(Task3, /* function address*/
					NULL,	/* function name, NULL because we don't want it*/
					100, /* stack depth */
					NULL,	/* pointer to void , will be passed to the task */
					0,	/* priority */
					NULL); /* handle task, used with other functions like delete task */

	xTaskCreate(Task4, /* function address*/
					NULL,	/* function name, NULL because we don't want it*/
					100, /* stack depth */
					NULL,	/* pointer to void , will be passed to the task */
					0,	/* priority */
					NULL); /* handle task, used with other functions like delete task */

	LCD_semap = xSemaphoreCreateCounting(1 ,1);
	vTaskStartScheduler();

	/* any code starting from here is not seen */
	while(1)
	{

	}
	return 0;
}

void Task1( void * p)
{
	u8 state=8;
	while(1)
	{

		DIO_VidSetPinValue(Port_D,Pin_0,state);
		vTaskDelay(200);   /* Put the task in waiting and see other tasks , 200 is the number of ticks, in configurations we set the tick as 1 ms*/
		state = ! state;

	}
}


void Task2( void * p)
{
	u8 state=8;
		while(1)
		{
			DIO_VidSetPinValue(Port_D,Pin_1,state);
			state = ! state;
			vTaskDelay(400);   /* Put the task in waiting and see other tasks */
		}
}

void Task3( void * p)
{
	u8 state=8;
		while(1)
		{
			DIO_VidSetPinValue(Port_D,Pin_2,state);
			state = ! state;
			vTaskDelay(800);   /* Put the task in waiting and see other tasks */
		}
}


void Task4( void * p)
{
	u8 state=8;
		while(1)
		{
			DIO_VidSetPinValue(Port_D,Pin_3,state);
			state = ! state;
			vTaskDelay(1600);   /* Put the task in waiting and see other tasks */
		}
}

#endif


#if code == 2

void Task1( void * p);
void Task2( void * p);
void Task3( void * p);
void Task4( void * p);

int main()
{

	DIO_VidSetPortDirection(Port_D,output);
	CLCD_VidInit();

	xTaskCreate(Task1, /* function address*/
			NULL,	/* function name, NULL because we don't want it*/
			100, /* stack depth */
			NULL,	/* pointer to void , will be passed to the task */
			1,	/* priority */
			NULL); /* handle task, used with other functions like delete task */

	xTaskCreate(Task2, /* function address*/
				NULL,	/* function name, NULL because we don't want it*/
				100, /* stack depth */
				NULL,	/* pointer to void , will be passed to the task */
				0,	/* priority */
				NULL); /* handle task, used with other functions like delete task */

	xTaskCreate(Task3, /* function address*/
					NULL,	/* function name, NULL because we don't want it*/
					100, /* stack depth */
					NULL,	/* pointer to void , will be passed to the task */
					0,	/* priority */
					NULL); /* handle task, used with other functions like delete task */

	xTaskCreate(Task4, /* function address*/
					NULL,	/* function name, NULL because we don't want it*/
					100, /* stack depth */
					NULL,	/* pointer to void , will be passed to the task */
					0,	/* priority */
					NULL); /* handle task, used with other functions like delete task */

	LCD_semap = xSemaphoreCreateCounting(1 ,1);
	vTaskStartScheduler();

	/* any code starting from here is not seen */
	while(1)
	{

	}
	return 0;
}

void Task1( void * p)
{
	u8 state=8;
	while(1)
	{

		DIO_VidSetPinValue(Port_D,Pin_0,state);
		vTaskDelay(200);   /* Put the task in waiting and see other tasks , 200 is the number of ticks, in configurations we set the tick as 1 ms*/
		state = ! state;

	}
}


void Task2( void * p)
{
	u8 state=8;
		while(1)
		{
			DIO_VidSetPinValue(Port_D,Pin_1,state);
			state = ! state;
			vTaskDelay(400);   /* Put the task in waiting and see other tasks */
		}
}

void Task3( void * p)
{
	u8 state=8;
		while(1)
		{
			DIO_VidSetPinValue(Port_D,Pin_2,state);
			state = ! state;
			vTaskDelay(800);   /* Put the task in waiting and see other tasks */
		}
}


void Task4( void * p)
{
	u8 state=8;
		while(1)
		{
			DIO_VidSetPinValue(Port_D,Pin_3,state);
			state = ! state;
			vTaskDelay(1600);   /* Put the task in waiting and see other tasks */
		}
}
#endif
