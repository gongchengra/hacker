#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//item
typedef char *Item;
#define key(A) (A)
#define less(A, B) (strcmp(key(A), key(B)) < 0)
#define exch(A, B)                                                             \
    {                                                                          \
        Item t = A;                                                            \
        A = B;                                                                 \
        B = t;                                                                 \
    }
#define compexch(A, B)                                                         \
    if (less(B, A))                                                            \
    exch(A, B)
static char buf[100000];
static int cnt = 0;
int ITEMscan(char **x) {
    int t;
    *x = &buf[cnt];
    t = scanf("%s", *x);
    cnt += strlen(*x) + 1;
    return t;
}
void ITEMshow(char *x) { printf("%s  ", x); }
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
    int N;
    Item *a;
    srand(time(NULL));
    if (argc < 2)
        printf("You have not entered enough arguments: N and sw required!\n ");
    else {
        N = atoi(argv[1]);
        a = malloc(N * sizeof(Item));
        scaninit(a, &N);
        printf("Initial: ");
        show(a, 0, N - 1);
        sort(a, 0, N - 1);
        printf("Sorted: ");
        show(a, 0, N - 1);
    }
    return 0;
}
