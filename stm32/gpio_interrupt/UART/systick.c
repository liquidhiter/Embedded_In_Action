#include "uart.h"
#include "exception.h"
#include "systick.h"
#include "led.h"
#include "mystring.h"

void SysTick_Init(void)
{
    SysTick_S *pSysTick = (SysTick_S*)SYSTICK_BASE;

    /* Set the current value */
    pSysTick->STK_VAL = SYSTICK_8M_1S_RELOAD_VAL;

    /* Set the reload register */
    pSysTick->STK_LOAD = SYSTICK_8M_1S_RELOAD_VAL;

    /* Set the clock source and enable the SysTick
     * 1U<<2: Processor clock (AHB)
     * 1U<<1: Counting down to zero to asserts the SysTick exception request
     * 1U<<0: Counter enabled
     */
    pSysTick->STK_CTRL |= (1U << 2) | (1U << 1) | (1U << 0);
}

void SysTick_Handler(void)
{
		puts("SysTick_Handler\n\r");
    
	  SCB_Type *pSCB = (SCB_Type *)SCB_BASE_ADDR;
    /* Toggle the LED */
    static int led_on = 0;
    if (led_on)
    {
        /* Turn off the LED */
        LED_Toggle(0);
    }
    else
    {
        /* Turn on the LED */
        LED_Toggle(1);
    }
    
    led_on = !led_on;

    /* Clear the exception status */
    pSCB->ICSR |= (1U << 25);
}