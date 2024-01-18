typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>

// register address
#define RCC_BASE        0x40021000
#define GPIOA_BASE      0x40010800
#define RCC_APB2ENR     *(volatile uint32_t *)(RCC_BASE  + 0x18)
#define GPIOA_CRH      *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR       *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

// bit fields
#define RCC_IOPAEN (1<<2)
#define GPIOA13    (1UL<<13)
typedef union {
	vuint32_t all_fields;
	struct {
		vuint32_t reserved:13 ;
		vuint32_t P_13:1 ;
	} Pin;
} R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C) ;
unsigned char q_variables[3] = {1,2,3};
unsigned char const const_variables[3] = {1,2,3};
unsigned char bss_variables[3];

//If you want to use malloc only you can write a fucntion for it directly without including stdlib.h but here we want to add sbrk
//you must define heap section in the linker file
#define heap_width 500
void* _sbrk(int incr){ // malloc return ptr, takes the size of memory to alloc
	static unsigned char* heap_ptr = NULL;
	unsigned char* alloc_start_ptr = NULL;
	extern unsigned int _E_bss; //symbol
	extern unsigned int _E_heap; //symbol

	// first time initialized
	if (heap_ptr == NULL){
		heap_ptr = (unsigned char*)& _E_bss;
	}

	// Make sure it is in the heap boundries
	if ((heap_ptr + incr) > ((unsigned char*)&_E_heap)){
		return (void*)NULL;
	}

	// book the size
	alloc_start_ptr = heap_ptr;
	heap_ptr += incr; // update the heap ptr
	return (void*)alloc_start_ptr;
}

int main(void)
{
	int* p = (int*)malloc(4);
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH    &= 0xff0fffff;
	GPIOA_CRH    |= 0x00200000;

	int i;
	while(1){
		R_ODR->Pin.P_13 = 1;
		for ( i = 0; i<5000;i++);
		R_ODR->Pin.P_13 = 0;
		for ( i = 0; i<5000;i++);
	}
	free(p);


	return 0;
}
