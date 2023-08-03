/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/* Standard includes. */
#include "stdlib.h"
#include "string.h"

/* lwIP core includes */
#include "lwip/opt.h"
#include "lwip/sockets.h"

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Utils includes. */
#include "FreeRTOS_CLI.h"

/* Dimensions the buffer into which input characters are placed. */
#define cmdMAX_INPUT_SIZE  100

/* Dimensions the buffer into which string outputs can be placed. */
#define cmdMAX_OUTPUT_SIZE 1024

/*-----------------------------------------------------------*/

void vBasicSocketsCommandInterpreterTask( void * pvParameters )
{
    long lSocket, lClientFd, lBytes, lAddrLen = sizeof( struct sockaddr_in ),
                                     lInputIndex;
    struct sockaddr_in sLocalAddr;
    struct sockaddr_in client_addr;
    const char * pcWelcomeMessage = "FreeRTOS command server - connection "
                                    "accepted.\r\nType Help to view a list of "
                                    "registered commands.\r\n\r\n>";
    char cInChar;
    static char cInputString[ cmdMAX_INPUT_SIZE ],
        cOutputString[ cmdMAX_OUTPUT_SIZE ];
    portBASE_TYPE xReturned;
    extern void vRegisterSampleCLICommands( void );

    ( void ) pvParameters;

    /* Register the standard CLI commands. */
    vRegisterSampleCLICommands();

    lSocket = lwip_socket( AF_INET, SOCK_STREAM, 0 );

    if( lSocket >= 0 )
    {
        memset( ( char * ) &sLocalAddr, 0, sizeof( sLocalAddr ) );
        sLocalAddr.sin_family = AF_INET;
        sLocalAddr.sin_len = sizeof( sLocalAddr );
        sLocalAddr.sin_addr.s_addr = htonl( INADDR_ANY );
        sLocalAddr.sin_port = ntohs( ( ( unsigned short ) 23 ) );

        if( lwip_bind( lSocket,
                       ( struct sockaddr * ) &sLocalAddr,
                       sizeof( sLocalAddr ) ) < 0 )
        {
            lwip_close( lSocket );
            vTaskDelete( NULL );
        }

        if( lwip_listen( lSocket, 20 ) != 0 )
        {
            lwip_close( lSocket );
            vTaskDelete( NULL );
        }

        for( ;; )
        {
            lClientFd = lwip_accept( lSocket,
                                     ( struct sockaddr * ) &client_addr,
                                     ( u32_t * ) &lAddrLen );

            if( lClientFd > 0L )
            {
                lwip_send( lClientFd,
                           pcWelcomeMessage,
                           strlen( ( const char * ) pcWelcomeMessage ),
                           0 );

                lInputIndex = 0;
                memset( cInputString, 0x00, cmdMAX_INPUT_SIZE );

                do
                {
                    lBytes = lwip_recv( lClientFd,
                                        &cInChar,
                                        sizeof( cInChar ),
                                        0 );

                    if( lBytes > 0L )
                    {
                        if( cInChar == '\n' )
                        {
                            /* The input string has been terminated.  Was the
                            input a quit command? */
                            if( strcmp( "quit",
                                        ( const char * ) cInputString ) == 0 )
                            {
                                /* Set lBytes to 0 to close the connection. */
                                lBytes = 0L;
                            }
                            else
                            {
                                /* The input string was not a quit command.
                                Pass the string to the command interpreter. */
                                do
                                {
                                    /* Get the next output string from the
                                     * command interpreter. */
                                    xReturned = FreeRTOS_CLIProcessCommand(
                                        cInputString,
                                        cOutputString,
                                        cmdMAX_INPUT_SIZE );
                                    lwip_send( lClientFd,
                                               cOutputString,
                                               strlen( ( const char * )
                                                           cOutputString ),
                                               0 );

                                } while( xReturned != pdFALSE );

                                /* All the strings generated by the input
                                command have been sent.  Clear the input
                                string ready to receive the next command. */
                                lInputIndex = 0;
                                memset( cInputString, 0x00, cmdMAX_INPUT_SIZE );
                                lwip_send( lClientFd,
                                           "\r\n>",
                                           strlen( "\r\n>" ),
                                           0 );
                            }
                        }
                        else
                        {
                            if( cInChar == '\r' )
                            {
                                /* Ignore the character. */
                            }
                            else if( cInChar == '\b' )
                            {
                                /* Backspace was pressed.  Erase the last
                                character in the string - if any. */
                                if( lInputIndex > 0 )
                                {
                                    lInputIndex--;
                                    cInputString[ lInputIndex ] = '\0';
                                }
                            }
                            else if( ( cInChar >= ' ' ) && ( cInChar <= 'z' ) )
                            {
                                /* A character was entered.  Add it to the
                                string entered so far.  When a \n is entered the
                                complete string will be passed to the command
                                interpreter. */
                                if( lInputIndex < cmdMAX_INPUT_SIZE )
                                {
                                    cInputString[ lInputIndex ] = cInChar;
                                    lInputIndex++;
                                }
                            }
                        }
                    }

                } while( lBytes > 0L );

                lwip_close( lClientFd );
            }
        }
    }

    /* Will only get here if a listening socket could not be created. */
    vTaskDelete( NULL );
}
