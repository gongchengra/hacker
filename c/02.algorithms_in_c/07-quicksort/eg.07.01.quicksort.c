#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)                                                             \
    {                                                                          \
        Item t = A;                                                            \
        A = B;                                                                 \
        B = t;                                                                 \
    }
int partition(Item a[], int l, int r) {
    int i = l - 1, j = r;
    Item v = a[r];
    for (;;) {
        while (less(a[++i], v))
            ;
        while (less(v, a[--j]))
            if (j == l)
                break;
        if (i >= j)
            break;
        if (less(a[j], a[i])) {
            //printf("exch %d with %d\n", i, j);
            exch(a[i], a[j]);
        }
    }
    if (less(a[r], a[i])) {
        //printf("r exch %d with %d\n", i, r);
        exch(a[i], a[r]);
    }
    return i;
}
void quicksort(Item a[], int l, int r) {
    int i;
    if (r <= l)
        return;
    i = partition(a, l, r);
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}
int main(int argc, char *argv[]) {
    int i = 0, N, sw;
    int *a = malloc(N * sizeof(int));
    srand(time(NULL));
    if (argc < 3)
        printf("You have not entered enough arguments: N and sw required!\n ");
    else {
        N = atoi(argv[1]);
        sw = atoi(argv[2]);
        if (sw)
            for (i = 0; i < N; i++)
                a[i] = 1000 * (1.0 * rand() / RAND_MAX);
        else
            while (i < N && scanf("%d", &a[i]) == 1)
                i++;
        printf("Initial: ");
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\nAfter: ");
        quicksort(a, 0, N - 1);
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\n");
    }
    return 0;
}
