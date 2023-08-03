/* See LICENSE of license details. */

#include "stub.h"
#include "weak_under_alias.h"
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

off_t __wrap_lseek( int fd, off_t ptr, int dir )
{
    if( isatty( fd ) )
        return 0;

    return _stub( EBADF );
}
weak_under_alias( lseek );
