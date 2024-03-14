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

/* Standard includes. */
#include <stdint.h>

/* FreeRTOS includes. */
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

/* Demo include */
#include "demo_tasks.h"
#include "context_restore_test.h"
/* ----------------------------------------------------------------------------------- */

BaseType_t xTestInit( void )
{
    /* Explained in test_utils.c skeleton file.
     * Generate and return a default Task TCB that populates default values for use in
     * common tests that don't need a whole task created and registered through the 
     * FreeRTOS-Kernel. */
    TCB_t * xTestTCB =  xCreateTaskTCB( NULL );

    /* Set the program counter for the CPU to the comparison function.
     * Now calling context restore will load the default test values into the 
     * registers handled by the port_RESTORE_CONTEXT() function. */
    xTestTCB->xMPUSettings.ulContext[portPROGRAM_COUNTER_LOC] = &xTestCompareRegisters;

    /* Set current TCB to xTestTCB for context restore test. */
    pxCurrentTCB = xTestTCB;

    /* Set R0-R12 to different values than the ones used for the test. */
    vSetUniqueRegisters();

    vStepTracker( /* Start of test. */ );

    /* Restore context from xTestTCB. */
    vPortRestoreContext();

    return xReturn;
}
