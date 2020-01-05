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
#define push2(A, B)                                                            \
    STACKpush(B);                                                              \
    STACKpush(A);
typedef int Item;
static Item *s;
static int N;
void STACKinit(int maxn) {
    s = malloc(maxn * sizeof(Item));
    N = 0;
}
int STACKempty(void) { return N == 0; }
void STACKpush(Item item) { s[++N] = item; }
Item STACKpop(void) { return s[N--]; }
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
        exch(a[i], a[j]);
    }
    exch(a[i], a[r]);
    return i;
}
void quicksort(Item a[], int l, int r) {
    int i;
    STACKinit((l + r) / 2);
    push2(l, r);
    while (!STACKempty()) {
        l = STACKpop();
        r = STACKpop();
        if (r <= l)
            continue;
        i = partition(a, l, r);
        if (i - l > r - i) {
            push2(l, i - 1);
            push2(i + 1, r);
        } else {
            push2(i + 1, r);
            push2(l, i - 1);
        }
    }
}
int main(int argc, char *argv[]) {
    int i = 0, N, sw, *a;
    srand(time(NULL));
    if (argc < 3)
        printf("You have not entered enough arguments: N and sw required!\n ");
    else {
        N = atoi(argv[1]);
        a = malloc(N * sizeof(int));
        sw = atoi(argv[2]);
        if (sw)
            for (i = 0; i < N; i++)
                a[i] = 1000 * (1.0 * rand() / RAND_MAX);
        else
            while (i < N && scanf("%d", &a[i++]) == 1)
                ;
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
