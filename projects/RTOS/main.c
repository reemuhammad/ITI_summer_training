/*
 * main.c
 *
 *  Created on: Sep 6, 2021
 *      Author: DELL
 */
#include "lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "RTOS_interface.h"

void task1(void);
void task2(void);
void task3(void);
void task4(void);

int main()
{
	/* set up output pins */
	DIO_VidSetPinDirection(Port_D,Pin_0,output);
	DIO_VidSetPinDirection(Port_D,Pin_1,output);
	DIO_VidSetPinDirection(Port_D,Pin_2,output);
	DIO_VidSetPinDirection(Port_D,Pin_3,output);

	/* create tasks */
	RTOS_u8CreateTask(0,200,task1);
	RTOS_u8CreateTask(1,400,task2);
	RTOS_u8CreateTask(2,800,task3);
	RTOS_u8CreateTask(3,1600,task4);

	RTOS_voidStart();
	while(1)
	{
		RTOS_voidDispather();
	}

	return 0;
}

void task1(void)
{
	static u8 toggle=0;
	toggle = !toggle;
	DIO_VidSetPinValue(Port_D,Pin_0,toggle);
}
void task2(void)
{
	static u8 toggle=0;
	toggle = !toggle;
	DIO_VidSetPinValue(Port_D,Pin_1,toggle);
}
void task3(void)
{
	static u8 toggle=0;
	toggle = !toggle;
	DIO_VidSetPinValue(Port_D,Pin_2,toggle);
}
void task4(void)
{
	static u8 toggle=0;
	toggle = !toggle;
	DIO_VidSetPinValue(Port_D,Pin_3,toggle);
}
