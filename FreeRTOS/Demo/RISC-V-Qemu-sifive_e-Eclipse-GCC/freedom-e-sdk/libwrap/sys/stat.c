/* See LICENSE of license details. */

#include "stub.h"
#include "weak_under_alias.h"
#include <errno.h>
#include <sys/stat.h>

int __wrap_stat( const char * file, struct stat * st )
{
    return _stub( EACCES );
}
weak_under_alias( stat );
