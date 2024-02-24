/*
========================================================
Date   : 24 - 04 - 2023
Author : Emad Hajaj
Target : LCD_interface.h
========================================================
Notes:
+
========================================================
*/ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

// =============================================== MACROS ===============================================


// shift direction
#define LCD_SHIFT_LEFT          0
#define LCD_SHIFT_RIGHT         1
						      
// Lines				      
#define LCD_LINE_ONE            1
#define LCD_LINE_TWO            2

// Modes
#define LCD_8_BIT_MODE          1
#define LCD_4_BIT_MODE          2

						  
// =============================================== Functions Prototypes ===============================================
			  
						  
void LCD_init              (void);
void LCD_sendInstruction   ( u8 cmnd );
void LCD_showChar          ( u8 data );
void LCD_showString        ( u8 *string );
void LCD_showAt            ( u8 line, u8 position);
void LCD_clear             ( void );
void LCD_shift             ( u8 shiftDirection );

#endif /* LCD_INTERFACE_H_ */