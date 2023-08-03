/* See LICENSE of license details. */

#include "stub.h"
#include "weak_under_alias.h"
#include <errno.h>

int __wrap_kill( int pid, int sig )
{
    return _stub( EINVAL );
}
weak_under_alias( kill );
