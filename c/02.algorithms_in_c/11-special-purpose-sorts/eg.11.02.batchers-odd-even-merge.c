#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int itemType;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)                                                             \
    {                                                                          \
        itemType t = A;                                                        \
        A = B;                                                                 \
        B = t;                                                                 \
    }
#define compexch(A, B)                                                         \
    if (less(B, A))                                                            \
    exch(A, B)
itemType *aux;
void shuffle(itemType a[], int l, int r) {
    int i, j, m = (l + r) / 2;
    for (i = l, j = 0; i <= r; i += 2, j++) {
        aux[i] = a[l + j];
        aux[i + 1] = a[m + 1 + j];
    }
    for (i = l; i <= r; i++)
        a[i] = aux[i];
    printf("\nshuffle:\n");
    for (i = l; i <= r; i++)
        printf("%4d", a[i]);
    printf("\n");
}
void unshuffle(itemType a[], int l, int r) {
    int i, j, m = (l + r) / 2;
    for (i = l, j = 0; i <= r; i += 2, j++) {
        aux[l + j] = a[i];
        aux[m + 1 + j] = a[i + 1];
    }
    for (i = l; i <= r; i++)
        a[i] = aux[i];
    printf("\nunshuffle:\n");
    for (i = l; i <= r; i++)
        printf("%4d", a[i]);
    printf("\n");
}
void mergeTD(itemType a[], int l, int r) {
    int i, m = (l + r) / 2;
    if (r == l + 1) {
        compexch(a[l], a[r]);
        printf("cmpexch %d %d\n", a[l], a[r]);
    }
    if (r < l + 2)
        return;
    unshuffle(a, l, r);
    mergeTD(a, l, m);
    mergeTD(a, m + 1, r);
    shuffle(a, l, r);
    for (i = l + 1; i < r; i += 2) {
        compexch(a[i], a[i + 1]);
        printf("cmpexch %d %d\n", a[i], a[i+1]);
    }
}
void print_list(int n, int a[]) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int main(int argc, char *argv[]) {
    int N, i;
    itemType *a;
    itemType *b;
    itemType *c;
    srand(time(NULL));
    if (argc != 2)
        printf("Missing argument. Enter a power of 2 number!");
    else {
        N = atoi(argv[1]);
        a = malloc(N * sizeof(itemType));
        b = malloc(N * sizeof(itemType));
        c = malloc(2 * N * sizeof(itemType));
        aux = malloc(2 * (N + 1) * sizeof(itemType));
        for (i = 0; i < N; i++) {
            a[i] = rand() % 1000;
            b[i] = rand() % 1000;
        }
        qsort(a, N, sizeof(int), cmp);
        qsort(b, N, sizeof(int), cmp);
        for (i = 0; i < 2 * N; i++) {
            if (i < N)
                c[i] = a[i];
            else
                c[i] = b[i - N];
        }
        printf("Before: ");
        print_list(2 * N, c);
        mergeTD(c, 0, 2 * N - 1);
        printf("After: ");
        print_list(2 * N, c);
    }
    return 0;
}
