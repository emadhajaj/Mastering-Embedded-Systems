#include "uart.h"
#include <stdio.h>

unsigned char string_buffer[100] = "learn-in-depth:Emad.Hajaj";

void main(void)
{
	Uart_Send_String (string_buffer);
}
