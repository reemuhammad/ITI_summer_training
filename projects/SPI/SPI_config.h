/*
 * SPI_config.h
 *
 *  Created on: Aug 30, 2021
 *      Author: DELL
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* Choose between:		disable			enable    */
#define SPI_Interrupt				enable

/* Choose between:		MSB_first			LSB_first    */
#define Data_Order					MSB_first

/* Choose between:		Rising_leading_edge			Falling_leading_edge    */
#define Clock_Polarity				Rising_leading_edge

/* Choose between:		Sample_on_leading_edge			Setup_on_leading_edge    */
#define Clock_Phase					Sample_on_leading_edge

/* Choose between:
divide_Focs_by_4=0
divide_Focs_by_16,
divide_Focs_by_64,
divide_Focs_by_128,
divide_Focs_by_2,
divide_Focs_by_8,
divide_Focs_by_32    */
#define SCK_Frequency				divide_Focs_by_16


#endif /* SPI_CONFIG_H_ */
