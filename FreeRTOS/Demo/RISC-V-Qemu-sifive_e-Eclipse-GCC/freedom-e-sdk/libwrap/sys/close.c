/* See LICENSE of license details. */

#include "stub.h"
#include "weak_under_alias.h"
#include <errno.h>

int __wrap_close( int fd )
{
    return _stub( EBADF );
}
weak_under_alias( close );
