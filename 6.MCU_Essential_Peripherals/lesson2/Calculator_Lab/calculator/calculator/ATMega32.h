/*
 * ATMega32.h
 *
 * Created: 2/14/2024 11:22:36 AM
 *  Author: Emad Hajaj
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

// PORT A
#define  PORTA                    *(volatile unsigned int*)(0x3B)
#define  DDRA                     *(volatile unsigned int*)(0x3A)
#define  PINA                     *(volatile unsigned int*)(0x39)

// PORT B
#define  PORTB                    *(volatile unsigned int*)(0x38)
#define  DDRB                     *(volatile unsigned int*)(0x37)
#define  PINB                     *(volatile unsigned int*)(0x36)



#endif /* ATMEGA32_H_ */