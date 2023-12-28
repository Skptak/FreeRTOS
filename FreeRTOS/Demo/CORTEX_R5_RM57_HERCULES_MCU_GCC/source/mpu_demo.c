/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Board Includes */
#include "sci.h"

/* Demo includes */
#include "demo_tasks.h"

/** @brief Size of the smallest valid MPU region, 32 bytes. */
#define SHARED_MEMORY_SIZE 0x20

/**
 * @brief Memory region used to track Memory Fault intentionally caused by the
 * RO Access task.
 *
 * @note RO Access task sets ucROTaskFaultTracker[ 0 ] to 1 before accessing illegal
 * memory. Illegal memory access causes Memory Fault and the fault handler
 * checks ucROTaskFaultTracker[ 0 ] to see if this is an expected fault. We
 * recover gracefully from an expected fault by jumping to the next instruction.
 *
 */
static volatile uint8_t ucROTaskFaultTracker[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) ) = { 0 };

#if mainDEMO_TYPE == MPU_DEMO

/* --------------------- Static Task Memory Allocation --------------------- */

/** @brief static variable that will be placed in privileged data */
PRIVILEGED_DATA static volatile uint8_t ucProtectedData = 0x99;

/** @brief Memory regions shared between the two MPU Tasks. */
static volatile uint8_t ucSharedMemory[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) );

static volatile uint8_t ucSharedMemory1[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) );

static volatile uint8_t ucSharedMemory2[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) );

static volatile uint8_t ucSharedMemory3[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) );

static volatile uint8_t ucSharedMemory4[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) );

    #if( configTOTAL_MPU_REGIONS == 16 )
static volatile uint8_t ucSharedMemory5[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) );

static volatile uint8_t ucSharedMemory6[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) );

static volatile uint8_t ucSharedMemory7[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) );

static volatile uint8_t ucSharedMemory8[ SHARED_MEMORY_SIZE ]
    __attribute__( ( aligned( SHARED_MEMORY_SIZE ) ) );
    #endif /* configTOTAL_MPU_REGIONS == 16 */

/* These tasks will use over 288 bytes as of time of writing.
 * Minimal Cortex R MPU region sizes are 32, 64, 128, 256, and 512 bytes. Regions must
 * aligned to their size. Due to this limitation these regions declare 512, or 0x200,
 * bytes and align to that size. */

/** @brief Statically declared MPU aligned stack used by the Read Only task */
static StackType_t xROAccessTaskStack[ configMINIMAL_STACK_SIZE ]
    __attribute__( ( aligned( configMINIMAL_STACK_SIZE * 0x4U ) ) );

/** @brief Statically declared TCB Used by the Idle Task */
PRIVILEGED_DATA static StaticTask_t xROAccessTaskTCB;

/** @brief Statically declared MPU aligned stack used by the Read Write task */
static StackType_t xRWAccessTaskStack[ configMINIMAL_STACK_SIZE ]
    __attribute__( ( aligned( configMINIMAL_STACK_SIZE * 0x4U ) ) );

/** @brief Statically declared TCB Used by the Read Write Task */
PRIVILEGED_DATA static StaticTask_t xRWAccessTaskTCB;

/* ----------------------- Task Function Decleration ----------------------- */

/** @brief Task function used by the task with RO access to shared memory
 *
 * @param pvParameters[in] Parameters as passed during task creation.
 */
static void prvROAccessTask( void * pvParameters );

/** @brief Task function used by the task with RW access to shared memory
 *
 * @param pvParameters[in] Parameters as passed during task creation.
 */
static void prvRWAccessTask( void * pvParameters );

/* --------------------- MPU Demo Function Definitions --------------------- */

