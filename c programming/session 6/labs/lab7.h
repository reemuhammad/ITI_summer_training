#ifndef lab7
#define lab7

/* functions like macro : text replacement */
#define Set_Bit(Var,BitNo)  (Var |= (1<<BitNo)) /* 0 becomes 1*/
#define Clr_Bit(Var,BitNo)   (Var &= ~(1<<BitNo)) /* 1 bcomes 0 */
#define Toggle_Bit(Var,BitNo)  (Var ^= (1<<BitNo)) /* 1 necomes 0, 0 becomes 1 */

#endif
/* The file body lies between the file guard lines
 that make sure the file is defined
only 1 time if it is included many times */