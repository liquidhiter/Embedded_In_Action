#ifndef UART_H_
#define UART_H_

/* ======================= typedefs ========================== */
typedef unsigned int uint32_t ;

/* Easy manipulation of USART registers */
typedef struct
{
    volatile uint32_t SR;    /*!< USART Status register, Address offset: 0x00 */
    volatile uint32_t DR;    /*!< USART Data register,   Address offset: 0x04 */
    volatile uint32_t BRR;   /*!< USART Baud rate register, Address offset: 0x08 */
    volatile uint32_t CR1;   /*!< USART Control register 1, Address offset: 0x0C */
    volatile uint32_t CR2;   /*!< USART Control register 2, Address offset: 0x10 */
    volatile uint32_t CR3;   /*!< USART Control register 3, Address offset: 0x14 */
    volatile uint32_t GTPR;  /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} USART;

/* ======================= prototypes ========================== */
void uart_init(void);
int uart_send(char c);
int uart_get(void);

#endif
