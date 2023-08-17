#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] )
{
    setvbuf( stdout, NULL, _IONBF, 0 );
    FILE * fp;
    char path[ 256 ];

    /* Open the command for reading. */
    char * cmd = "sudo qemu-system-arm -machine mps2-an385 -monitor null \
                -semihosting --semihosting-config enable=on,target=native -kernel \
                ./build/gcc/output/RTOSDemo.out -serial stdio -nographic";
    fp = popen( cmd, "r" );
    if( fp == NULL )
    {
        printf( "Failed to run command\n" );
        exit( 1 );
    }

    /* Read the output a line at a time - output it. */
    while( fgets( path, sizeof( path ), fp ) != NULL )
    {
        printf( "%s", path );
    }

    /* close */
    pclose( fp );

    return 0;
}