#include <stdio.h>
struct st {
    int a, b;
    double f;
} s, *ps;
int main() {
    double a = 6.8;
    double *pd = &a;
    float b = 6.5;
    float *pf = &b;
    char c = 'G';
    char *pc = &c;
    int *p = NULL;
    printf("%ld %ld %ld %ld %ld\n", sizeof(pd), sizeof(pf), sizeof(pc),
           sizeof(p), sizeof(ps));
    return 0;
}
