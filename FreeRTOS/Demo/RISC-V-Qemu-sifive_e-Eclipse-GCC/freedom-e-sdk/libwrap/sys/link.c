/* See LICENSE of license details. */

#include "stub.h"
#include "weak_under_alias.h"
#include <errno.h>

int __wrap_link( const char * old_name, const char * new_name )
{
    return _stub( EMLINK );
}
weak_under_alias( link );
