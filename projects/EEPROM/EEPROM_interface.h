/*
 * EEPROM_interface.h
 *
 *  Created on: Sep 2, 2021
 *      Author: DELL
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/* EEPROM FUNCTIONS */
/* write on a byte in the EEPROM memory*/
void EEPROM_write(u8 Copy_u8_EEPROM_Address,u8 Copy_u8MemoryAddress, u8 Copy_u8data);
/* read a byte in the EEPROM memory*/
void EEPROM_read(u8 Copy_u8_EEPROM_Address,u8 Copy_u8MemoryAddress, u8 * Copy_u8read_value);
/* write the same value on a block of successive bytes with the number we want in the EEPROM memory*/
void EEPROM_writeBlock(u8 Copy_u8_EEPROM_Address,u8 Copy_u8NumBytes,u8 Copy_u8MemoryAddress, u8 Copy_u8data);
/* read from a block of successive bytes with the number we want in the EEPROM memory*/
void EEPROM_readBlock(u8 Copy_u8_EEPROM_Address,u8 Copy_u8NumBytes,u8 Copy_u8MemoryAddress, u8 * Copy_u8read_value);


#endif /* EEPROM_INTERFACE_H_ */
