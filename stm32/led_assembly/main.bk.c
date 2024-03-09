//#define RCC_APB2ENR  (0x40021000 + 0x18)
//#define GPIOB_BASE   (0x40010C00)
//#define GPIOB_CRL    (GPIOB_BASE + 0)
//#define GPIOB_ODR    (GPIOB_BASE + 0X0c)

#define RCC_APB2ENR		(0x40021000 + 0x18)
#define GPIOC_BASE		(0x40011000)
#define GPIOC_CRH			(GPIOC_BASE + 0x04)
#define GPIOC_ODR     (GPIOC_BASE + 0X0C)

/* Function Prototype */
void delay(volatile int i);

void delay(volatile int i)
{
	while (i--);
}

int mymain(void)
{
	volatile unsigned int *pRccApb2Enr;
	volatile unsigned int *pGpiocCrH;
	volatile unsigned int *pGpiocOdr;
	
	pRccApb2Enr = (volatile unsigned int *)RCC_APB2ENR;
	pGpiocCrH   = (volatile unsigned int *)GPIOC_CRH;
	pGpiocOdr   = (volatile unsigned int *)GPIOC_ODR;
	
	*pRccApb2Enr |= (1<<4);

  *pGpiocCrH |= (1<<20);
	
	while (1)
	{
    *pGpiocOdr |= (unsigned int)(1<<13);
		delay(100000);
    *pGpiocOdr &= (unsigned int)~(1<<13);
		delay(100000);
	}
	return 0;
}

