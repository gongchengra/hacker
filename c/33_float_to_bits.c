#include <limits.h> /* for CHAR_BIT */
#include <stdint.h>
#include <stdio.h>

// https://stackoverflow.com/questions/44609743/obtaining-bit-representation-of-a-float-in-c
/** formatted output of ieee-754 representation of float */
void show_float(float f) {
    union {
        float f;
        uint32_t u;
    } fu = {.f = f}; // fu.f = f;
    int i, j;
    i = sizeof f * CHAR_BIT;
    j = i - 1;

    printf(" ");
    while (i--)
        printf("%d ", (fu.u >> i) & 0x1);

    putchar('\n');
    printf("|");
    while (j--)
        printf("- ");
    printf("-|\n");
    printf("|s|%9s%6s|%25s%20s|\n\n", "exp", "", "mantissa", "");
    /*    printf(" |s|      exp      |                  mantissa"*/
    /*           "                    |\n\n");*/
}

void show_double(double d) {
    union {
        double d;
        uint64_t u;
    } du = {.d = d};
    int i, j;
    i = sizeof d * CHAR_BIT;
    j = i - 1;
    printf(" ");
    while (i--)
        printf("%llu ", (du.u >> i) & 0x1);

    putchar('\n');
    printf("|");
    while (j--)
        printf("- ");
    printf("-|\n");
    printf("|s|%12s%9s|%55s%48s|\n\n", "exp", "", "mantissa", "");
}

// Another way
// https://www.geeksforgeeks.org/program-for-conversion-of-32-bits-single-precision-ieee-754-floating-point-representation/

void printBinary(int n, int i) {
    // Prints the binary representation
    // of a number n up to i-bits.
    int k;
    for (k = i - 1; k >= 0; k--) {

        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}

typedef union {

    float f;
    struct {
        // Order is important.
        // Here the members of the union data structure
        // use the same memory (32 bits).
        // The ordering is taken
        // from the LSB to the MSB.
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;

    } raw;
} myfloat;

// Function to convert real value
// to IEEE foating point representation
void printIEEE(myfloat var) {

    // Prints the IEEE 754 representation
    // of a float value (32 bits)

    printf("%d | ", var.raw.sign);
    printBinary(var.raw.exponent, 8);
    printf(" | ");
    printBinary(var.raw.mantissa, 23);
    printf("\n");
}

int main(void) {

    // float f = 3.14159f;
    float f;
    printf("Please input the float number you want to convert:\n");
    scanf("%f", &f);

    printf("\nIEEE-754 Single-Precision representation of: %f\n\n", f);
    show_float(f);

    printf("\nIEEE-754 Double-Precision representation of: %f\n\n", f);
    show_double(f);

    myfloat var;
    var.f = f;
    printf("IEEE 754 representation of %f is : \n", var.f);
    printIEEE(var);
    return 0;
}
