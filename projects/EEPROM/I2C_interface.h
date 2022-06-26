/*
 * I2C_interface.h
 *
 *  Created on: Aug 31, 2021
 *      Author: DELL
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "lib/STD_TYPES.h"

#define TWI_Read				1
#define TWI_Write				0

void TWI_voidInitMaster(u8 Copy_u8Address);
void TWI_voidInitSlave(u8 Copy_u8Address);
void TWI_SendStartCondition(void);
void TWI_MasterSendAddress(u8 Copy_u8Address, u8 Copy_u8Operation);
void TWI_MasterSendData(u8 Copy_u8Data);
void TWI_MasterReadData(u8 * Copy_u8Data);
void TWI_SendStopCondition(void);



#endif /* I2C_INTERFACE_H_ */
