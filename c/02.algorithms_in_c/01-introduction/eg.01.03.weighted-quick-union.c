#include <stdio.h>
#define N 1000
int main(void) {
    int p, q, i, j, id[N], sz[N];
    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (scanf("%d %d\n", &p, &q) == 2) {
        for (i = p; i != id[i]; i = id[i])
            ;
        for (j = q; j != id[j]; j = id[j])
            ;
        if (i == j)
            continue;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        printf(" %d %d\n", p, q);
    }
    return 0;
}
/*
input:
3 4
4 9
8 0
2 3
5 6
2 9
5 9
7 3
4 8
5 6
0 2
6 1
output:
 3 4
 4 9
 8 0
 2 3
 5 6
 5 9
 7 3
 4 8
 6 1
because these pairs provide new connections.
  */
