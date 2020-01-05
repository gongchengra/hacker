#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
int cmp(const void *i, const void *j) { return (*(int *)i - *(int *)j); }
int main() {
    int i, a[N];
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        a[i] = 1000 * (1.0 * rand() / RAND_MAX);
        printf("%d ", a[i]);
    }
    mergesort(a, N, sizeof(int), cmp);
    printf("\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
}
