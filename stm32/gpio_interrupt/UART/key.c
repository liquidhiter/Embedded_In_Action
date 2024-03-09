/*================================== Includes ========================== */
#include "mystring.h"
#include "key.h"
#include "peipheral_reg_def.h"

/*================================== Functions ========================== */
/*!SECTION
 * 
 * @brief  KEY Initialization
 */
void KEY_Init(void)
{
    RCC_S *pRcc = RCC_STM32F103;
    volatile GPIO_S *pGpioB = GPIOB_STM32F103;
    AFIO_S *pAfio = AFIO_STM32F103;

    /* Enable the clock for GPIOB */
    pRcc->RCC_APB2ENR |= (1U << 3);

    /* Configure GPIOB pin 14 to be input */
    pGpioB->GPIOx_CRH &= (0x00 << 24);
    pGpioB->GPIOx_CRH |= (0x01 << 26);

    /* Configure APIO */
    pRcc->RCC_APB2ENR |= (1U << 0);
    pAfio->EXTICR[3] |= (0x0001 << 8);
}

unsigned char KEY_Inspect(void)
{
    volatile GPIO_S *pGpioB = GPIOB_STM32F103;
    return (pGpioB->GPIOx_IDR >> 14U) & 0x1;
}