#include "exti.h"

void EXTI_Init(void)
{
    EXTI_S *pExti = EXTI_STM32F103;
    
    //pExti->EXTI_EMR &= (0 << 14);
    pExti->EXTI_RTSR |= (1U << 14);
    pExti->EXTI_FTSR |= (1U << 14);
	  /* Configure EXTI line 14 */
    pExti->EXTI_IMR |= (1U << 14);
}

void EXTI_Clear_IRQ(void)
{
    EXTI_S *pExti = EXTI_STM32F103;
    
    /* Clear the bit corresponding to the active interrupt in the pending status reg */
    pExti->EXTI_PR |= (1U << 14);
}