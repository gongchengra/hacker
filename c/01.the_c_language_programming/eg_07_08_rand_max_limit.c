#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define frand() ((double)rand() / (RAND_MAX + 1.0))
int main() {
    /*    time_t t;*/
    /*    srand((unsigned) time(&t));*/
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        printf("%d\n", rand());
        printf("%f\n", frand());
    }
    printf("RAND_MAX is %d\n", RAND_MAX);

    printf("The number of bits in a byte %d\n", CHAR_BIT);

    printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

    printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
    printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);

    printf("The minimum value of INT = %d\n", INT_MIN);
    printf("The maximum value of INT = %d\n", INT_MAX);

    printf("The minimum value of CHAR = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR = %d\n", CHAR_MAX);

    printf("The minimum value of LONG = %ld\n", LONG_MIN);
    printf("The maximum value of LONG = %ld\n", LONG_MAX);

    return (0);
}
