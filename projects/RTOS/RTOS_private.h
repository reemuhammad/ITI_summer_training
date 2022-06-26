/*
 * RTOS_private.h
 *
 *  Created on: Sep 6, 2021
 *      Author: DELL
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

enum RTOS{
	/* for error status */
	OK,
	NOT_OK
};

typedef struct
{
	u16 periodictiy; /* task will be executed after how many milli seconds? >>> 200 ms */
	u16 TaskCounter; /* counts to calculate 200 ms */
	void (*TaskFunc)(void); /* task call back */
	u8 RunMe; /* flag */
}TaskControlBlock_t;

static void voidAlgorithm(void);
static void voidSleep(void);
#endif /* RTOS_PRIVATE_H_ */
