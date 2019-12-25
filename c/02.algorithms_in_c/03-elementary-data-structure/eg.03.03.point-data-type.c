#include "point.h"
#include <stdio.h>
// gcc eg.03.03.point-data-type.c eg.03.04.point-type-implementation.c -o
// eg.03.03.point-data-type.exe
int main(void) {
    point a, b;
    a.x = 1;
    a.y = 1;
    b.x = 2;
    b.y = 2;
    printf("%f\n", distance(a, b));
    return 0;
}
