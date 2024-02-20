/*
 * UTILS.h
 *
 * Created: 2/14/2024 11:23:31 AM
 *  Author: Emad Hajaj
 */ 


#ifndef UTILS_H_
#define UTILS_H_



#define SET_BIT(reg, bit)          reg |= (1<<bit)
#define CLEAR_BIT(reg, bit)        reg &= ~(1<<bit)
#define TOGGLE_BIT(reg, bit)       reg ^= (1<<bit)
#define GET_BIT(reg, bit)          ((reg>>bit) &1)



#endif /* UTILS_H_ */