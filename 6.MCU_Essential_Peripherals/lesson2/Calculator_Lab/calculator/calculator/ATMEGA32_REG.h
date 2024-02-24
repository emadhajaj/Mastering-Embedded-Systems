/*
========================================================
Date   : 14 - 03 - 2023
Author : Emad Hajaj
Target : Defining the Regesters
========================================================
Notes:
+ PINs are controlled only by 3 registers (DDR, PORT, PIN)
PIN for input, PORT for output and, DDR to set either to 
input or output. every 8 bits are grouped together and 
given a letter to name thier register (ABCD)

+ 
========================================================
*/


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

// =============================================== DIO Registers ===============================================


// DATA DIRECTION
#define DDRA        (*(volatile u8*)0x3A)
#define DDRB        (*(volatile u8*)0x37)
#define DDRC        (*(volatile u8*)0x34)
#define DDRD        (*(volatile u8*)0x31)

// OUTPUT 
#define PORTA       (*(volatile u8*)0x3B)
#define PORTB       (*(volatile u8*)0x38)
#define PORTC       (*(volatile u8*)0x35)
#define PORTD       (*(volatile u8*)0x32)

// INPUT
#define PINA        (*(volatile u8*)0x39)
#define PINB        (*(volatile u8*)0x36)
#define PINC        (*(volatile u8*)0x33)
#define PIND        (*(volatile u8*)0x30)


#endif /* ATMEGA32_REG_H_ */