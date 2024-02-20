/*
 * calculator.c
 *
 * Created: 2/14/2024 11:21:24 AM
 * Author : Emad Hajaj
 */ 

#define F_CPU 8000000UL


//#include <avr/io.h>
#include <util/delay.h>


#include "ATMega32.h"
#include "UTILS.h"
#include "LCD_HD44780U.h"


// ========================= Initialization =========================

void GPIO_init(){
	// Port A Output
	DDRA = 0xff;
	
	// Port B Input with pull-up resistor
	DDRB = 0x0;
	PORTB = 0xff;
}



int main(void)
{
	
	
	/*
	GPIO_init();
	
	LCD_lcd_init();
	
	while (1) { 
		LCD_Send_A_String("Emad"); 
		LCD_clear_screen(); 
		LCD_Send_A_String("Numbers Examples:"); 
		LCD_display_real_number( 30.127); 
		LCD_Send_A_String(" "); 
		LCD_display_number(12); 
		LCD_clear_screen(); 
		_delay_ms(1000);
	}
	*/
	return 0;
}

