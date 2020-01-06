#include <stdio.h>
#include <stdlib.h>

#include <pigpio.h>

#include "wiegand.h"

/*

REQUIRES

Wiegand contacts 0 and 1 connected to separate gpios.

TO BUILD

gcc -o wiegand_c test_wiegand.c wiegand.c -lpigpio -lrt

TO RUN

sudo ./wiegand_c

*/

void callback(int bits, uint32_t value)
{
    printf("%u\n", value);
}

int main(int argc, char *argv[])
{
    Pi_Wieg_t * w;
    int gpio0 = 17;
    int gpio1 = 18;

    if( 3 > argc ) {
        printf( "Usage: %s <pin0> <pin1>\n", argv[0] );
        return 0;
    }
    gpio0 = atoi( argv[1] );
    gpio1 = atoi( argv[2] );

    if (gpioInitialise() < 0) return 1;

    w = Pi_Wieg( gpio0, gpio1, callback, 5 );
    sleep(300);

    Pi_Wieg_cancel(w);

    gpioTerminate();
}

