/*
 * calculator.c
 *
 * Created: 2/14/2024 11:21:24 AM
 * Author : Emad Hajaj
 */ 

#include <stdio.h>
#include <math.h>

// UTILES_LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

// MCALL
#include "ATMega32_DIO_interface.h"

// HALL
#include "LCD_HD44780U_interface.h"
#include "LCD_HD44780U_config.h"
#include "KEYPAD_4x4_interface.h"
#include "KEYPAD_4x4_config.h"


void GPIO_Pins_Init(){
	// Data PINs
	DIO_setPinDirection(DIO_PORTA, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN7, DIO_PIN_OUTPUT);
	
	// Control PINs
	DIO_setPinDirection(DIO_PORTB, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
}

s8 prevOperator =0, intArray[10], digits =0, result =0, number =0;


void Calculate(){
	u8 i;
	//-----------------store number-----------------
	for (i=0;i<digits;i++){
		number += intArray[digits -i -1] * pow(10,(i));
	}
	
	//-----------------Logic-----------------
	switch (prevOperator)
	{
		case 0:
		result = number;
		break;
		
		case '+':
		result += number;
		break;
		
		case '-':
		result -= number;
		break;
		
		case '*':
		result *= number;
		break;
		
		case '/':
		if (number != 0)
		{
			result /= number;
		} else if (number == 0)
		{
			LCD_clear();
			LCD_showString("Error");
			prevOperator =0;
			digits =0;
			result =0;
			number =0;
			return;
		}
		break;
	}
	
	//-----------------Show result-----------------
	LCD_clear();
	if (result == 0) {
		LCD_showChar('0'); // Display '0' if the result is zero
	} else  {
		if (result < 0)
		{
			LCD_showChar('-');
			result = -result;
		}
		
		int result_digits = (int)log10(result) + 1; // Calculate the number of digits in the result

		for (i = 0; i < result_digits; i++) {
			int divisor = pow(10, result_digits - i - 1);
			int digit = ((result) / divisor) % 10;
			LCD_showChar(digit + '0'); // Display the current digit
		}
	}
	
	//-----------------Reset-----------------
	number =0;
	digits =0;
	for(i=0; i<10; i++){
		intArray[i] =0;
	}
}

int main(void)
{
	// Initialization 
	GPIO_Pins_Init();
	LCD_init();
	KPD_init();
	
	u8 KPDKEY;
	
	while(1)
	{
		KPD_getValue(&KPDKEY);
		if (KPDKEY != KPD_NOT_PRESSED)
		{
			switch(KPDKEY)
			{
				case '/' :
				Calculate();
				LCD_showChar(KPDKEY);
				prevOperator = KPDKEY;
				break;
				
				
				
				
				
				case '*' :
				Calculate();
				LCD_showChar(KPDKEY);
				prevOperator = KPDKEY;
				break;
				
				
				
				
				
				case '+' :
				Calculate();
				LCD_showChar(KPDKEY);
				prevOperator = KPDKEY;
				break;
				
				
				
				
				
				case '-' :
				Calculate();
				LCD_showChar(KPDKEY);
				prevOperator = KPDKEY;
				break;
				
				
				
				
				
				case 'C' :
				LCD_clear();
				prevOperator =0; 
				digits =0; 
				result =0;
				number =0;
				break;
				
				
				

				case '=' :
				Calculate();
				prevOperator =0;
				result =0;
				break;
				
				
			
			
				default :
				intArray[digits] = KPDKEY - '0'; // The conversion from ascii
				digits ++;
				LCD_showChar(KPDKEY);

			}
		}
	}
}