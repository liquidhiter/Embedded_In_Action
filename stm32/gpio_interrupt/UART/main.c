/*====================== includes ========================== */
#include "util.h"
#include "uart.h"
#include "mystring.h"
#include <string.h>
#include "key.h"
#include "exti.h"
#include "nvic.h"
#include "peipheral_reg_def.h"


/* ======================= globals ========================== */
/* Can't use global variable ?
 * Non-const: requires data relocation
 */
// static USART *pUSART1 = (USART *)USART1_BASE_ADDR;
char g_Char = 'A';
const char g_CharConst = 'B';
const char RECEIVED_MSG[] = "Received => ";
char g_CodeChar[4] = {0, 0, 0, 0};
int	g_Cnt;

/* ======================= defines ========================== */
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof(x[0]))
#define size_t unsigned int

/* ======================= prototypes ========================== */
void systemInit(void);


/* ======================= functions ========================== */
static inline void uart_receive(void)
{
    uart_print(RECEIVED_MSG, SIZE_OF_ARRAY(RECEIVED_MSG));
}

static inline void uart_println(const char c)
{
    /* Send the given char */
    uart_send(c);
    /* Move the cursor to the start of the next line */
    uart_send('\n');
    uart_send('\r');
}

int mymain(void)
{
    const char pData[] = "\x1b[34m Sending from Maxin's powerful desktop!\n\r \x1b[0m";
    unsigned int lenOfData = SIZE_OF_ARRAY(pData);
    char c;

    /* Initialize UART */
    uart_init();

    /* Initialize KEY: GPIO and AFIO */
    KEY_Init();

    /* Initialize the EXTI */
    EXTI_Init();

    /* Enable global interrupt */
		NVIC_EnableIRQ();

#if 0
    /* Send two global char */
    uart_println(g_Char);
    uart_println(g_CharConst);
#endif

#if 0
    /* Send two global variable: one zero-initialized and the other un-initialized */
    uart_println(g_CodeChar[0]);
    uart_println(g_Cnt);
#endif

#if 0
    /* Print the addresses of two global objects */
    put_s_hex("Address of g_Char = ", (void*)&g_Char - (void*)0);
    put_s_hex("Address of g_CharConst = ", (void*)&g_CharConst - (void*)0);
    put_s_hex("Address of g_CodeChar = ", (void*)&g_CodeChar - (void*)0);
    put_s_hex("Address of g_Cnt = ", (void*)&g_Cnt - (void*)0);

    put_s_hex("Value of g_Cnt = ", g_Cnt);
    put_s_hex("Value of g_CodeChar[0] = ", g_CodeChar[0]);
#endif

#if 1
    /* Send all characters one by one */
    for (size_t i = 0; i < lenOfData; ++i)
    {
        uart_send(pData[i]);
    }
#endif

#ifdef __TEST_KEY_CFG__
    /* Check KEY configuration */
    GPIO_S *pGpioB = GPIOB_STM32F103;
    
    while (1) {
        /* Read the key input register */
        int keyEn = (pGpioB->GPIOx_IDR) & (1<<14);
        if (keyEn == 0)
        {
            puts("Key pressed!\r\n");
        }
        else
        {
            puts("Key released!\r\n");
        }
    }
#endif

#if 1
    while (1)
    {
        /* Fetch received characters */
        c = uart_get();
        /* Print "Received => " to improve readability */
        uart_receive();
        uart_println(c);
    }
#endif

    return 0;
}

/**!SECTION
 * @fn     systemInit
 */
void systemInit(void)
{
    extern char Image$$RW_IRAM1$$Base[];
    extern int Image$$RW_IRAM1$$Length;
    extern char Load$$RW_IRAM1$$Base[];

    extern char Image$$RW_IRAM1$$ZI$$Base[];
    extern int Image$$RW_IRAM1$$ZI$$Length;

    extern char Image$$ER_IROM1$$Base[];
    extern int Image$$ER_IROM1$$Length;
    extern char Load$$ER_IROM1$$Base[];

    /* Relocate text section (RO) */
    memcpy(Image$$ER_IROM1$$Base, Load$$ER_IROM1$$Base, (size_t)&Image$$ER_IROM1$$Length);

    /* Clear .bss */
    memset(Image$$RW_IRAM1$$ZI$$Base, 0x00, (size_t)&Image$$RW_IRAM1$$ZI$$Length);

    /* Relocate data section (RW) */
    memcpy(Image$$RW_IRAM1$$Base, Load$$RW_IRAM1$$Base, (size_t)&Image$$RW_IRAM1$$Length);
}