static void prvROAccessTask( void * pvParameters )
{
    volatile uint8_t ucVal;

    /* Unused parameters. */
    ( void ) pvParameters;

    for( ;; )
    {
        /* This task performs the following sequence for all the shared memory
         * regions:
         *
         * 1. Perform a read access to the shared memory. Since this task has
         *    RO access to the shared memory, the read operation is successful.
         *
         * 2. Set ucROTaskFaultTracker[ 0 ] to 1 before performing a write to
         *    the shared memory. Since this task has Read Only access to the
         *    shared memory, the write operation would result in a Memory Fault.
         *    Setting ucROTaskFaultTracker[ 0 ] to 1 tells the Memory Fault
         *    Handler that this is an expected fault. The handler recovers from
         *    the expected fault gracefully by jumping to the next instruction.
         *
         * 3. Perform a write to the shared memory resulting in a memory fault.
         *
         * 4. Ensure that the write access did generate MemFault and the fault
         *    handler did clear the ucROTaskFaultTracker[ 0 ].
         */
        /* Perform the above mentioned sequence on ucSharedMemory. */
        ucVal = ucSharedMemory[ 0 ];
        ucVal = 1U;
        ucROTaskFaultTracker[ 0 ] = ucVal;
        ucSharedMemory[ 0 ] = 0U;
        ucVal = ucROTaskFaultTracker[ 0 ];
        configASSERT( ucVal == 0U );

        /* Perform the above mentioned sequence on ucSharedMemory1. */
        ucVal = ucSharedMemory1[ 0 ];
        ucROTaskFaultTracker[ 0 ] = 1U;
        ucSharedMemory1[ 0 ] = 0U;
        ucVal = ucROTaskFaultTracker[ 0 ];
        configASSERT( ucVal == 0U );

        /* Perform the above mentioned sequence on ucSharedMemory2. */
        ucVal = ucSharedMemory2[ 0 ];
        ucROTaskFaultTracker[ 0 ] = 1U;
        ucSharedMemory2[ 0 ] = 0U;
        ucVal = ucROTaskFaultTracker[ 0 ];
        configASSERT( ucVal == 0U );

        /* Perform the above mentioned sequence on ucSharedMemory3. */
        ucVal = ucSharedMemory3[ 0 ];
        ucROTaskFaultTracker[ 0 ] = 1U;
        ucSharedMemory3[ 0 ] = 0U;
        ucVal = ucROTaskFaultTracker[ 0 ];
        configASSERT( ucVal == 0U );

        /* Perform the above mentioned sequence on ucSharedMemory4. */
        ucVal = ucSharedMemory4[ 0 ];
        ucROTaskFaultTracker[ 0 ] = 1U;
        ucSharedMemory4[ 0 ] = 0U;
        ucVal = ucROTaskFaultTracker[ 0 ];
        configASSERT( ucVal == 0U );

    #if( configTOTAL_MPU_REGIONS == 16 )
        {
            /* Perform the above mentioned sequence on ucSharedMemory5. */
            ucVal = ucSharedMemory5[ 0 ];
            ucROTaskFaultTracker[ 0 ] = 1U;
            ucSharedMemory5[ 0 ] = 0U;
            ucVal = ucROTaskFaultTracker[ 0 ];
            configASSERT( ucVal == 0U );

            /* Perform the above mentioned sequence on ucSharedMemory6. */
            ucVal = ucSharedMemory6[ 0 ];
            ucROTaskFaultTracker[ 0 ] = 1U;
            ucSharedMemory6[ 0 ] = 0U;
            ucVal = ucROTaskFaultTracker[ 0 ];
            configASSERT( ucVal == 0U );

            /* Perform the above mentioned sequence on ucSharedMemory7. */
            ucVal = ucSharedMemory7[ 0 ];
            ucROTaskFaultTracker[ 0 ] = 1U;
            ucSharedMemory7[ 0 ] = 0U;
            ucVal = ucROTaskFaultTracker[ 0 ];
            configASSERT( ucVal == 0U );

            /* Perform the above mentioned sequence on ucSharedMemory8. */
            ucVal = ucSharedMemory8[ 0 ];
            ucROTaskFaultTracker[ 0 ] = 1U;
            ucSharedMemory8[ 0 ] = 0U;
            ucVal = ucROTaskFaultTracker[ 0 ];
            configASSERT( ucVal == 0U );
        }
    #endif /* configTOTAL_MPU_REGIONS == 16 */

        /* Wait for a bit. */
        sci_print( "Read only task did a loop\r\n" );
        vToggleLED( 0x0 );
        vTaskDelay( pdMS_TO_TICKS( 4400 ) );
    }
}
/*-----------------------------------------------------------*/

