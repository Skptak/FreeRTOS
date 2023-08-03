/* See LICENSE of license details. */

#include "stub.h"
#include "weak_under_alias.h"
#include <errno.h>
#include <sys/times.h>

clock_t __wrap_times( struct tms * buf )
{
    return _stub( EACCES );
}
weak_under_alias( times );
