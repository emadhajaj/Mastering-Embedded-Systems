#include <stdio.h>
#include <stdlib.h>
#include "LIFO.h"

unsigned int buffer1[5];

int main(void) {

	LIFO_buf_t uartLifo, I2CLifo;

	// Static allocation
	LIFO_Init(&uartLifo, buffer1, sizeof(buffer1));

	// Dynamic allocation
	unsigned int* buffer2 = (unsigned int*)malloc(5 * sizeof(unsigned int));
	LIFO_Init(&I2CLifo, buffer2, 5);

	unsigned int i, temp=0;
	for (i = 0; i < 5; ++i){
		if( LIFO_Add_items(&uartLifo, i) == LIFO_no_error)
			printf("uartLifo add : %d \n", i);
	}

	for(i=0; i<5; i++){
		if( LIFO_Get_items(&uartLifo, &temp) == LIFO_no_error)
			printf("uartLifo get : %d \n", temp);
	}

	return 0;
}
