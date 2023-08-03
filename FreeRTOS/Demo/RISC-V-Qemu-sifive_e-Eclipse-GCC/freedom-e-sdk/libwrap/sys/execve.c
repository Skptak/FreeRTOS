/* See LICENSE of license details. */

#include "stub.h"
#include "weak_under_alias.h"
#include <errno.h>

int __wrap_execve( const char * name, char * const argv[], char * const env[] )
{
    return _stub( ENOMEM );
}
weak_under_alias( execve );
