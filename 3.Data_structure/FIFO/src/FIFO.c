#include "fifo.h"
#include <stdio.h>

FIFO_STATUS Fifo_Init(FIFO_BUF_t *fifo_buf, el_type *buf, uint32_t length)
{
    if (buf == NULL)
        return FIFO_NULL;

    fifo_buf->head = buf;
    fifo_buf->base = buf;
    fifo_buf->tail = buf;
    fifo_buf->length = length;
    fifo_buf->count = 0;

    return FIFO_NO_ERROR;
}

FIFO_STATUS Fifo_Enqueue(FIFO_BUF_t *fifo_buf, el_type item)
{
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_NULL;

    if (Fifo_IsFull(fifo_buf) == FIFO_FULL)
    {
        return FIFO_FULL;
    }

    *(fifo_buf->head) = item;
    fifo_buf->count++;

    if (fifo_buf->head == fifo_buf->base + fifo_buf->length * sizeof(el_type))
        fifo_buf->head = fifo_buf->base;
    else
        fifo_buf->head++;

    return FIFO_NO_ERROR;
}

FIFO_STATUS Fifo_Dequeque(FIFO_BUF_t *fifo_buf, el_type *item)
{
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_NULL;

    if (fifo_buf->count == 0)
    {
        return FIFO_EMPTY;
    }

    *item = *(fifo_buf->tail);
    fifo_buf->count--;

    if (fifo_buf->tail == fifo_buf->base + fifo_buf->length * sizeof(el_type))
        fifo_buf->tail = fifo_buf->base;
    else
        fifo_buf->tail++;

    return FIFO_NO_ERROR;
}

FIFO_STATUS Fifo_IsFull(FIFO_BUF_t *fifo_buf)
{
    if (!fifo_buf->head || !fifo_buf->tail || !fifo_buf->base)
        return FIFO_NULL;

    if (fifo_buf->count == fifo_buf->length)
    {
        return FIFO_FULL;
    }

    return FIFO_NO_ERROR;
}

void Print_Fifo(FIFO_BUF_t *fifo)
{
    el_type *temp = 0;
    int i;

    if (fifo->count == 0)
    {
        printf("Fifo Is Empty !!!!\n\n");
    }
    else
    {
        temp = fifo->tail;
        printf("\n============= Print FIFO =================\n");
        for (i = 0; i < fifo->count; i++)
        {
            printf("\t %x   \n", *temp);
            temp++;
        }
        printf("=====================\n");
    }
}
