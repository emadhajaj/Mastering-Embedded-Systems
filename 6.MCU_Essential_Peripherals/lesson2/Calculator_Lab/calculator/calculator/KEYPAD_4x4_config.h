/*
 * KBD_config.h
 *
 *  Created on: Mar 16, 2023
 *      Author: Hello
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

// ==================== Keypad Column (output) PINs ====================

#define KPD_COLMS       4

#define KPD_COL0_PORT   DIO_PORTC
#define KPD_COL0_PIN    DIO_PIN0

#define KPD_COL1_PORT   DIO_PORTC
#define KPD_COL1_PIN    DIO_PIN1

#define KPD_COL2_PORT   DIO_PORTC
#define KPD_COL2_PIN    DIO_PIN2

#define KPD_COL3_PORT   DIO_PORTC
#define KPD_COL3_PIN    DIO_PIN3


// ==================== Keypad Row (input) PINs ====================

#define KPD_ROWS        4

#define KPD_ROW0_PORT   DIO_PORTC
#define KPD_ROW0_PIN    DIO_PIN4

#define KPD_ROW1_PORT   DIO_PORTC
#define KPD_ROW1_PIN    DIO_PIN5

#define KPD_ROW2_PORT   DIO_PORTC
#define KPD_ROW2_PIN    DIO_PIN6

#define KPD_ROW3_PORT   DIO_PORTC
#define KPD_ROW3_PIN    DIO_PIN7

// ==================== Keypad Buttons ====================


#define KPD_KEYS  { '7' , '8' ,'9' , '/' , \
	                '4' , '5' ,'6' , '*' , \
					'1' , '2' ,'3' , '-' , \
					'C' , '0' ,'=' , '+' }
					
					
#endif /* KPD_CONFIG_H_ */
