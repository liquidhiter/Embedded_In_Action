#include "nvic.h"

void NVIC_EnableIRQ(void)
{
    NVIC_S *pNvic = NVIC_M3;

    /*GPIO PB14: EXTI15_10_IRQHandler, 40th in the external interrupts table*/
    pNvic->ISER[1] |= (1U << 8);
}

void NVIC_ClearIRQ(void)
{
    NVIC_S *pNvic = NVIC_M3;

    /*GPIO PB14: EXTI15_10_IRQHandler, 40th in the external interrupts table*/
    pNvic->ICPR[1] |= (1U << 8);
}