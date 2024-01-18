#ifndef _FIFO_H_
#define _FIFO_H_

#include <stdint.h>

#define el_type uint8_t
#define width 5

typedef struct
{
    el_type length;
    el_type count;
    el_type *base;
    el_type *head;
    el_type *tail;
} FIFO_BUF_t;

typedef enum
{
    FIFO_NO_ERROR,
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL
} FIFO_STATUS;

FIFO_STATUS Fifo_Init(FIFO_BUF_t *fifo_buf, el_type *buf, uint32_t length);
FIFO_STATUS Fifo_Enqueue(FIFO_BUF_t *fifo_buf, el_type item);
FIFO_STATUS Fifo_Dequeque(FIFO_BUF_t *fifo_buf, el_type *item);
FIFO_STATUS Fifo_IsFull(FIFO_BUF_t *fifo_buf);
void Print_Fifo(FIFO_BUF_t *fifo_buf);

#endif
