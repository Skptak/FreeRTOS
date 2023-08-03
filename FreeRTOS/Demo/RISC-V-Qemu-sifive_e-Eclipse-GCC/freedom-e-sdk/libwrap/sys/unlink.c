/* See LICENSE of license details. */

#include "stub.h"
#include "weak_under_alias.h"
#include <errno.h>

int __wrap_unlink( const char * name )
{
    return _stub( ENOENT );
}
weak_under_alias( unlink );
