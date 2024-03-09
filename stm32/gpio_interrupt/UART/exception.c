/* ======================= includes ========================== */
#include "mystring.h"
#include "exception.h"
#include "key.h"
#include "exti.h"
#include "nvic.h"
#include <stdio.h>

/* ======================= defines ========================== */
#define SCB_BASE_ADDR  0xE000ED00
#define SCB_CFSR_UNDEFINSTR_POS 16U
#define EXCEPTION_STACK_PC  6U

/*======================== functions ========================== */
void HardFault_Handler(unsigned int *pStack)
{
    puts("HardFault_Handler\n\r");
    volatile SCB_Type *pSCB = (volatile SCB_Type *)SCB_BASE_ADDR;
    puthex(pSCB->CFSR);

    put_s_hex("R0  = ", pStack[0]);
    put_s_hex("R1  = ", pStack[1]);
    put_s_hex("R2  = ", pStack[2]);
    put_s_hex("R3  = ", pStack[3]);
    put_s_hex("R12 = ", pStack[4]);
    put_s_hex("LR  = ", pStack[5]);
    put_s_hex("PC  = ", pStack[6]);
}

void UsageFaultEnable(void)
{
   volatile SCB_Type *pSCB = (volatile SCB_Type *)SCB_BASE_ADDR;
   pSCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk;
}

void UsageFault_Handler(unsigned int *pStack)
{
    volatile SCB_Type *pSCB = (volatile SCB_Type *)SCB_BASE_ADDR;
    puts("UsageFault_Handler\n\r");
    puthex(pSCB->CFSR);

    /* Clear the bit UNDEFINSTR */
    pSCB->CFSR |= pSCB->CFSR;
    puts("\n\r");
    puthex(pSCB->CFSR);
    puts("\n\r");

    /* Points LR to the next instruction */
    pStack[EXCEPTION_STACK_PC] += 4U;

    put_s_hex("R0  = ", pStack[0]);
    put_s_hex("R1  = ", pStack[1]);
    put_s_hex("R2  = ", pStack[2]);
    put_s_hex("R3  = ", pStack[3]);
    put_s_hex("R12 = ", pStack[4]);
    put_s_hex("LR  = ", pStack[5]);
}

void SVCall_Handler(void)
{
    puts("SVCall_Handler\n\r");
}

void EXTI15_10_IRQHandler(void)
{
    //puts("EXTI15_10_IRQHandler\n\r");
    if (!KEY_Inspect())
    {
        puts("\x1b[31m KEY[PB14] is pressed!\n\r \x1b[0m");
    }
    else
    {
        puts("\x1b[32m KEY[PB14] is released!\n\r \x1b[0m");
    }

    /* Clear the pending interrupt
     * NOTE: both EXTI and NVIC have the interrupt pending status registers
     *       which need to be cleared both
     */
    EXTI_Clear_IRQ();
    NVIC_ClearIRQ();
}