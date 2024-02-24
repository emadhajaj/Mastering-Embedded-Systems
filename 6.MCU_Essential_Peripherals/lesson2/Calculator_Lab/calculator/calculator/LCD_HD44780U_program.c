/*
========================================================
Date   : 24 - 04 - 2023
Author : Emad Hajaj
Target : LCD_program.c
========================================================
Notes:
+IN 4BIT INITIALIZATION WE SEND AN ENABLE SIGNAL AFTER EVERY 4BIT SENT TO THE LCD
+
========================================================
*/

#define  F_CPU 16000000UL
#include <util/delay.h>

// Utiles Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

// MCALL
#include "ATMega32_DIO_interface.h"

// HALL
#include "LCD_HD44780U_interface.h"
#include "LCD_HD44780U_config.h"


// private functions
static void privateWriteHalfPort( u8 value ); // this func is made to be used in this module funcs only



//Functions

void LCD_sendInstruction ( u8 instr ){
	// set RS to Instruction code
	DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, LCD_PIN_LOW); 
	
	// set RW to Write
	DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, LCD_PIN_LOW);
	
#if LCD_MODE == LCD_8_BIT_MODE

	DIO_setPortValue(LCD_DATA_PORT,instr);
	
	// Enable Pulse 
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_LOW);

#elif LCD_MODE == LCD_4_BIT_MODE

	// write the Most 4 bits
	privateWriteHalfPort(instr>>4);

	// Enable Pulse
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_LOW);
	
	// write the Least 4 bits
	privateWriteHalfPort(instr);
	
	// Enable Pulse
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_LOW);
	
#endif

}


void LCD_showChar ( u8 data ){
	// set RS to Display data
	DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, LCD_PIN_HIGH); 
	
	// set RW to Write
	DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, LCD_PIN_LOW); 
	
#if LCD_MODE == LCD_8_BIT_MODE

	DIO_setPortValue(LCD_DATA_PORT,data);
	
	// Enable Pulse
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_LOW);

#elif LCD_MODE == LCD_4_BIT_MODE

	// write the Most 4 bits
	privateWriteHalfPort(data>>4);

	// Enable Pulse
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_LOW);
	
	// write the Least 4 bits
	privateWriteHalfPort(data);
	
	// Enable Pulse
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LCD_PIN_LOW);
	
#endif
	
}


void LCD_init (void){
	// ============ in this function we follow the sequence in the LMB161A data sheet ============
	
	_delay_ms(35);
	
	#if   LCD_MODE == LCD_8_BIT_MODE
	
	LCD_sendInstruction(0b00111000); // Function Set command 2*16 LCD
	
	#elif LCD_MODE == LCD_4_BIT_MODE
	
	DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, LCD_PIN_LOW);   // set RS to Display data
	DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, LCD_PIN_LOW);    // set RW to Write
	privateWriteHalfPort(0b0010);                          // write the Most 4 bits
	
	// Enable pulse
	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LCD_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LCD_PIN_LOW);
	
	LCD_sendInstruction(0b00101000);
	_delay_ms(45);
	
	#endif
	
	LCD_sendInstruction(0b00001111);

	_delay_ms(45);
	
	LCD_sendInstruction(0b00000001); // clear display
	_delay_ms(2);
	
	LCD_sendInstruction(0b00000110); //entry mode set (auto increment mode on, shift off)
	
}


static void privateWriteHalfPort( u8 value ){
	if ( 1 == GET_BIT(value, 0) ){
		DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, LCD_PIN_HIGH);
	} 
	else
	{
		DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, LCD_PIN_LOW);
	}
	
	if ( 1 == GET_BIT(value, 1) ){
		DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, LCD_PIN_HIGH);
	} 
	else
	{
		DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, LCD_PIN_LOW);
	}
	
	if ( 1 == GET_BIT(value, 2) ){
		DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, LCD_PIN_HIGH);
	} 
	else
	{
		DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, LCD_PIN_LOW);
	}
	
	if ( 1 == GET_BIT(value, 3) ){
		DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, LCD_PIN_HIGH);
	} 
	else
	{
		DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, LCD_PIN_LOW);
	}
}

void LCD_showString ( u8 *string){
	if (string != NULL){
		
		u8 stringlength = 0 ;
		
		while (string[stringlength] != '\0'){
			LCD_showChar(string[stringlength]);
			stringlength++;
		}
	}
}


void LCD_showAt ( u8 line, u8 position){
	
	if ( line == LCD_LINE_ONE ){
		if(position <= 15){
			LCD_sendInstruction(0x80 + position);
		}
	}
	
	if ( line == LCD_LINE_TWO ){
		if(position <= 15){
			LCD_sendInstruction(0xc0 + position);
		}
	}
}


void LCD_clear (void){
	LCD_sendInstruction(0b00000001);
	_delay_ms(2);
}

void LCD_shift ( u8 shiftDirection ){
	if (shiftDirection == LCD_SHIFT_LEFT){
		LCD_sendInstruction(0b00011000);
		_delay_ms(10);
	}
	if (shiftDirection == LCD_SHIFT_RIGHT){
		LCD_sendInstruction(0b00011100);
		_delay_ms(10);
	}
}