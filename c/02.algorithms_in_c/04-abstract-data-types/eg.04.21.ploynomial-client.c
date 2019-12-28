#include "poly.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int N = atoi(argv[1]), i;
    float p = atof(argv[2]);
    Poly t, x;
    printf("Binomial coefficients\n");
    t = POLYadd(POLYterm(1, 5), POLYterm(1, 0));
    for (i = 0, x = t; i < N - 1; i++) {
        x = POLYmult(t, x);
        showPOLY(x);
    }
    printf("%f\n", POLYeval(x, p));
    return 0;
}
