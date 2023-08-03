/* See LICENSE of license details. */

#include "platform.h"
#include "weak_under_alias.h"
#include <unistd.h>

void __wrap_exit( int code )
{
    const char message[] = "\nProgam has exited with code:";

    write( STDERR_FILENO, message, sizeof( message ) - 1 );
    write_hex( STDERR_FILENO, code );
    write( STDERR_FILENO, "\n", 1 );

    for( ;; )
        ;
}
weak_under_alias( exit );
