/*
========================================================
Date   : 24 - 04 - 2023
Author : Emad Hajaj
Target : LCD_confic.h
========================================================
Notes:
+
========================================================
*/


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_PIN_HIGH          DIO_PIN_HIGH
#define LCD_PIN_LOW           DIO_PIN_LOW

/* Options FOR LCD Mode:
1- LCD_8_BIT_MODE
2- LCD_4_BIT_MODE */
#define LCD_MODE              LCD_4_BIT_MODE

// Control Pins
#define LCD_RS_PORT           DIO_PORTB
#define LCD_RS_PIN            DIO_PIN1

#define LCD_RW_PORT           DIO_PORTB
#define LCD_RW_PIN            DIO_PIN2

#define LCD_EN_PORT           DIO_PORTB
#define LCD_EN_PIN            DIO_PIN3


// 4 Bit Mode Pins Configuration 

#define LCD_D4_PIN            DIO_PIN4
#define LCD_D4_PORT           DIO_PORTA

#define LCD_D5_PIN            DIO_PIN5
#define LCD_D5_PORT           DIO_PORTA

#define LCD_D6_PIN            DIO_PIN6
#define LCD_D6_PORT           DIO_PORTA

#define LCD_D7_PIN            DIO_PIN7
#define LCD_D7_PORT           DIO_PORTA


// 8 Bit Mode Pins Configuration

#define LCD_DATA_PORT         DIO_PORTA

#endif /* LCD_CONFIG_H_ */