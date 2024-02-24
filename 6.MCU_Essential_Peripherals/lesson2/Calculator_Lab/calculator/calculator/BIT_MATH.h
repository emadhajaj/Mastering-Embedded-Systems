/*
========================================================
Date   : 21 - 02 - 2023
Author : Emad Hajaj
Target : Bit Math Library
========================================================
Notes:
+ 
========================================================
*/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

//bitwise operations
#define SET_BIT(REG,BIT_NUM)    REG |= (1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM)    REG &= (~(1<<BIT_NUM))
#define TOG_BIT(REG,BIT_NUM)    REG ^= (1<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM)    ((REG >> BIT_NUM) &1)

#endif