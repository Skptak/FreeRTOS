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

#ifndef TEST_UTILS_ASM_H
#define TEST_UTILS_ASM_H

/* ----------------------------------------------------------------------------------- */

#define FREERTOS_ASSEMBLY
    #include "FreeRTOSConfig.h"
    #include "portmacro_asm.h"
#undef FREERTOS_ASSEMBLY

/**
 * Per the ARM Cortex-R Series Programmer's Guide:
 * Constants in THUMB mode need to be in the following format:
 * 1.   A constant that can be produced by rotating an 8-bit value by any
 *      even number of bits within a 32-bit word.
 * 2.   A constant of the form 0x00XY00XY
 * 3.   A constant of the form 0xXY00XY00
 * 4.   A constant of the form 0xXYXYXYX
 */

#define test_REGISTER_00_VALUE                          0xFF
#define test_REGISTER_01_VALUE                          0x01
#define test_REGISTER_02_VALUE                          0x02
#define test_REGISTER_03_VALUE                          0x03
#define test_REGISTER_04_VALUE                          0x04
#define test_REGISTER_05_VALUE                          0x05
#define test_REGISTER_06_VALUE                          0x06
#define test_REGISTER_07_VALUE                          0x07
#define test_REGISTER_08_VALUE                          0x08
#define test_REGISTER_09_VALUE                          0x09
#define test_REGISTER_10_VALUE                          0x10
#define test_REGISTER_11_VALUE                          0x11
#define test_REGISTER_12_VALUE                          0x12
#define test_STACK_POINTER_VALUE                        0x13
#define test_LINK_REGISTER_VALUE                        0x14
#define test_PROGRAM_COUNTER_VALUE                      0x15
#define test_CURRENT_PROGRAM_STATUS_REGISTER_VALUE      0x1F
#define test_PORT_CRITICAL_NESTING                      0xF0

#if( portENABLE_FPU == 1 )
    #define test_FLOATING_REGISTER_00_VALUE             0xF0
    #define test_FLOATING_REGISTER_01_VALUE             0x01
    #define test_FLOATING_REGISTER_02_VALUE             0x02
    #define test_FLOATING_REGISTER_03_VALUE             0x03
    #define test_FLOATING_REGISTER_04_VALUE             0x04
    #define test_FLOATING_REGISTER_05_VALUE             0x05
    #define test_FLOATING_REGISTER_06_VALUE             0x06
    #define test_FLOATING_REGISTER_07_VALUE             0x07
    #define test_FLOATING_REGISTER_08_VALUE             0x08
    #define test_FLOATING_REGISTER_09_VALUE             0x09
    #define test_FLOATING_REGISTER_10_VALUE             0x10
    #define test_FLOATING_REGISTER_11_VALUE             0x11
    #define test_FLOATING_REGISTER_12_VALUE             0x12
    #define test_FLOATING_REGISTER_13_VALUE             0x13
    #define test_FLOATING_REGISTER_14_VALUE             0x14
    #define test_FLOATING_REGISTER_15_VALUE             0x15
    #define test_FLOATING_REGISTER_16_VALUE             0x16
    #define test_FLOATING_REGISTER_17_VALUE             0x17
    #define test_FLOATING_REGISTER_18_VALUE             0x18
    #define test_FLOATING_REGISTER_19_VALUE             0x19
    #define test_FLOATING_REGISTER_20_VALUE             0x20
    #define test_FLOATING_REGISTER_21_VALUE             0x21
    #define test_FLOATING_REGISTER_22_VALUE             0x22
    #define test_FLOATING_REGISTER_23_VALUE             0x23
    #define test_FLOATING_REGISTER_24_VALUE             0x24
    #define test_FLOATING_REGISTER_25_VALUE             0x25
    #define test_FLOATING_REGISTER_26_VALUE             0x26
    #define test_FLOATING_REGISTER_27_VALUE             0x27
    #define test_FLOATING_REGISTER_28_VALUE             0x28
    #define test_FLOATING_REGISTER_29_VALUE             0x29
    #define test_FLOATING_REGISTER_30_VALUE             0x30
    #define test_FLOATING_REGISTER_31_VALUE             0x31
    #define test_FPSR_VALUE                             0x11
#endif /* portENABLE_FPU == 1 */

/* ----------------------------------------------------------------------------------- */

#endif /* TEST_UTILS_H */
