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

    .syntax unified
    .text

    .extern vTestPassed
#include "test_utils_asm.h"

/*-----------------------------------------------------------*/
.align 4
.type vSetUniqueRegisters, %function
.global vSetUniqueRegisters
vSetUniqueRegisters:

    /* Zero out all General Purpose Registers (GPRs). */
    MOVS     R0,  #0x00
    MOVS     R1,  #0x00
    MOVS     R2,  #0x00
    MOVS     R3,  #0x00
    MOVS     R4,  #0x00
    MOVS     R5,  #0x00
    MOVS     R6,  #0x00
    MOVS     R7,  #0x00
    /* Use Cortex M0+ Compliant code to make the file more portable.
     * i.e. don't directly use Registers R8+ for most operations. */
    MOVS     R8, R0
    MOVS     R9,  R0
    MOVS     R10, R0
    MOVS     R11, R0
    MOVS     R12, R0

    #if( portENABLE_FPU == 1 )
        /* Zero out all Floating Point Registers (FPRs). */
        VMOV     D0,  R0, R1
        VMOV     D1,  R0, R1
        VMOV     D2,  R0, R1
        VMOV     D3,  R0, R1
        VMOV     D4,  R0, R1
        VMOV     D5,  R0, R1
        VMOV     D6,  R0, R1
        VMOV     D7,  R0, R1
        VMOV     D8,  R0, R1
        VMOV     D9,  R0, R1
        VMOV     D10, R0, R1
        VMOV     D11, R0, R1
        VMOV     D12, R0, R1
        VMOV     D13, R0, R1
        VMOV     D14, R0, R1
        VMOV     D15, R0, R1
    #endif /* portENABLE_FPU == 1 */

    BX      LR

.align 4
.type xTestFunction, %function
.global xTestFunction
xTestFunction:
    /* Ensure all registers controlled by portRESTORE_CONTEXT() have been properly set */
    /* Default Comparison bits are for a passing comparison. Ensure this is correctly
     * set. */
    BEQ     testFailure
    BLT     testFailure

    CMP     R0, #test_REGISTER_00_VALUE
    BNE     testFailure

    CMP     R1, #test_REGISTER_01_VALUE
    BNE     testFailure

    CMP     R2, #test_REGISTER_02_VALUE
    BNE     testFailure

    CMP     R3, #test_REGISTER_03_VALUE
    BNE     testFailure

    CMP     R4, #test_REGISTER_04_VALUE
    BNE     testFailure

    CMP     R5, #test_REGISTER_05_VALUE
    BNE     testFailure

    CMP     R6, #test_REGISTER_06_VALUE
    BNE     testFailure

    CMP     R7, #test_REGISTER_07_VALUE
    BNE     testFailure

    /* Use Cortex M0+ Compliant code to make the file more portable.
     * i.e. don't directly use Registers R8+ for most operations. */
    MOVS    R0, #test_REGISTER_08_VALUE
    MOVS    R1, R8
    CMP     R0, R1
    BNE     testFailure

    MOVS    R0, #test_REGISTER_09_VALUE
    MOVS    R1, R9
    CMP     R0, R1
    BNE     testFailure

    MOVS    R0, #test_REGISTER_10_VALUE
    MOVS    R1, R10
    CMP     R0, R1
    BNE     testFailure

    MOVS    R0, #test_REGISTER_11_VALUE
    MOVS    R1, R11
    CMP     R0, R1
    BNE     testFailure

    MOVS    R0, #test_REGISTER_12_VALUE
    MOVS    R1, R12
    CMP     R0, R1
    BNE     testFailure

    LDR     R0, =vTestPassed
    MOVS    R1, R14
    CMP     R0, R1
    BNE     testFailure

    #if( portENABLE_FPU == 1 )
        VMRS    R0, FPSCR               /* R0 = FPSCR. */
        CMP     R0, #test_FPSR_VALUE
        BNE     testFailure

        VMOV    R0, R1, D0
        MOVS    R2, #test_FLOATING_REGISTER_00_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_01_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D1
        MOVS    R2, #test_FLOATING_REGISTER_02_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_03_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D2
        MOVS    R2, #test_FLOATING_REGISTER_04_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_05_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D3
        MOVS    R2, #test_FLOATING_REGISTER_06_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_07_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D4
        MOVS    R2, #test_FLOATING_REGISTER_08_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_09_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D5
        MOVS    R2, #test_FLOATING_REGISTER_10_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_11_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D6
        MOVS    R2, #test_FLOATING_REGISTER_12_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_13_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D7
        MOVS    R2, #test_FLOATING_REGISTER_14_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_15_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D8
        MOVS    R2, #test_FLOATING_REGISTER_16_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_17_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D9
        MOVS    R2, #test_FLOATING_REGISTER_18_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_19_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D10
        MOVS    R2, #test_FLOATING_REGISTER_20_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_21_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D11
        MOVS    R2, #test_FLOATING_REGISTER_22_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_23_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D12
        MOVS    R2, #test_FLOATING_REGISTER_24_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_25_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D13
        MOVS    R2, #test_FLOATING_REGISTER_26_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_27_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D14
        MOVS    R2, #test_FLOATING_REGISTER_28_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_29_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

        VMOV    R0, R1, D15
        MOVS    R2, #test_FLOATING_REGISTER_30_VALUE
        MOVS    R3, #test_FLOATING_REGISTER_31_VALUE
        CMP     R0, R2
        BNE     testFailure
        CMP     R1, R3
        BNE     testFailure

    #endif /* portENABLE_FPU */

    /* If a branch to the testFailure is not hit, then all registers contain
     * expected values. */
    /* If the LR was properly set this will return to vRegisterTestPassed() */
    MOVS    R0, #0x1
    BLX     LR

testFailure:
    /* A failure was found in the regsiter test, jump to the failure test. */
    LDR     R0, =vTestFailed
    MOVS    LR, R0
    BLX     LR


/* End of file */
.end
