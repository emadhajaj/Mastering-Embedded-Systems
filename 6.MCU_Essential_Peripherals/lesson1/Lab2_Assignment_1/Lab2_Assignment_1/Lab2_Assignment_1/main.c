/*
 * Lab2_Assignment_1.c
 *
 * Created: 2/14/2024 6:47:24 AM
 * Author : Emad Hajaj
 */ 

#define F_CPU 8000000UL


#include <avr/io.h>
#include <util/delay.h>



// ========================= Utils =========================

#define SET_BIT(reg, bit)          reg |= (1<<bit)
#define CLEAR_BIT(reg, bit)        reg &= ~(1<<bit)
#define TOGGLE_BIT(reg, bit)       reg ^= (1<<bit)



// ========================= Registers =========================

// PORT A
#define  PORTA                    *(volatile unsigned int*)(0x3B)
#define  DDRA                     *(volatile unsigned int*)(0x3A)
#define  PINA                     *(volatile unsigned int*)(0x39)


// ========================= Initialization =========================

void GPIO_init(){
	// Port A Output
	DDRA = 0xff;
}

// ========================= LED =========================

void LED_ON(int led){
	SET_BIT(PORTA, led);
}


void LED_OFF(int led){
	CLEAR_BIT(PORTA, led);
}



int main(void)
{
    GPIO_init();
	
	// All LEDs off
	PORTA = 0x0;
	
	int i;
    while (1) 
    {
		for (i=0; i<8; i++)
		{
			LED_ON(i);
			_delay_ms(50);
		}
		
		for (i=0; i<8; i++)
		{
			LED_OFF(7-i);
			_delay_ms(50);
		}
    }
}

