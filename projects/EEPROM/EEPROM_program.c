/*
 * EEPROM_program.c
 *
 *  Created on: Sep 2, 2021
 *      Author: DELL
 */
#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "I2C_private.h"
#include "I2C_interface.h"


void EEPROM_write(u8 Copy_u8_EEPROM_Address,u8 Copy_u8MemoryAddress, u8 Copy_u8data)
{
	/* start */
	TWI_SendStartCondition();
	/* send address of the EEPROM and write operation */
	TWI_MasterSendAddress(Copy_u8_EEPROM_Address, TWI_Write);
	/* send address in the memory we want to write on */
	TWI_MasterSendData(Copy_u8MemoryAddress);
	/* send data */
	TWI_MasterSendData(Copy_u8data);
	/* stop */
	TWI_SendStopCondition();
}

void EEPROM_read(u8 Copy_u8_EEPROM_Address,u8 Copy_u8MemoryAddress, u8 * Copy_u8read_value)
{
	/* start */
	TWI_SendStartCondition();
	/* send address of the EEPROM and write operation */
	TWI_MasterSendAddress(Copy_u8_EEPROM_Address, TWI_Write);
	/* send address in the memory we want to read from */
	TWI_MasterSendData(Copy_u8MemoryAddress);
	/* start again */
	TWI_SendStartCondition();
	/* send address of the EEPROM and read operation */
	TWI_MasterSendAddress(Copy_u8_EEPROM_Address, TWI_Read);
	/* read data */
	TWI_MasterReadData(Copy_u8read_value);
	/* stop */
	TWI_SendStopCondition();
}

void EEPROM_writeBlock(u8 Copy_u8_EEPROM_Address,u8 Copy_u8NumBytes,u8 Copy_u8MemoryAddress, u8 Copy_u8data)
{
	/* start */
	TWI_SendStartCondition();
	/* send address of the EEPROM and write operation */
	TWI_MasterSendAddress(Copy_u8_EEPROM_Address, TWI_Write);
	/* send address in the memory we want to start writing from */
	TWI_MasterSendData(Copy_u8MemoryAddress);
	/* send data: the same data value will be written on successive bytes that represent the block */
	for(u8 i=0; i<Copy_u8NumBytes;i++)
	{TWI_MasterSendData(Copy_u8data);}
	/* stop */
	TWI_SendStopCondition();
}

void EEPROM_readBlock(u8 Copy_u8_EEPROM_Address,u8 Copy_u8NumBytes,u8 Copy_u8MemoryAddress, u8 * Copy_u8read_value)
{
	/* send acknowledge to be able to read successive bytes */
	SET_BIT(TWCR,TWCR_TWEA);
	/* start */
	TWI_SendStartCondition();
	/* send address of the EEPROM and write operation */
	TWI_MasterSendAddress(Copy_u8_EEPROM_Address, TWI_Write);
	/* send address in the memory we want to start reading from */
	TWI_MasterSendData(Copy_u8MemoryAddress);
	/* start again */
	TWI_SendStartCondition();
	/* send address of the EEPROM and read operation */
	TWI_MasterSendAddress(Copy_u8_EEPROM_Address, TWI_Read);
	/* read data: the data will be read from successive bytes that represent the block */
	for(u8 i=0; i<Copy_u8NumBytes;i++)
	{TWI_MasterReadData(&Copy_u8read_value[i]);}
	/* send NO acknowledge to stop reading: By clearing the enable acknowledge bit in the TWCR register */
	CLEAR_BIT(TWCR,TWCR_TWEA);
	/* Start job by clearing the flag by setting it to 1*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* Wait until the operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) ==0 );
	/* stop */
	TWI_SendStopCondition();
}
