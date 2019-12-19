#include <limits.h>
#include <stdio.h>
#include <float.h>
int main() {
    printf("bit of char = %d\n", CHAR_BIT);

    printf("sizeof(char) = %ld\n", sizeof(char));
    printf("Unsigned char: %d\t%d\n", 0, UCHAR_MAX);
    printf("Signed char: %d\t%d\n", SCHAR_MIN, SCHAR_MAX);

    printf("sizeof(short) = %ld\n", sizeof(short));
    printf("Unsigned short: %d\t%d\n", 0, USHRT_MAX);
    printf("(Signed) short: %d\t%d\n", SHRT_MIN, SHRT_MAX);

    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("Unsigned int: %d\t%u\n", 0, UINT_MAX);
    printf("(Signed) int: %d\t%d\n", INT_MIN, INT_MAX);

    printf("sizeof(long) = %ld\n", sizeof(long));
    printf("Unsigned long: %d\t%lu\n", 0, ULONG_MAX);
    printf("(Signed) long: %ld\t%ld\n", LONG_MIN, LONG_MAX);

    printf("sizeof(long long) = %ld\n", sizeof(long long));
    printf("Unsigned long long: %d\t%llu\n", 0, ULLONG_MAX);
    printf("(Signed) long long: %lld\t%lld\n", LLONG_MIN, LLONG_MAX);

    printf("sizeof(float) = %ld\n", sizeof(float));
    printf("sizeof(double) = %ld\n", sizeof(double));
    printf("sizeof(long double) = %ld\n", sizeof(long double));

    printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
    printf("-FLT_MAX    :   %g\n", (float) -FLT_MAX);
    printf("-FLT_MIN    :   %g\n", (float) -FLT_MIN);
    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
    printf("-DBL_MAX     :  %g\n", (double) -DBL_MAX);
    printf("Precision value: %d\n", FLT_DIG );
    return 0;
}
