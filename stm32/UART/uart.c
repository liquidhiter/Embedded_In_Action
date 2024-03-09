/*====================== includes ========================== */
#include "uart.h"

/* ======================= defines ========================== */
#define USART1_BASE_ADDR 0x40013800
#define RCC_APB2ENR	(0x40021000 + 0x18)
#define GPIOA_BASE (0x40010800)
#define GPIOA_CRH (GPIOA_BASE + 0x04)
#define _IO (volatile uint32_t *)
#define USART1_DIV_MANTISSA 4U
#define USART1_DIV_FRACTION 5U

/* ======================= functions ========================== */

/**!SECTION: UART Initialization
 * @brief  Initialize UART
 */
void uart_init(void)
{
    /* USART1 */
    volatile USART *pUSART1 = (volatile USART *)USART1_BASE_ADDR;

    volatile uint32_t *pRCCAPB2ENR =  (volatile uint32_t *) RCC_APB2ENR;
    volatile uint32_t *pGPIOACRH =  (volatile uint32_t *) GPIOA_CRH;
    
    /* Enable clock for USART1  */
    *pRCCAPB2ENR |= (1U << 2) | (1U << 14);

    /* Configure PA9  to output mode USART1 */
    *pGPIOACRH &= ~((3U << 4) | (3U << 6)); /* Reset value is 0x4444,4444, clear bits to ensure no conflicts */
    *pGPIOACRH |= (1U << 4) | (2U << 6); /* MODE(0x01): output mode, max speed 10 MHz, CNF(0x10): push-pull ? */

    /* Configure PA10 to input mode USART1 */
    *pGPIOACRH &= ~((3U << 8) | (3U << 10)); /* Reset value is 0x4444,4444, clear bits to ensure no conflicts */
    *pGPIOACRH |= (0U << 8) | (1U << 10); /* MODE(0x00): input mode, CNF(0x01): floating input ? */

    /* Set baud rate 
     * 115200 = 8M (fclk) / 16 / USARTDIV
     * USARTDIV = 4.34
     * DIV_Mantissa = 4
     * DIV_Fraction = 0.34 * 16 = 5.44 = 5
     * Actual baud rate = 115942
     */
    pUSART1->BRR = (USART1_DIV_MANTISSA << 4) | (USART1_DIV_FRACTION);

    /* Set data frame and enable the USART1 */
    pUSART1->CR1 = (1U << 13) | (0U << 12) | (0U << 10) | (1U << 3) | (1U << 2);
    pUSART1->CR2 &= ~(3U << 12);
}

/**!SECTION UART send 
 * 
*/
int uart_send(char c)
{
    /* USART1 */
    volatile USART *pUSART1 = (volatile USART *)USART1_BASE_ADDR;

    /* Wait until the data in the TX buffer have been sent to the shift register */
    while  ((pUSART1->SR & (1U << 7)) == 0);

    /* Put data into the TX buffer */
    pUSART1->DR = c;

    return c;
}

/**!SECTION UART receive
 * 
 */
int uart_get(void)
{
    /* USART1 */
    volatile USART *pUSART1 = (volatile USART *)USART1_BASE_ADDR;

    /* Wait until the data in the RX buffer are ready to read */
    while ((pUSART1->SR & (1U << 5)) == 0);

    return pUSART1->DR & 0xFF;
}
