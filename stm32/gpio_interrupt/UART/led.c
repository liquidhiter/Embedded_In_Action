/* ======================= includes ========================== */
#include "led.h"
#include "peipheral_reg_def.h"

/* ======================= implementation ======================== */
void LED_Init()
{
    /* Configure RCC and GPIOC */
    RCC_S *pRcc = RCC_STM32F103;
    volatile GPIO_S *pGpio = GPIOC_STM32F103;
    pRcc->RCC_APB2ENR |= (1U << 4);
    pGpio->GPIOx_CRH |= (1U << 20);

    /* Set the LED off */
    pGpio->GPIOx_ODR |= (1U << 13);
}

void LED_Toggle(unsigned int LED_Status)
{
    volatile GPIO_S *pGpio = GPIOC_STM32F103;

    if (LED_Status)
    {
        /* Turn off the LED */
        pGpio->GPIOx_ODR |= (1U << 13);
    }
    else
    {
        /* Turn on the LED */
        pGpio->GPIOx_ODR &= ~(1U << 13);
    }
}