/*
 * Address of the PB14 and PC13
 */
#define RCC_APB2ENR (0x40021000 + 0x18)

#define GPIOC_BASE  (0x40011000)
#define GPIOC_CRH   (GPIOC_BASE + 0x04)
#define GPIOC_ODR   (GPIOC_BASE + 0X0C)

#define GPIOB_BASE  (0x40010C00)
#define GPIOB_CRH   (GPIOB_BASE + 0x04)
#define GPIOB_IDR   (GPIOB_BASE + 0x08)

/** Main Entry
 * @brief  
 * @note   
 * @param  argc: 
 * @param  argv: 
 * @retval 
 */
int main(void)
{
    volatile unsigned int *pRccApb2En;
    volatile unsigned int *pGpioCCtrH;
    volatile unsigned int *pGpioCOdr;
    
    volatile unsigned int *pGpioBCtrH;
    volatile unsigned int *pGpioBIdr;

    pRccApb2En = (volatile unsigned int *)RCC_APB2ENR;
    pGpioCCtrH = (volatile unsigned int *)GPIOC_CRH;
    pGpioCOdr = (volatile unsigned int *)GPIOC_ODR;

    pGpioBCtrH = (volatile unsigned int *)GPIOB_CRH;
    pGpioBIdr = (volatile unsigned int *)GPIOB_IDR;

    /* Enable the clock for IOPB and IOPC */
    *pRccApb2En |= (1<<3) | (1<<4);

    /* Configure PC13 to be output */
    *pGpioCCtrH |= (1<<20);

    /* Configure PB14 to be floating input */
    *pGpioBCtrH &= (0x00<<24);
    *pGpioBCtrH |= (0x01<<26);

    /* main loop */
    while (1)
    {
        /* Read the key input register */
        int keyEn = (*pGpioBIdr) & (1<<14);
        if (keyEn == 0)
        {
			/* Set the PC13 output to be low */
            *pGpioCOdr &= (unsigned int) ~ (1<<13);
        }
        else
        {
            /* Set the PC13 output to be high */
            *pGpioCOdr |= (unsigned int)(1<<13);
        }
    }

    return 0;
}
