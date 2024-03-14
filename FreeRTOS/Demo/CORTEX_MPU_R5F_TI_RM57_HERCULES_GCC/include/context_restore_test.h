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

#ifndef CONTEXT_RESTORE_TEST_H
#define CONTEXT_RESTORE_TEST_H

#include "FreeRTOSConfig.h"
#include "portmacro.h"

/* ------------------------------ Test Specific Defines ------------------------------ */
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
    #define test_FLOATING_REGISTER_00_VALUE             0xD0000000
    #define test_FLOATING_REGISTER_01_VALUE             0xD0000000
    #define test_FLOATING_REGISTER_02_VALUE             0xD0000001
    #define test_FLOATING_REGISTER_03_VALUE             0xD1000000
    #define test_FLOATING_REGISTER_04_VALUE             0xD0000002
    #define test_FLOATING_REGISTER_05_VALUE             0xD2000000
    #define test_FLOATING_REGISTER_06_VALUE             0xD0000003
    #define test_FLOATING_REGISTER_07_VALUE             0xD3000000
    #define test_FLOATING_REGISTER_08_VALUE             0xD0000004
    #define test_FLOATING_REGISTER_09_VALUE             0xD4000000
    #define test_FLOATING_REGISTER_10_VALUE             0xD0000005
    #define test_FLOATING_REGISTER_11_VALUE             0xD5000000
    #define test_FLOATING_REGISTER_12_VALUE             0xD0000006
    #define test_FLOATING_REGISTER_13_VALUE             0xD6000000
    #define test_FLOATING_REGISTER_14_VALUE             0xD0000007
    #define test_FLOATING_REGISTER_15_VALUE             0xD7000000
    #define test_FLOATING_REGISTER_16_VALUE             0xD0000008
    #define test_FLOATING_REGISTER_17_VALUE             0xD8000000
    #define test_FLOATING_REGISTER_18_VALUE             0xD0000009
    #define test_FLOATING_REGISTER_19_VALUE             0xD0900000
    #define test_FLOATING_REGISTER_20_VALUE             0xD0000010
    #define test_FLOATING_REGISTER_21_VALUE             0xD1000000
    #define test_FLOATING_REGISTER_22_VALUE             0xD0000011
    #define test_FLOATING_REGISTER_23_VALUE             0xD1100000
    #define test_FLOATING_REGISTER_24_VALUE             0xD0000012
    #define test_FLOATING_REGISTER_25_VALUE             0xD1200000
    #define test_FLOATING_REGISTER_26_VALUE             0xD0000013
    #define test_FLOATING_REGISTER_27_VALUE             0xD1300000
    #define test_FLOATING_REGISTER_28_VALUE             0xD0000014
    #define test_FLOATING_REGISTER_29_VALUE             0xD1400000
    #define test_FLOATING_REGISTER_30_VALUE             0xD1500015
    #define test_FLOATING_REGISTER_31_VALUE             0xD1500000
    #define test_FPSR_VALUE                             0x00DDDD00
#endif /* portENABLE_FPU == 1 */


void vTestCompareRegisters();

/* ----------------------------------------------------------------------------------- */

#endif /* CONTEXT_RESTORE_TEST_H */