static void prvRWAccessTask( void * pvParameters )
{
    /* Unused parameters. */
    ( void ) pvParameters;
    volatile uint8_t ucVal;

    for( ;; )
    {
        /* This task has RW access to ucSharedMemory */
        ucSharedMemory[ 0 ]++;
        ucSharedMemory1[ 0 ]++;
        ucSharedMemory2[ 0 ]++;
        ucSharedMemory3[ 0 ]++;
        ucSharedMemory4[ 0 ]++;
    #if( configTOTAL_MPU_REGIONS == 16 )
        {
            ucSharedMemory5[ 0 ]++;
            ucSharedMemory6[ 0 ]++;
            ucSharedMemory7[ 0 ]++;
            ucSharedMemory8[ 0 ]++;
        }
    #endif /* configTOTAL_MPU_REGIONS == 16 */

        /* Set ucVal to 0 */
        ucVal = ucSharedMemory[ 0 ];

        /** Attempt to set ucVal to the stored value of 1U in ucROTaskFaultTracker.
         * This will trigger a data abort as this task only has privileged read/write
         * access to this variable. The Data abort handler at the bottom of this
         * file will then see this raised value, mark it low, and return this task
         * to the following instruction.
         */
        ucVal = ucProtectedData;

        /* The value of ucVal should not have changed */
        configASSERT( ucVal != ucSharedMemory[ 0 ] );

        /* Wait for a second. */
        sci_print( "Read/Write task did a loop\r\n" );
        vToggleLED( 0x1 );
        vTaskDelay( pdMS_TO_TICKS( 9500 ) );
    }
}
/*-----------------------------------------------------------*/

