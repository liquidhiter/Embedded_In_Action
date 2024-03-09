/* ======================= includes ========================== */
#include "uart.h"
#include "util.h"

/* ======================= implementation ======================== */
void uart_print(const char* pData, unsigned int len)
{
    for (unsigned int i = 0; i < len; ++i)
    {
        uart_send(pData[i]);
    }
}

void relocate_memcpy(void* dest, void* src, unsigned int len)
{
    unsigned char *pDest;
    unsigned char *pSrc;
    
    pDest = (unsigned char *)dest;
    pSrc = (unsigned char *)src;
    while (len--)
    {
            *pDest++ = *pSrc++;
    }
}

void relocate_memset(void* dest, unsigned int len)
{
    unsigned char *pDest;
    pDest = (unsigned char *)dest;
    while (len--)
    {
            *pDest++ = 0x00;
    }
}