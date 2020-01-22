#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
#define R 256
#define bitsword 3
#define M 4
#define digit(A, B) A[B]
#define bin(A) l + count[A]
typedef char *Item;
char *aux[100];
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
void insertion(Item a[], int l, int r) {
    int i;
    for (i = r; i > l; i--)
        compexch(a[i - 1], a[i]); // put the smallest into first position
    for (i = l + 2; i <= r; i++) {
        int j = i;
        Item v = a[i];
        while (less(v, a[j - 1])) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
    }
}
void radixMSD(Item a[], int l, int r, int w) {
    int i, j, count[R + 1];
    if (w > bitsword)
        return;
/*    if (r - l <= M) {*/
/*        insertion(a, l, r);*/
/*        return;*/
/*    }*/
    if (l >= r) return;
    for (j = 0; j < R; j++)
        count[j] = 0;
    for (i = l; i <= r; i++)
        count[digit(a[i], w) + 1]++;
    for (j = 1; j < R; j++)
        count[j] += count[j - 1];
    for (i = l; i <= r; i++)
        aux[count[digit(a[i], w)]++] = a[i];
    for (i = l; i <= r; i++)
        a[i] = aux[i - l];
    radixMSD(a, l, bin(0) - 1, w + 1);
    for (j = 0; j < R - 1; j++)
        radixMSD(a, bin(j), bin(j + 1) - 1, w + 1);
}

void sort(Item a[], int l, int r) { radixMSD(a, l, r, 0); }
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
/*
input:
jok
koi
joi
qwe
oi
joqfwe
joiqwe
ovasd
oqwe
joqw

output:
Initial: jok  koi  joi  qwe  oi  joqfwe  joiqwe  ovasd  oqwe  joqw
Sorted: joi  joiqwe  jok  joqfwe  joqw  koi  oi  oqwe  ovasd  qwe
*/
