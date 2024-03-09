;******************** (C) COPYRIGHT 2011 STMicroelectronics ********************
;* File Name          : startup_stm32f10x_hd.s
;* Author             : MCD Application Team
;* Version            : V3.5.1
;* Date               : 08-September-2021
;* Description        : STM32F10x High Density Devices vector table for MDK-ARM 
;*                      toolchain. 
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Set the vector table entries with the exceptions ISR address
;*                      - Configure the clock system and also configure the external 
;*                        SRAM mounted on STM3210E-EVAL board to be used as data 
;*                        memory (optional, to be enabled by user)
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the CortexM3 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>   
;*******************************************************************************
;*
;* Copyright (c) 2011 STMicroelectronics.
;* All rights reserved.
;*
;* This software is licensed under terms that can be found in the LICENSE file
;* in the root directory of this software component.
;* If no LICENSE file comes with this software, it is provided AS-IS.
;
;*******************************************************************************
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
				
				; Enable GPIO clock
				LDR		R0, =0x40021018
				LDR		R1, [R0]
				ORR		R1, R1, #0x10
				STR		R1, [R0]
				
				; Configure control register
				LDR		R0, =0x40011004
				LDR		R1, [R0]
				ORR		R1, R1, #0x100000
				STR		R1, [R0]
Loop
				; Set output to high
				LDR		R0, =0x4001100C
				LDR		R1, [R0]
				ORR		R1, R1, #0x2000
				STR		R1, [R0]
				
				; Delay
				LDR		R0, =100000
				BL		Delay
				
				; Set output to low
				LDR		R0, =0x4001100C
				LDR		R1, [R0]
				BIC		R1, R1, #0x2000
				STR		R1, [R0]
				
				; Delay
				LDR		R0, =100000
				BL		Delay
				
				; Looping ...
				B Loop

                ENDP

Delay
				; decrease R0
				; compare R0 with 0
				; loop until R0 = 0
				SUBS	R0, R0, #1
				BNE		Delay
				MOV		PC,	LR

				END