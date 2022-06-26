/*
 * bit_math.h
 *
 *  Created on: Aug 15, 2021
 *      Author: DELL
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/* functions like macro : text replacement */
#define Set_Bit(Var,BitNo)  (Var |= (1<<BitNo)) /* 0 becomes 1*/
#define Clr_Bit(Var,BitNo)   (Var &= ~(1<<BitNo)) /* 1 becomes 0 */
#define Toggle_Bit(Var,BitNo)  (Var ^= (1<<BitNo)) /* 1 becomes 0, 0 becomes 1 */
#define Get_Bit(Var,BitNo)  ((Var | (1<<BitNo)>>BitNo) /* Get bit to know if it is 0 or 1 */
/* The file body lies between the file guard lines
 that make sure the file is defined
only 1 time if it is included many times */

#endif /* BIT_MATH_H_ */
