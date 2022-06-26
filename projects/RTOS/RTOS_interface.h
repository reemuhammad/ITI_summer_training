/*
 * RTOS_interface.h
 *
 *  Created on: Sep 6, 2021
 *      Author: DELL
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidStart(void);
u8 RTOS_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (* func) (void));
void RTOS_voidDispather(void);

#endif /* RTOS_INTERFACE_H_ */
