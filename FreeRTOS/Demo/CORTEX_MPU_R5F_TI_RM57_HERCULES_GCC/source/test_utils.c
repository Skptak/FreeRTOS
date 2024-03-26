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
#include "test_utils.h"
#include "context_restore_test.h"

/* Board Includes */
#include "sci.h"

extern portDONT_DISCARD PRIVILEGED_DATA TCB_t * volatile pxCurrentTCB;

/* ----------------------------------------------------------------------------------- */

/** @brief Static TCB For when only a single Task TCB is needed. */
PRIVILEGED_DATA static TCB_t xTestTCBs[configMAX_PRIORITIES];

/** @brief Static Task Stacks to use for default fake task creation. */
static StackType_t uxTestStacks[ configMAX_PRIORITIES ][configMINIMAL_STACK_SIZE]
   __attribute__( ( aligned( configMINIMAL_STACK_SIZE * 0x4U ) ) );

PRIVILEGED_DATA static uint32_t xTaskCount = 0UL;

/** @brief There should be a test function to populate a TCB.
 * It should also have a way to populate a TCB to a "default" value for tests that
 * just need a TCB to exist. I'd say that making it so that having NULL passed in
 * means it should just fill with default values.
 * Default Program Counter could be either xTestTaskFunction() or something
 * that can be set upon the return. */
TCB_t * xCreateTaskTCB( TaskParameters_t * xTestTaskParameters )
{
    UBaseType_t ulIndex = CONTEXT_SIZE - 1U;

    TCB_t * pxNewTCB = &xTestTCBs[ xTaskCount ];
    StackType_t * pulTestStack = &uxTestStacks[ xTaskCount ][ configMINIMAL_STACK_SIZE ];
    xTaskCount++;


    /* Set Default Task MPU Settings. */
    for( uint32_t ulMPURegion = portFIRST_CONFIGURABLE_REGION; ulMPURegion < portLAST_CONFIGURABLE_REGION; ulMPURegion++ )
    {
        /* Would make sense to have a port/BSP specific function to handle this? */
        pxNewTCB->xMPUSettings.xRegion[ ulMPURegion ].ulRegionSize = 0UL;
        pxNewTCB->xMPUSettings.xRegion[ ulMPURegion ].ulRegionAttribute = 0UL;
        pxNewTCB->xMPUSettings.xRegion[ ulMPURegion ].ulRegionBaseAddress = 0UL;
    }

    if( xTestTaskParameters != NULL )
    {
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_CURRENT_PROGRAM_STATUS_REGISTER_VALUE;
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) xTestTaskParameters->pvTaskCode; /* PC. */
        ulIndex--;
        /* Feel like it could make sense for this to just be set to safeASSERT_PANIC()? */
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) &vTestPassed; /* LR. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) xTestTaskParameters->puxStackBuffer; /* SP. */
    }
    else
    {
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_CURRENT_PROGRAM_STATUS_REGISTER_VALUE;
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) &xTestFunction; /* PC. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) &vTestPassed;   /* LR. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) pulTestStack; /* SP. */
    }
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_12_VALUE; /* R12. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_11_VALUE; /* R11. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_10_VALUE; /* R10. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_09_VALUE; /* R9. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_08_VALUE; /* R8. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_07_VALUE; /* R7. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_06_VALUE; /* R6. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_05_VALUE; /* R5. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_04_VALUE; /* R4. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_03_VALUE; /* R3. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_02_VALUE; /* R2. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_01_VALUE; /* R1. */
    ulIndex--;
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_REGISTER_00_VALUE; /* R0. */
    ulIndex--;

    vStepTracker( /* Created Non-FPU Task Context. */ );

    #if( portENABLE_FPU == 1 )
    {
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_31_VALUE; /* S31. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_30_VALUE; /* S30. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_29_VALUE; /* S29. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_28_VALUE; /* S28. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_27_VALUE; /* S27. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_26_VALUE; /* S26. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_25_VALUE; /* S25. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_24_VALUE; /* S24. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_23_VALUE; /* S23. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_22_VALUE; /* S22. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_21_VALUE; /* S21. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_20_VALUE; /* S20. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_19_VALUE; /* S19. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_18_VALUE; /* S18. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_17_VALUE; /* S17. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_16_VALUE; /* S16. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_15_VALUE; /* S15. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_14_VALUE; /* S14. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_13_VALUE; /* S13. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_12_VALUE; /* S12. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_11_VALUE; /* S11. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_10_VALUE; /* S10. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_09_VALUE; /* S9. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_08_VALUE; /* S8. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_07_VALUE; /* S7. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_06_VALUE; /* S6. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_05_VALUE; /* S5. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_04_VALUE; /* S4. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_03_VALUE; /* S3. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_02_VALUE; /* S2. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_01_VALUE; /* S1. */
        ulIndex--;
        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FLOATING_REGISTER_00_VALUE; /* S0. */
        ulIndex--;

        pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_FPSR_VALUE; /* FPSR. */
        ulIndex--;

        vStepTracker( /* Created FPU Task Context. */ );
    }
    #endif /* portENABLE_FPU */

    /* The task will start with a critical nesting count of 0. */
    pxNewTCB->xMPUSettings.ulContext[ ulIndex ] = ( StackType_t ) test_PORT_CRITICAL_NESTING;

    pxNewTCB->pxTopOfStack =  &( pxNewTCB->xMPUSettings.ulContext[ ulIndex ] );

    return pxNewTCB;
}

/* ----------------------------------------------------------------------------------- */

/* PRIVILEGED_FUNCTION */ void * xApplicationPrivilegedCallback( void * xPrivilegedStruct )
{
    vPrintString("Next step in the step tracker\r\n");
    return NULL;
}

void vStepTracker( void )
{
    vPrintString("Step Tracker Magic\r\n");
}

void vTestPassed( void )
{
    while( 1 )
    {
        vPrintString("Test Passed String\r\n");
    }

}

void vTestFailed( void )
{
    vPrintString("Test Failed String\r\n");
}


PRIVILEGED_FUNCTION portDONT_DISCARD void vHandleMemoryFault(
    uint32_t * pulFaultStackAddress )
{
    vPrintString("Unexpected Hardfault Hit, test failing.\r\n");
}

