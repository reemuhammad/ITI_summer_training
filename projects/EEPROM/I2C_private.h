/*
 * I2C_private.h
 *
 *  Created on: Aug 31, 2021
 *      Author: DELL
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/* TWI Control Register */
#define TWCR 					*((volatile u8 * )0x56)

/* TWCR bits */
#define TWCR_TWINT							7
#define TWCR_TWEA							6
#define TWCR_TWSTA							5
#define TWCR_TWSTO							4
#define TWCR_TWWC							3
#define TWCR_TWEN							2
#define TWCR_TWIE							0

/* TWI Bit Rate Register */
#define TWBR                    *((volatile u8 * )0x20)
/* TWI Status Register */
#define TWSR                    *((volatile u8 * )0x21)

/* TWSR bits */
#define TWSR_TWS7 							7
#define TWSR_TWS6 							6
#define TWSR_TWS5  							5
#define TWSR_TWS4  							4
#define TWSR_TWS3  							3
#define TWSR_TWPS1 							1
#define TWSR_TWPS0 							0

/* TWI (Slave) Address Register */
#define TWAR                    *((volatile u8 * )0x22)

/* TWAR bits */
#define TWAR_TWA0 1
#define TWAR_TWGCE 0

/* TWI Data Register */
#define TWDR					*((volatile u8 * )0x23)


/* TWI states */
/*** For Master mode ****/
#define START_ACK 0x08
#define REP_START_ACK 0x10
#define SLAVE_W_ACK 0x18
#define SLAVE_W_NACK 0x20
#define SLAVE_DATA_ACK 0x28
#define SLAVE_DATA_NACK 0x30
#define SLAVE_R_ACK 0x40
#define SLAVE_R_NACK 0x48
#define MASTER_R_DATA_ACK 0x50
#define MASTER_R_DATA_NACK 0x58



/*** For Slave mode ****/
#define SLAVE_ADDRESS_W_ACK 0x60
#define SLAVE_GEN_CALL_ACK 0x70
#define SLAVE_DATA_REC_ACK 0x80
#define SLAVE_DATA_REC_NACK 0x88


#define TWSR_MASK 0xF8


enum TWI{
	 Prescaler_1,
	 Prescaler_4,
	 Prescaler_16,
	 Prescaler_64

};
#endif /* I2C_PRIVATE_H_ */




