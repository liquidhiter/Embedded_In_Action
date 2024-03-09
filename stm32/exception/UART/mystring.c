#include "uart.h"
int puts(const char *s)
{
    while (*s)
    {
        uart_send(*s);
        s++;
    }
    return 0;
}

void puthex(unsigned int val)
{
    /* 0x76543210 */
    int i, j;

    puts("0x");
    for (i = 7; i >= 0; i--)
    {
        j = (val >> (i*4)) & 0xf;
        if ((j >= 0) && (j <= 9))
            uart_send('0' + j);
        else
            uart_send('A' + j - 0xA);
    }	
}

void put_s_hex(const char *s, unsigned int val)
{
    puts(s);
    puthex(val);
    puts("\r\n");
}

