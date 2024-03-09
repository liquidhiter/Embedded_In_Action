                PRESERVE8
                THUMB

; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
				IMPORT	HardFault_Handler
				IMPORT  UsageFault_Handler
				IMPORT	SVCall_Handler
				IMPORT	SysTick_Handler

__Vectors       DCD     0			               ; Top of Stack
                DCD     0x08000009 ;Reset_Handler              ; Reset Handler
				DCD     0                ; NMI Handler
                DCD     HardFault_Handler          ; Hard Fault Handler
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

				;IMPORT  relocate_memcpy
				;IMPORT	relocate_memset
					
				;IMPORT	|Image$$RW_IRAM1$$Base|
				;IMPORT	|Image$$RW_IRAM1$$Length|
				;IMPORT	|Load$$RW_IRAM1$$Base|
				
				;IMPORT  |Image$$RW_IRAM1$$ZI$$Base|
				;IMPORT  |Image$$RW_IRAM1$$ZI$$Length|

				;IMPORT |Image$$ER_IROM1$$Base|
				;IMPORT |Image$$ER_IROM1$$Length|
				;IMPORT |Load$$ER_IROM1$$Base|


				; Set stack top address
                LDR     SP, =(0x20000000 + 0x1000)

				; Relocate text section (RW)
				;LDR 	R0, = |Image$$ER_IROM1$$Base|    ; DEST
				;LDR 	R1, = |Load$$ER_IROM1$$Base|     ; SORUCE
				;LDR 	R2, = |Image$$ER_IROM1$$Length|  ; LENGTH
				;BL		relocate_memcpy

				; Relocate data section (RW)
				;LDR		R0,	= |Image$$RW_IRAM1$$Base| 		;Destination
				;LDR		R1, = |Load$$RW_IRAM1$$Base|		;Source
				;LDR		R2, = |Image$$RW_IRAM1$$Length|  	;Length
				;BL		relocate_memcpy
				
				; Clear .bss
				;LDR 	R0, = |Image$$RW_IRAM1$$ZI$$Base|       ; DEST
				;LDR 	R1, = |Image$$RW_IRAM1$$ZI$$Length|     ; Length
				;BL 		relocate_memset

				;BL		systemInit
				
				BL		uart_init
				;BL		UsageFaultEnable
				
				; Experiment to see certain registers are saved
				LDR		R0, =0x11111111
				LDR		R1, =0x22222222
				LDR		R2, =0x33333333
				LDR		R3, =0x44444444
				LDR		R12, =0x55555555
				LDR		LR, =0x66666666 
				
				; Cause a usage fault as the instruction is unknown
				;DCD		0xFFFFFFFF
				
				; Cause a SVC exception
				;SVC		#1
				
				; Enable all interrupts
				CPSIE I  ; clear PRIMASK to enable interrupts
				
				; Cause a SysTick exception
				BL		LED_Init
				BL		SysTick_Init

                ;BL		mymain
                LDR		R0, =mymain
				BLX		R0
				
				ENDP

; UsageFault_Handler with stack as the argument
UsageFault_Handler_ASM PROC
				; To not override EXC_RETURN value saved in the LR register when jumping into the exception handler
				MOV	R0,	SP
				B UsageFault_Handler
				ENDP

				END
