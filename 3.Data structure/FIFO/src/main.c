#include <stdio.h>
#include "fifo.h"

el_type uart_buf[width];

int main(void)
{
    FIFO_BUF_t Fifo_Uart;
    el_type i, temp = 0;

    if (Fifo_Init(&Fifo_Uart, uart_buf, 5) == FIFO_NO_ERROR)
    {
        printf("\nFIFO Init ..... Done :)\n");
    }
    else
    {
        printf("\n FIFO Init ..... Faild!!!\n");
    }

    for (i = 0; i < 7; i++)
    {
        printf("Fifo Enqueue(%x)\n", i);
        if (Fifo_Enqueue(&Fifo_Uart, i) == FIFO_NO_ERROR)
        {
            printf("Fifo Enqueue..... Done :)\n");
        }
        else
        {
            printf("Fifo Enqueue..... Faild !!!\n");
        }
    }

    Print_Fifo(&Fifo_Uart);

    if (Fifo_Dequeque(&Fifo_Uart, &temp) == FIFO_NO_ERROR)
    {
        printf("Fifo Dequeue (%x)...Done\n", temp);
    }
    if (Fifo_Dequeque(&Fifo_Uart, &temp) == FIFO_NO_ERROR)
    {
        printf("Fifo Dequeue (%x)...Done\n", temp);
    }

    Print_Fifo(&Fifo_Uart);

    return 0;
}
