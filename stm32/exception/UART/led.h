#ifndef _LED_H__
#define _LED_H__

/* ==================== RCC and LED Register Address =====================*/
#define RCC_BASE        (0x40021000)
#define GPIOC_BASE      (0x40011000)

#define uint32_t unsigned int

typedef struct
{
    volatile uint32_t GPIOx_CRL;
    volatile uint32_t GPIOx_CRH;
    volatile uint32_t GPIOx_IDR;
    volatile uint32_t GPIOx_ODR;
    volatile uint32_t GPIOx_BSRR;
    volatile uint32_t GPIOx_BRR;
    volatile uint32_t GPIOx_LCKR;
} GPIO_S;

#define GPIOC_STM32F103 ((GPIO_S*)GPIOC_BASE)

typedef struct
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_AHBENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    volatile uint32_t RCC_AHBRSTR;
    volatile uint32_t RCC_CFGR2;
} RCC_S;

#define RCC_STM32F103 ((RCC_S*)RCC_BASE)

void LED_Init(void);
void LED_Toggle(unsigned int LED_Status);
#endif