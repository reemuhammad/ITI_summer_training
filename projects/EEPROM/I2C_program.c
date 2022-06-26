/*
 * I2C_program.c
 *
 *  Created on: Aug 31, 2021
 *      Author: DELL
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "I2C_private.h"
#include "I2C_interface.h"
#include "I2C_config.h"

void TWI_voidInitMaster(u8 Copy_u8Address)
{
	/* Freq= 400Kbps*/
	TWBR =2;
	TWSR |= PRESCALER<<TWSR_TWPS0;

	/* Assign Address */
	if(Copy_u8Address >0)
	{
		TWAR = Copy_u8Address<<1;   /* To send the address */
	}

	/* Enable TWI--->>I2C module in AVR */
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidInitSlave(u8 Copy_u8Address)
{
	/* Assign Address */
	if(Copy_u8Address >0)
	{
		TWAR = Copy_u8Address<<1;   /* To save the address of the MC */
	}

	/* Enable TWI--->>I2C module in AVR */
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_SendStartCondition(void)
{
	/* Set start condition */
	SET_BIT(TWCR,TWCR_TWSTA);
	/* Start job by clearing the flag by setting it to 1*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* Wait until the operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) ==0 );

	/* Check if the process is executed correctly */
	/* ------>>>>>>>>> write here the check condition */

}

void TWI_MasterSendAddress(u8 Copy_u8Address, u8 Copy_u8Operation)
{
	/* send the slave address and the operation we want to do (either Read or Write) */
	TWDR = (Copy_u8Address<<1 | Copy_u8Operation) ;
	/* Clear the start bit */
	CLEAR_BIT(TWCR,TWCR_TWSTA);
	/* Start job by clearing the flag by setting it to 1*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* Wait until the operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) ==0 );

	/* Check if the process is executed correctly */
	/* ------>>>>>>>>> write here the check condition */

}

void TWI_MasterSendData(u8 Copy_u8Data)
{
	TWDR = Copy_u8Data;
	/* Start job by clearing the flag by setting it to 1*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* Wait until the operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) ==0 );

	/* Check if the process is executed correctly : here acknowledgment */
	/* ------>>>>>>>>> write here the check condition */
}

void TWI_MasterReadData(u8 * Copy_u8Data)
{
	/* Start job by clearing the flag by setting it to 1*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* Wait until the operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) ==0 );
	/* read data and save in the variable which the pointer points to */
	* Copy_u8Data = TWDR;
}

void TWI_SendStopCondition(void)
{
	/* Set stop condition */
	SET_BIT(TWCR,TWCR_TWSTO);
	/* Start job by clearing the flag by setting it to 1*/
	SET_BIT(TWCR,TWCR_TWINT);
}
