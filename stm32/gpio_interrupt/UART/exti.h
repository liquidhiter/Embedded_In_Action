#pragma __EXTI_H__

#define uint32_t unsigned int
typedef struct
{
    volatile uint32_t EXTI_IMR;
    volatile uint32_t EXTI_EMR;
    volatile uint32_t EXTI_RTSR;
    volatile uint32_t EXTI_FTSR;
    volatile uint32_t EXTI_SWIER;
    volatile uint32_t EXTI_PR;
} EXTI_S;

#define EXTI_BASE_ADDR_STM32F103 (0x40010400)
#define EXTI_STM32F103 ((EXTI_S*)EXTI_BASE_ADDR_STM32F103)

void EXTI_Init(void);
void EXTI_Clear_IRQ(void);