/*
 * LCD_HD44780U.h
 *
 * Created: 2/14/2024 11:39:48 AM
 *  Author: Emad Hajaj
 */ 


#ifndef LCD_HD44780U_H_
#define LCD_HD44780U_H_

#define F_CPU 8000000UL

#include "ATMega32.h"
#include "UTILS.h"
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

// =========================== PINs configuration ===========================

#define LCD_port                                    PORTA
#define DataDir_LCD_port                            DDRA
#define LCD_control                                 PORTB
#define DataDir_LCD_control                         DDRB
#define EN_switch                                   3
#define RW_switch                                   2
#define RS_switch                                   1


#define DATA_shift                                  0
#define LCD_REGISTER_SELECT_PIN						(0)
#define LCD_READ_WRITE_PIN							(1)
#define LCD_ENABLE_PIN								(2)
#define LCD_REGISTER_SELECT_ENABLE					(1)
#define LCD_REGISTER_SELECT_DISABLE					(0)
#define READ_FROM_LCD								(1)
#define WRITE_TO_LCD								(0)
#define LCD_ENABLE									(1)
#define LCD_DISABLE									(0)
#define LCD_FIRST_LINE								(0)
#define LCD_SECOND_LINE								(1)



// =========================== Select mode and comment the other one ===========================

#define	EIGHT_BIT_MODE
//#define FOUR_BIT_MODE


// =========================== Instructions ===========================

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)




// =========================== LCD APIs ===========================

void LCD_Init(void);
void LCD_Send_Command(unsigned char command);
void LCD_Send_Character(unsigned char character);
void LCD_Send_String(char *string);
void LCD_Clear_screen ();
void LCD_Isbusy(void);
void LCD_GotoXY(unsigned char line, unsigned char position );



void LCD_display_number (int Number );
void LCD_display_real_number (double  Number );



#endif /* LCD_HD44780U_H_ */