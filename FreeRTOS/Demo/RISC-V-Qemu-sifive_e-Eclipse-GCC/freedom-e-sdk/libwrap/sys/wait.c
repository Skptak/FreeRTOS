/* See LICENSE of license details. */

#include "stub.h"
#include <errno.h>

int wait( int * status )
{
    return _stub( ECHILD );
}
