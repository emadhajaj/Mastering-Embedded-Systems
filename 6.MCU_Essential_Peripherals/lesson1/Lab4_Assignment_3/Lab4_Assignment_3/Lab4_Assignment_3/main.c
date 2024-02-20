/*
 * Lab4_Assignment_3.c
 *
 * Created: 2/14/2024 10:54:10 AM
 * Author : Emad Hajaj
 */ 

#define F_CPU 8000000UL


#include <avr/io.h>
#include <util/delay.h>



// ========================= Utils =========================

#define SET_BIT(reg, bit)          reg |= (1<<bit)
#define CLEAR_BIT(reg, bit)        reg &= ~(1<<bit)
#define TOGGLE_BIT(reg, bit)       reg ^= (1<<bit)
#define GET_BIT(reg, bit)          ((reg>>bit) &1)



// ========================= Registers =========================

// PORT A
#define  PORTA                    *(volatile unsigned int*)(0x3B)
#define  DDRA                     *(volatile unsigned int*)(0x3A)
#define  PINA                     *(volatile unsigned int*)(0x39)

// PORT B
#define  PORTB                    *(volatile unsigned int*)(0x38)
#define  DDRB                     *(volatile unsigned int*)(0x37)
#define  PINB                     *(volatile unsigned int*)(0x36)


// ========================= Initialization =========================

void GPIO_init(){
	// Port A Output
	DDRA = 0xff;
	
	// Port B Input with pull-up resistor
	DDRB = 0x0;
	PORTB = 0xff;
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
	
	int count =0, flag=0;
	while (1)
	{
		
		if ((GET_BIT(PINB, 0) == 0) && (flag == 0)){
			LED_ON(count);
			if (count <8)
			{
				count++;
			}
			
			// protection
			flag++;
		}
		
		if ((GET_BIT(PINB, 1) == 0) && (flag == 0)){
			LED_OFF(count);
			if (count >0)
			{
				count--;
			}
			
			// protection 
			flag++;
		}
		
		if ((GET_BIT(PINB, 0) == 1) && (GET_BIT(PINB, 1) == 1)){
			flag =0;
		}
	}
}

