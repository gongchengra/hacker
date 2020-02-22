#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
int max(int a[], int l, int r) {
    int u, v;
    int m = (l + r) / 2;
    /*    printf("%d %d %d\n",l, m, r);*/
    if (l == r)
        return a[l];
    u = max(a, l, m);
    v = max(a, m + 1, r);
    return (u > v) ? u : v;
}
int main(void) {
    int i, a[N];
    srand(time(NULL));
    for (i = 0; i < N; i++){
        a[i] = rand() % (20 * N);
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Max: %d\n", max(a, 0, N - 1));
    return 0;
}
