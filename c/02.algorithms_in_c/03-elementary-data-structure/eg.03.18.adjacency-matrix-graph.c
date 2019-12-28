#include <stdio.h>
#include <stdlib.h>
#define v 10
int main(void) {
    int i, j, adj[v][v];
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            adj[i][j] = 0;
    for (i = 0; i < v; i++)
        adj[i][i] = 1;
    printf("Enter the edges(press letter to exit): \n");
    while (scanf("%d %d\n", &i, &j) == 2) {
        adj[i][j] = 1;
        adj[j][i] = 1;
    }
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
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
q
output:
1 0 1 0 0 0 0 0 1 0
0 1 0 0 0 0 1 0 0 0
1 0 1 1 0 0 0 0 0 1
0 0 1 1 1 0 0 1 0 0
0 0 0 1 1 0 0 0 1 1
0 0 0 0 0 1 1 0 0 1
0 1 0 0 0 1 1 0 0 0
0 0 0 1 0 0 0 1 0 0
1 0 0 0 1 0 0 0 1 0
0 0 1 0 1 1 0 0 0 1
*/