BaseType_t xCreateMPUTasks( void )
{
    BaseType_t xReturn = pdPASS;
    /* Make sure that SHARED_MEMORY_SIZE is a valid MPU region size */
    if( ( SHARED_MEMORY_SIZE < 0x20 ) || ( ( SHARED_MEMORY_SIZE % 2 ) != 0 ) )
    {
        sci_print( "SHARED_MEMORY_SIZE must be a power of 2 larger than 32\r\n" );
        xReturn = pdFAIL;
    }

    uint32_t readMemoryPermissions =
        portMPU_PRIV_RW_USER_RO_NOEXEC | portMPU_NORMAL_OIWTNOWA_SHARED;

    uint32_t writeMemoryPermissions =
        portMPU_PRIV_RW_USER_RW_NOEXEC | portMPU_NORMAL_OIWTNOWA_SHARED;

    TaskParameters_t
        xROAccessTaskParameters = { .pvTaskCode = prvROAccessTask,
                                    .pcName = "ROAccess",
                                    .usStackDepth = configMINIMAL_STACK_SIZE,
                                    .pvParameters = NULL,
                                    .uxPriority = tskIDLE_PRIORITY + 0x4,
                                    .puxStackBuffer = xROAccessTaskStack,
                                    .pxTaskBuffer = &xROAccessTaskTCB,
                                    .xRegions = {
                                        /* First Configurable Region 0 */
                                        { ( void * ) ucSharedMemory,
                                          SHARED_MEMORY_SIZE,
                                          readMemoryPermissions },
                                        /* Region 1 */
                                        { ( void * ) ucSharedMemory1,
                                          SHARED_MEMORY_SIZE,
                                          readMemoryPermissions },
                                        /* Region 2 */
                                        { ( void * ) ucSharedMemory2,
                                          SHARED_MEMORY_SIZE,
                                          readMemoryPermissions },
                                        /* Region 3 */
                                        { ( void * ) ucSharedMemory3,
                                          SHARED_MEMORY_SIZE,
                                          readMemoryPermissions },
                                        /* Region 4 */
                                        { ( void * ) ucSharedMemory4,
                                          SHARED_MEMORY_SIZE,
                                          readMemoryPermissions },
    #if( configTOTAL_MPU_REGIONS == 16 )
                                        /* Region 5 */
                                        { ( void * ) ucSharedMemory5,
                                          SHARED_MEMORY_SIZE,
                                          readMemoryPermissions },
                                        /* Region 6 */
                                        { ( void * ) ucSharedMemory6,
                                          SHARED_MEMORY_SIZE,
                                          readMemoryPermissions },
                                        /* Region 7 */
                                        { ( void * ) ucSharedMemory7,
                                          SHARED_MEMORY_SIZE,
                                          readMemoryPermissions },
                                        /* Region 8 */
                                        { ( void * ) ucSharedMemory8,
                                          SHARED_MEMORY_SIZE,
                                          readMemoryPermissions },
    #endif /* configTOTAL_MPU_REGIONS == 16 */
                                        /* Last Configurable Region */
                                        { ( void * ) ucROTaskFaultTracker,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
                                    } };

    TaskParameters_t
        xRWAccessTaskParameters = { .pvTaskCode = prvRWAccessTask,
                                    .pcName = "RWAccess",
                                    .usStackDepth = configMINIMAL_STACK_SIZE,
                                    .pvParameters = NULL,
                                    .uxPriority = tskIDLE_PRIORITY + 0x3,
                                    .puxStackBuffer = xRWAccessTaskStack,
                                    .pxTaskBuffer = &xRWAccessTaskTCB,
                                    .xRegions = {
                                        /* First Configurable Region 5 */
                                        { ( void * ) ucSharedMemory,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
                                        /* Region 6 */
                                        { ( void * ) ucSharedMemory1,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
                                        /* Region 7 */
                                        { ( void * ) ucSharedMemory2,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
                                        /* Region 8 */
                                        { ( void * ) ucSharedMemory3,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
                                        /* Region 9 */
                                        { ( void * ) ucSharedMemory4,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
    #if( configTOTAL_MPU_REGIONS == 16 )
                                        /* Region 10 */
                                        { ( void * ) ucSharedMemory5,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
                                        /* Region 11 */
                                        { ( void * ) ucSharedMemory6,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
                                        /* Region 12 */
                                        { ( void * ) ucSharedMemory7,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
                                        /* Region 13 */
                                        { ( void * ) ucSharedMemory8,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
    #endif /* configTOTAL_MPU_REGIONS == 16 */
                                        /* Last Configurable Region */
                                        { ( void * ) ucROTaskFaultTracker,
                                          SHARED_MEMORY_SIZE,
                                          writeMemoryPermissions },
                                    } };

    if( pdPASS == xReturn )
    {
        /* Create an unprivileged task with RO access to ucSharedMemory. */
        xReturn = xTaskCreateRestrictedStatic( &( xROAccessTaskParameters ), NULL );
        if( pdPASS == xReturn )
        {
            /* Create an unprivileged task with RW access to ucSharedMemory. */
            xReturn = xTaskCreateRestrictedStatic( &( xRWAccessTaskParameters ), NULL );
            if( pdPASS != xReturn )
            {
                sci_print( "Failed to create the Read Write MPU Task" );
            }
        }
        else
        {
            sci_print( "Failed to create the Read Write MPU Task" );
        }
    }

    return xReturn;
}
/*-----------------------------------------------------------*/
#endif /* mainDEMO_TYPE == MPU_DEMO */

PRIVILEGED_FUNCTION portDONT_DISCARD void vHandleMemoryFault(
    uint32_t * pulFaultStackAddress
)
{
    volatile uint32_t ulPC;
    volatile uint32_t ulOffendingInstruction;

    /* Is this an expected fault? */
    if( ( ucROTaskFaultTracker[ 0 ] == 1U ) || ( ucROTaskFaultTracker[ 1 ] == 1U ) )
    {
        /* Read program counter. */
        ulPC = pulFaultStackAddress[ 13 ];

        /* Read the offending instruction. */
        ulOffendingInstruction = *( uint32_t * ) ulPC;

        /** From ARM docs:
         * Bits [31:28] are the conditional field
         * Bits [27:24] are the operation code
         * If bits [31:28] are 0b1111, the instruction can only be executed
         * unconditionally If bits [31:28] are not 0b1111, the op code determines what the
         * instruction is doing If bits [27:24] are 0b01x0 it is a load/store word If bits
         * [27:24] are 0b0111 it is a media instruction
         */

        /* Extract bits[31:25] of the offending instruction. */
        ulOffendingInstruction = ulOffendingInstruction & 0xFF000000;
        ulOffendingInstruction = ( ulOffendingInstruction >> 24 );

        /* Check if we were called by a load/store word instruction */
        if( ( ulOffendingInstruction == 0x00E4 ) ||
            ( ulOffendingInstruction == 0x00E5 ) || ( ulOffendingInstruction == 0x00E6 ) )
        {
            /* Increment the program counter to move to the next instruction */
            ulPC += 0x4;
        }
        else
        {
            sci_print( "Unexpected Instruction caused an MPU fault\r\n" );
            configASSERT( 0 );
        }

        /* Save the new program counter on the stack. */
        pulFaultStackAddress[ 13 ] = ulPC;

        /* Mark the fault as handled. */
        if( ucROTaskFaultTracker[ 0 ] == 1U )
        {
            ucROTaskFaultTracker[ 0 ] = 0U;
            sci_print( "Cleared an MPU Read Only Task Fault\r\n" );
        }
        else if( ucROTaskFaultTracker[ 1 ] == 1U )
        {
            sci_print( "Cleared an MPU Write Only Task Fault\r\n" );
            ucROTaskFaultTracker[ 1 ] = 0U;
        }
        else
        {
            sci_print( "TaskFaultTracker value changed, Are IRQs disabled? \r\n" );
            /* Sit in a loop forever */
            configASSERT( 0 );
        }
    }
    else
    {
        sci_print( "Unexpected MPU Fault\r\n" );
        /* This is an unexpected fault - loop forever. */
        configASSERT( 0 );
    }
}

/*-----------------------------------------------------------*/
