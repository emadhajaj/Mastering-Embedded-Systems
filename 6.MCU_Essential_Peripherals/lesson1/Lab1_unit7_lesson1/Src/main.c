/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>


// ================== Registers =======================

// RCC
#define RCC_BASE        0x40021000
#define RCC_APB2ENR     *(volatile uint32_t *)(RCC_BASE  + 0x18)
#define RCC_IOPAEN      (1<<2)
#define RCC_AFIOEN      (1<<0)


// GPIOA
#define GPIOA_Base      0x40010800
#define GPIOA_CRL       *(volatile unsigned int*)(GPIOA_Base + 0x00)
#define GPIOA_CRH       *(volatile unsigned int*)(GPIOA_Base + 0x04)
#define GPIOA_IDR       *(volatile unsigned int*)(GPIOA_Base + 0x08)
#define GPIOA_ODR       *(volatile unsigned int*)(GPIOA_Base + 0x0C)
#define GPIOA_BSRR      *(volatile unsigned int*)(GPIOA_Base + 0x10)
#define GPIOA_BRR       *(volatile unsigned int*)(GPIOA_Base + 0x14)
#define GPIOA_LCKR      *(volatile unsigned int*)(GPIOA_Base + 0x18)


// GPIOB
#define GPIOB_Base      0x40010C00
#define GPIOB_CRL       *(volatile unsigned int*)(GPIOB_Base + 0x00)
#define GPIOB_CRH       *(volatile unsigned int*)(GPIOB_Base + 0x04)
#define GPIOB_IDR       *(volatile unsigned int*)(GPIOB_Base + 0x08)
#define GPIOB_ODR       *(volatile unsigned int*)(GPIOB_Base + 0x0C)
#define GPIOB_BSRR      *(volatile unsigned int*)(GPIOB_Base + 0x10)
#define GPIOB_BRR       *(volatile unsigned int*)(GPIOB_Base + 0x14)
#define GPIOB_LCKR      *(volatile unsigned int*)(GPIOB_Base + 0x18)




// ================== Initialization =======================

void clock_Init(){
	// I/O port A clock enable
	RCC_APB2ENR |= RCC_IOPAEN;

	// I/O port B clock enable
	RCC_APB2ENR |= (1<<3);
}



void GPIO_Init(){
	// GPIOA
	GPIOA_CRL = 0x0;

	// A1 Floating input
	GPIOA_CRL |= (0b01<<6);

	// A13 Floating input
	GPIOA_CRH &= ~(0b11<<20);
	GPIOA_CRH |= (0b01<<22);



	// GPIOB
	GPIOB_CRL = 0x0;

	// B1 Output push-pull
	GPIOB_CRL &= ~(0b11<<6);
	GPIOB_CRL |= (0b01<<4);

	// B13 Output push-pull
	GPIOB_CRH |= (0b01<<20);
	GPIOB_CRH &= ~(0b11<<22);
}




//========================== LED ==========================

void LED_TOGGLE(int led){
	if (led == 0)
	{
		GPIOB_ODR   ^= (1<<1);
	}
	else if (led == 1)
	{
		GPIOB_ODR   ^= (1<<13);
	}

}




int main(void)
{
	clock_Init();
	GPIO_Init();


	int i;

	while(1){
		// toggle led 0 by button 0
		if ((GPIOA_IDR & (1 << 1) >> 1) == 0) {
			LED_TOGGLE(0);
			while((GPIOA_IDR & (1 << 1) >> 1) == 0){}   //Keep on
		}


		// toggle led 1 by button 1
		if ((GPIOA_IDR & (1 << 13) >> 13) == 0) {
			LED_TOGGLE(1);
		}

		for (i = 0; i < 1000; ++i){}           //delay
	}
}


