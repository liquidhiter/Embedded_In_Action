/*====================== includes ========================== */
#include "uart.h"

/* ======================= defines ========================== */
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof(x[0]))
#define size_t unsigned int

/* ======================= globals ========================== */
/* Can't use global variable ? */
// static USART *pUSART1 = (USART *)USART1_BASE_ADDR;

int main(void)
{
    const char pData[] = "Sending from Maxin's powerful desktop!\n\r";
    unsigned int lenOfData = SIZE_OF_ARRAY(pData);

    /* Initialize UART */
    uart_init();

    /* Send all characters one by one */
    for (size_t i = 0; i < lenOfData; ++i)
    {
        uart_send(pData[i]);
    }

    return 0;
}
