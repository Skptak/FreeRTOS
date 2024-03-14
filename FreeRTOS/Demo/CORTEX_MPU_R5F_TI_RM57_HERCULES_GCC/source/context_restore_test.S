/*
 * FreeRTOS V202212.00
 * Copyright (C) 2024 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#define FREERTOS_ASSEMBLY
    #include "portmacro_asm.h"
    #include "FreeRTOSConfig.h"
#undef FREERTOS_ASSEMBLY

    .global vSetUniqueRegisters
    .global vRegTest2Implementation
    .extern vPortYield
    .extern MPU_vTaskDelay
    .extern
    .extern loopCounter
    .text
    .arm

/*-----------------------------------------------------------*/
.align 4
.type vSetUniqueRegisters, %function
vSetUniqueRegisters:

    /* Fill each general purpose register with a known value. */
    MOV     R0,  #0xFF
    MOV     R1,  #0x11
    MOV     R2,  #0x22
    MOV     R3,  #0x33
    MOV     R4,  #0x44
    MOV     R5,  #0x55
    MOV     R6,  #0x66
    MOV     R7,  #0x77
    MOV     R8,  #0x88
    MOV     R9,  #0x99
    MOV     R10, #0xAA
    MOV     R11, #0xBB
    MOV     R12, #0xCC
    #if( portENABLE_FPU == 1 )
    {
        /* Fill each FPU register with a known value. */
        VMOV     D0,  R0,  R1
        VMOV     D1,  R2,  R3
        VMOV     D2,  R4,  R5
        VMOV     D3,  R6,  R7
        VMOV     D4,  R8,  R9
        VMOV     D5,  R10, R11
        VMOV     D6,  R0,  R1
        VMOV     D7,  R2,  R3
        VMOV     D8,  R4,  R5
        VMOV     D9,  R6,  R7
        VMOV     D10, R8,  R9
        VMOV     D11, R10, R11
        VMOV     D12, R0,  R1
        VMOV     D13, R2,  R3
        VMOV     D14, R4,  R5
        VMOV     D15, R6,  R7
    #endif /* portENABLE_FPU == 1 */

    BX      LR

.align 4
.type vTestCompareRegisters, %function
xTestCompareRegisters:
    /* Ensure all registers controlled by portRESTORE_CONTEXT() have been properly set */
    cmp r0, #test_REGISTER_00_VALUE
    bne testFailure
    cmp r1, #test_REGISTER_01_VALUE
    bne testFailure
    cmp r2, #test_REGISTER_02_VALUE
    bne testFailure
    cmp r3, #test_REGISTER_03_VALUE
    bne testFailure
    cmp r4, #test_REGISTER_04_VALUE
    bne testFailure
    cmp r5, #test_REGISTER_05_VALUE
    bne testFailure
    cmp r6, #test_REGISTER_06_VALUE
    bne testFailure
    cmp r7, #test_REGISTER_07_VALUE
    bne testFailure
    movs r0, #test_REGISTER_08_VALUE
    cmp r8, r0
    bne testFailure
    movs r0, #test_REGISTER_09_VALUE
    cmp r9, r0
    bne testFailure
    movs r0, #test_REGISTER_10_VALUE
    cmp r10, r0
    bne testFailure
    movs r0, #test_REGISTER_11_VALUE
    cmp r11, r0
    bne testFailure
    movs r0, #test_REGISTER_12_VALUE
    cmp r12, r0
    bne testFailure

    movs r0, #test_REGISTER_14_VALUE
    cmp r14, r0
    bne testFailure

    #if( portENABLE_FPU == 1 )
        VMOV     R0, R1, D0
        CMP      R0, #0xFF
        BLNE     testFailure
        CMP      R1, #0x11
        BLNE     testFailure
        VMOV     R0, R1, D1
        CMP      R0, #0x22
        BLNE     testFailure
        CMP      R1, #0x33
        BLNE     testFailure
        VMOV     R0, R1, D2
        CMP      R0, #0x44
        BLNE     testFailure
        CMP      R1, #0x55
        BLNE     testFailure
        VMOV     R0, R1, D3
        CMP      R0, #0x66
        BLNE     testFailure
        CMP      R1, #0x77
        BLNE     testFailure
        VMOV     R0, R1, D4
        CMP      R0, #0x88
        BLNE     testFailure
        CMP      R1, #0x99
        BLNE     testFailure
        VMOV     R0, R1, D5
        CMP      R0, #0xAA
        BLNE     testFailure
        CMP      R1, #0xBB
        BLNE     testFailure
        VMOV     R0, R1, D6
        CMP      R0, #0xFF
        BLNE     testFailure
        CMP      R1, #0x11
        BLNE     testFailure
        VMOV     R0, R1, D7
        CMP      R0, #0x22
        BLNE     testFailure
        CMP      R1, #0x33
        BLNE     testFailure
        VMOV     R0, R1, D8
        CMP      R0, #0x44
        BLNE     testFailure
        CMP      R1, #0x55
        BLNE     testFailure
        VMOV     R0, R1, D9
        CMP      R0, #0x66
        BLNE     testFailure
        CMP      R1, #0x77
        BLNE     testFailure
        VMOV     R0, R1, D10
        CMP      R0, #0x88
        BLNE     testFailure
        CMP      R1, #0x99
        BLNE     testFailure
        VMOV     R0, R1, D11
        CMP      R0, #0xAA
        BLNE     testFailure
        CMP      R1, #0xBB
        BLNE     testFailure
        VMOV     R0, R1, D12
        CMP      R0, #0xFF
        BLNE     testFailure
        CMP      R1, #0x11
        BLNE     testFailure
        VMOV     R0, R1, D13
        CMP      R0, #0x22
        BLNE     testFailure
        CMP      R1, #0x33
        BLNE     testFailure
        VMOV     R0, R1, D14
        CMP      R0, #0x44
        BLNE     testFailure
        CMP      R1, #0x55
        BLNE     testFailure
        VMOV     R0, R1, D15
        CMP      R0, #0x66
        BLNE     testFailure
        CMP      R1, #0x77
        BLNE     testFailure
    #endif /* portENABLE_FPU */

testFailure:
    /* If this line is hit then a VFP register value was found to be
    incorrect. */
    BL       safeASSERT_Panic

/* End of file */
.end


