#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#define uint32_t unsigned int

typedef struct
{
    volatile uint32_t STK_CTRL;
    volatile uint32_t STK_LOAD;
    volatile uint32_t STK_VAL;
    volatile uint32_t STK_CALIB;
} SysTick_S;

#define SYSTICK_BASE   (0xE000E010)
#define SYSTICK_M3     ((SysTick_S*)SYSTICK_BASE)
#define SYSTICK_8M_1S_RELOAD_VAL    (8000000U)

#endif