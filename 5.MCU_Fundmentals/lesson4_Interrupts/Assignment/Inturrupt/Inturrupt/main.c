/*
 * Inturrupt.c
 *
 * Created: 2/10/2024 7:39:24 AM
 * Author : Emad Hajaj
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



//========================== Registers    (from register summary) ==========================

// GPIO
#define PORTB   *(volatile unsigned int *)(0x38)
#define DDRB    *(volatile unsigned int *)(0x37)
#define PORTD   *(volatile unsigned int *)(0x32)
#define DDRD    *(volatile unsigned int *)(0x31)


// Interrupt
#define MCUCR   *(volatile unsigned int *)(0x55)
#define MCUCSR  *(volatile unsigned int *)(0x54)
#define GICR    *(volatile unsigned int *)(0x5B)
#define GIFR    *(volatile unsigned int *)(0x5A)





//========================== Initialization ==========================

void Clk_init(){
	/* The device is shipped with CKSEL = “0001” and SUT = “10”. The default clock source setting is    therefore the 1MHz Internal RC Oscillator with longest startup time. This default setting ensures    that all users can make their desired clock source setting using an In-System or Parallel    Programmer.*/
}



void GPIO_init(){
	// LED Pins output
	DDRD   |= (1<<5);
	DDRD   |= (1<<6);
	DDRD   |= (1<<7);
	
	// INT Pins input
	DDRB   &= ~(1<<2);
	DDRD   &= ~(1<<2);
	DDRD   &= ~(1<<3);
}



void EXI_init(){
	//External Interrupt 0 (INT0) - PD2. >> irq occur when “any logical change”
	GICR   |= (1<<6);  //Bit 6 – INT0: External Interrupt Request 0 Enable
	MCUCR  |= (01<<0); //0 1 Any logical change on INT0 generates an interrupt request.
	
	
	//External Interrupt 1 (INT1) - PD3. >> irq occur when “rising edge”
	GICR   |= (1<<7);  //Bit 7 – INT1: External Interrupt Request 1 Enable
	MCUCR  |= (11<<2); //1 1 The rising edge of INT1 generates an interrupt request.
	
	
	//External Interrupt 2 (INT2) - PB2. >> irq occur when “Falling edge”
	GICR   |= (1<<5);  //Bit 5 – INT2: External Interrupt Request 2 Enable
	MCUCSR &= ~(1<<6); //If ISC2 is written to zero, a falling edge on INT2 activates the interrupt.
}





//========================== LED ==========================

void LED_ON(int led){
	if (led == 0)
	{ 
		PORTD   |= (1<<5);
	} 
	else if (led == 1)
	{
		PORTD   |= (1<<6);
	} 
	else if (led == 2)
	{
		PORTD   |= (1<<7);
	}
}


void LED_OFF(int led){
	if (led == 0)
	{
		PORTD   &= ~(1<<5);
	}
	else if (led == 1)
	{
		PORTD   &= ~(1<<6);
	}
	else if (led == 2)
	{
		PORTD   &= ~(1<<7);
	}
}







//========================== MAIN ==========================


int main(void)
{
	Clk_init();
	GPIO_init();
	EXI_init();
	
	sei(); // Enable global interrupts
	
	
    while (1) 
    {
		//We have also 3 leds (PD5,6,7) (led0,1,2). 
		//Each interrupt just make the led 0N for 1 sec 
		//The main function is always make all the leds off
		LED_OFF(0);
		LED_OFF(1);
		LED_OFF(2);
    }
}






//========================== ISR ==========================

ISR(INT0_vect){
	LED_ON(0);
	_delay_ms(1000);
}

ISR(INT1_vect){
	LED_ON(1);
	_delay_ms(1000);
}

ISR(INT2_vect){
	LED_ON(2);
	_delay_ms(1000);
}