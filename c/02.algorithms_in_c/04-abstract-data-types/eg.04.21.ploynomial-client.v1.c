#include <stdio.h>
#include <stdlib.h>
typedef struct poly *Poly;
struct poly {
    int N;
    int *a;
};
Poly POLYterm(int coeff, int exp) {
    int i;
    Poly t = malloc(sizeof *t);
    /*    Poly t = malloc(sizeof(Poly));*/
    t->a = malloc((exp + 1) * sizeof(int));
    t->N = exp + 1;
    t->a[exp] = coeff;
    for (i = 0; i < exp; i++)
        t->a[i] = 0;
    return t;
}
Poly POLYadd(Poly p, Poly q) {
    int i;
    Poly t;
    if (p->N < q->N) {
        t = p;
        p = q;
        q = t;
    }
    for (i = 0; i < q->N; i++)
        p->a[i] += q->a[i];
    return p;
}
Poly POLYmult(Poly p, Poly q) {
    int i, j;
    Poly t = POLYterm(0, (p->N - 1) + (q->N - 1));
    for (i = 0; i < p->N; i++)
        for (j = 0; j < q->N; j++)
            t->a[i + j] += p->a[i] * q->a[j];
    return t;
}
float POLYeval(Poly p, float x) {
    int i;
    double t = 0.0;
    for (i = p->N - 1; i >= 0; i--)
        t = t * x + p->a[i];
    return t;
}
void showPOLY(Poly p) {
    int i, term;
    for (i = p->N - 1; i >= 0; i--)
        if ((term = p->a[i]) != 0) {
            if (i == 0) {
                if (term < 0)
                    printf("%d", term);
                else if (p->N - 1 == 0)
                    printf("%d", term);
                else
                    printf("+%d", term);
                printf("\n");
            } else if (i == 1) {
                if (term < 0)
                    printf("%dx", term);
                else
                    printf("+%dx", term);
            } else if (i < (p->N - 1)) {
                if (term < 0)
                    printf("%dx^%d", term, i);
                else
                    printf("+%dx^%d", term, i);
            } else if (term != 1) {
                if (term < 0)
                    printf("%dx^%d", term, i);
                else
                    printf("%dx^%d", term, i);
            } else {
                if (term < 0)
                    printf("x^%d", i);
                else
                    printf("x^%d", i);
            }
        }
}
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
