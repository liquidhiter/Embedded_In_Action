                PRESERVE8
                THUMB

; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     0			               ; Top of Stack
                DCD     0x08000009 ;Reset_Handler              ; Reset Handler

                AREA    |.text|, CODE, READONLY
			
; Reset handler
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]				
				IMPORT  mymain
				IMPORT  systemInit

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

				BL		systemInit
								
                ;BL		mymain
                LDR		R0, =mymain
				BLX		R0
				
				ENDP
				END
