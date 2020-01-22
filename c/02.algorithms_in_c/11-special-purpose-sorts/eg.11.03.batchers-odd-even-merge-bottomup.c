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
void mergeBU(itemType a[], int l, int r) {
    int i, j, k, N = r - l + 1;
    for (k = N / 2; k > 0; k /= 2)
        for (j = k % (N / 2); j + k < N; j += (k + k))
            for (i = 0; i < k; i++)
                compexch(a[l + j + i], a[l + j + i + k]);
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
    itemType *a, *b, *c;
    srand(time(NULL));
    if (argc != 2)
        printf("Missing argument. Enter a power of 2 number!");
    else {
        N = atoi(argv[1]);
        a = malloc(N * sizeof(itemType));
        b = malloc(N * sizeof(itemType));
        c = malloc(2 * N * sizeof(itemType));
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
        mergeBU(c, 0, 2 * N - 1);
        printf("After: ");
        print_list(2 * N, c);
    }
    return 0;
}
