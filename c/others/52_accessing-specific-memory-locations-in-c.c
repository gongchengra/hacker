// https://stackoverflow.com/questions/15638105/accessing-specific-memory-locations-in-c
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>


int main(void)
{
    //  Create an int.
    int x = 0;

    //  Find its address.
    char buf[100];
    sprintf(buf, "%" PRIuPTR, (uintptr_t) &x);
    printf("The address of x is %s.\n", buf);

    //  Read the address.
    uintptr_t u;
    sscanf(buf, "%" SCNuPTR, &u);

    //  Convert the integer value to an address.
    int *p = (int *) u;

    //  Modify the int through the new pointer.
    *p = 123;

    //  Display the int.
    printf("x = %d\n", x);

    return 0;
}
