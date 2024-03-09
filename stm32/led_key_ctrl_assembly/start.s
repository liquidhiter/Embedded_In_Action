                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     0			               ; Top of Stack
                DCD     Reset_Handler              ; Reset Handler


                AREA    |.text|, CODE, READONLY
                
; Reset handler
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
				
				; Enable the clock for IOPB and IOPC
				LDR		R0, =0x40021018
				LDR		R1, [R0]
				ORR		R1, R1, #(1<<3)
				ORR		R1, R1, #(1<<4)
				STR		R1, [R0]
				
				; Configure PC13 to be output
				LDR		R0, =0x40011004
				LDR		R1, [R0]
				ORR		R1, R1, #0x100000
				STR		R1, [R0]
				
				; Configure PB14 to be input
				LDR		R0, =0x40010C04
				LDR		R1, [R0]
				AND		R1, R1, #(0x00<<24)
				ORR		R1, R1, #(0x01<<26)
				STR		R1, [R0]

Loop
				; Read the PB14 input register
				LDR		R0, =0x40010C08
				LDR		R1, [R0]
				AND		R1, R1, #(1<<14)
				CBNZ	R1, LED_OFF
				;B		LED_ON
				; Set PC13 output to be low
				LDR		R0, =0x4001100C
				LDR		R1, [R0]
				BIC		R1, R1, #0x2000
				STR		R1, [R0]
				
				; Continue looping
				B 		Loop

LED_OFF
				; Set PC13 output to be high
				LDR		R0, =0x4001100C
				LDR		R1, [R0]
				ORR		R1, R1, #0x2000
				STR		R1, [R0]
				
				; Continue looping
				B		Loop

                ENDP

				END