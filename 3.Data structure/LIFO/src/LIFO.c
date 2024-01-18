#include "LIFO.h"

LIFO_status LIFO_Init     (LIFO_buf_t* lifoBuf, unsigned int* buf, unsigned int len){
	if (buf == NULL)
		return LIFO_Null;

	lifoBuf->base   = buf;
	lifoBuf->head   = buf;
	lifoBuf->length = len;
	lifoBuf->count  = 0;

	return LIFO_no_error;
}

LIFO_status LIFO_Add_items(LIFO_buf_t* lifoBuf, unsigned int item){

	// Check valid
	if(!lifoBuf->base || !lifoBuf->head) // if not exist
		return LIFO_Null;

	// Check full
	if(lifoBuf->count == lifoBuf->length)
		return LIFO_full;

	// Add
	*(lifoBuf->head) = item;
	lifoBuf->head++;
	lifoBuf->count++;

	return LIFO_no_error;
}

LIFO_status LIFO_Get_items(LIFO_buf_t* lifoBuf, unsigned int* item){

	// Check valid
	if(!lifoBuf->base || !lifoBuf->head) // if not exist
		return LIFO_Null;

	// Check empty
	if(lifoBuf->count == 0)
		return LIFO_empty;

	// Get
	lifoBuf->head--; //the head is pointing at a place to store the item so you have to go back one step to read the last value
	*item = *lifoBuf->head;
	lifoBuf->count--;

	return LIFO_no_error;
}
