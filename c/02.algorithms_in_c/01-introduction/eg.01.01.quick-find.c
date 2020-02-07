#include <stdio.h>
#define N 1000
int main(void) {
    int p, q, i, t, id[N];
    for (i = 0; i < N; i++)
        id[i] = i;
/*    while (scanf("%d %d\n", &p, &q) == 2) {*/
    FILE* ptr = fopen("101.txt","r");
    if (ptr==NULL)
    {
        printf("no such file.");
        return 0;
    }
    while (fscanf(ptr, "%d %d\n", &p, &q) == 2) {
        if (id[p] == id[q])
            continue;
        for (t = id[p], i = 0; i < N; i++)
            if (id[i] == t)
                id[i] = id[q];
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
