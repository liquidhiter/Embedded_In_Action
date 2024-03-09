                PRESERVE8
                THUMB

; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
				IMPORT	HardFault_Handler
				IMPORT  UsageFault_Handler
				IMPORT	SVCall_Handler
				IMPORT	SysTick_Handler
				IMPORT  EXTI15_10_IRQHandler

__Vectors       DCD     0			               ; Top of Stack
                DCD     0x08000009 ;Reset_Handler              ; Reset Handler
				DCD     0                ; NMI Handler
                DCD     HardFault_Handler_ASM          ; Hard Fault Handler
                DCD     0          ; MPU Fault Handler
                DCD     0           ; Bus Fault Handler
                DCD     UsageFault_Handler_ASM         ; Usage Fault Handler
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     SVCall_Handler             ; SVCall Handler
                DCD     0           ; Debug Monitor Handler
                DCD     0                          ; Reserved
                DCD     0             ; PendSV Handler
                DCD     SysTick_Handler            ; SysTick Handler

                ; External Interrupts
                DCD     0            ; Window Watchdog
                DCD     0             ; PVD through EXTI Line detect
                DCD     0          ; Tamper
                DCD     0             ; RTC
                DCD     0           ; Flash
                DCD     0             ; RCC
                DCD     0           ; EXTI Line 0
                DCD     0           ; EXTI Line 1
                DCD     0           ; EXTI Line 2
                DCD     0           ; EXTI Line 3
                DCD     0           ; EXTI Line 4
                DCD     0   ; DMA1 Channel 1
                DCD     0   ; DMA1 Channel 2
                DCD     0   ; DMA1 Channel 3
                DCD     0   ; DMA1 Channel 4
                DCD     0   ; DMA1 Channel 5
                DCD     0   ; DMA1 Channel 6
                DCD     0   ; DMA1 Channel 7
                DCD     0          ; ADC1 & ADC2
                DCD     0  ; USB High Priority or CAN1 TX
                DCD     0 ; USB Low  Priority or CAN1 RX0
                DCD     0        ; CAN1 RX1
                DCD     0        ; CAN1 SCE
                DCD     0         ; EXTI Line 9..5
                DCD     0        ; TIM1 Break
                DCD     0         ; TIM1 Update
                DCD     0    ; TIM1 Trigger and Commutation
                DCD     0         ; TIM1 Capture Compare
                DCD     0            ; TIM2
                DCD     0            ; TIM3
                DCD     0            ; TIM4
                DCD     0         ; I2C1 Event
                DCD     0         ; I2C1 Error
                DCD     0         ; I2C2 Event
                DCD     0         ; I2C2 Error
                DCD     0            ; SPI1
                DCD     0            ; SPI2
                DCD     0          ; USART1
                DCD     0          ; USART2
                DCD     0          ; USART3
                DCD     EXTI15_10_IRQHandler       ; EXTI Line 15..10
                DCD     0        ; RTC Alarm through EXTI Line
                DCD     0       ; USB Wakeup from suspend
                DCD     0        ; TIM8 Break
                DCD     0         ; TIM8 Update
                DCD     0    ; TIM8 Trigger and Commutation
                DCD     0         ; TIM8 Capture Compare
                DCD     0            ; ADC3
                DCD     0            ; FSMC
                DCD     0            ; SDIO
                DCD     0            ; TIM5
                DCD     0            ; SPI3
                DCD     0           ; UART4
                DCD     0           ; UART5
                DCD     0            ; TIM6
                DCD     0            ; TIM7
                DCD     0   ; DMA2 Channel1
                DCD     0   ; DMA2 Channel2
                DCD     0   ; DMA2 Channel3
                DCD     0 ; DMA2 Channel4 & Channel5

                AREA    |.text|, CODE, READONLY

; Reset handler
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]				
				IMPORT  mymain
				IMPORT  systemInit
				IMPORT	uart_init
				IMPORT	UsageFaultEnable
				IMPORT	SysTick_Init
				IMPORT	LED_Init

				; Set stack top address
                LDR     SP, =(0x20000000 + 0x1000)

				; Clear PRIMSAK to enable all interrupts
				CPSIE I

                ;BL		mymain
                LDR		R0, =mymain
				BLX		R0
				
				ENDP

; UsageFault_Handler with stack as the argument
UsageFault_Handler_ASM PROC
				; To not override EXC_RETURN value saved in the LR register when jumping into the exception handler
				;MOV	R0,	SP
				;B UsageFault_Handler
				ENDP

HardFault_Handler_ASM PROC
				MOV	R0,	SP
				B HardFault_Handler
				ENDP

				END
