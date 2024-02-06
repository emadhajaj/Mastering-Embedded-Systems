#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>

//type definitions
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
} LIFO_buf_t;


typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
} LIFO_status;


//APIs
LIFO_status LIFO_Init     (LIFO_buf_t* lifoBuf, unsigned int* buf, unsigned int len); // we pass the array we are gonna use as a LIFO
LIFO_status LIFO_Add_items(LIFO_buf_t* lifoBuf, unsigned int item);
LIFO_status LIFO_Get_items(LIFO_buf_t* lifoBuf, unsigned int* item);// we passed item as a pointer to get the value in it

#endif /* LIFO_H_ */
