#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)                                                             \
    {                                                                          \
        Item t = A;                                                            \
        A = B;                                                                 \
        B = t;                                                                 \
    }
#define compexch(A, B)                                                         \
    if (less(B, A))                                                            \
    exch(A, B)
typedef double Item;
double ITEMrand(void) { return 1.0 * rand() / RAND_MAX; }
Item ITEMscan(double *x) { return scanf("%lf", x); }
void ITEMshow(double x) { printf("%7.5f ", x); }
void randinit(Item a[], int N) {
    int i;
    for (i = 0; i < N; i++)
        a[i] = ITEMrand();
}
void scaninit(Item a[], int *N) {
    int i = 0;
    for (i = 0; i < *N; i++)
        if (ITEMscan(&a[i]) == EOF)
            break;
    *N = i;
}
void show(Item a[], int l, int r) {
    int i;
    for (i = l; i <= r; i++)
        ITEMshow(a[i]);
    printf("\n");
}
void sort(Item a[], int l, int r) {
    int i, j;
    for (i = l + 1; i <= r; i++)
        for (j = i; j > l; j--)
            compexch(a[j - 1], a[j]);
}
int main(int argc, char *argv[]) {
    int N, sw;
    Item *a;
    srand(time(NULL));
    if (argc < 3)
        printf("You have not entered enough arguments: N and sw required!\n ");
    else {
        N = atoi(argv[1]);
        sw = atoi(argv[2]);
        a = malloc(N * sizeof(Item));
        if (sw)
            randinit(a, N);
        else
            scaninit(a, &N);
        printf("Initial: ");
        show(a, 0, N - 1);
        sort(a, 0, N - 1);
        printf("Sorted: ");
        show(a, 0, N - 1);
    }
    return 0;
}
