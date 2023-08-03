/* See LICENSE of license details. */

#include "stub.h"
#include <errno.h>

int fork( void )
{
    return _stub( EAGAIN );
}
