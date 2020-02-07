#include <stdio.h>
#include <stdlib.h>
#define v 10
/*
 * This program reads a set of edges that define an undirected graph and
 * builds an adjacency-matrix representation for the graph, setting a [i] [j]
 * and a[j] [i] to 1 if there is an edge from i to j or j to i in the graph,
 * or to 0 if there is no such edge. The program assumes that the number
 * of vertices V is a compile-time constant. Otherwise, it would need to
 * dynamically allocate the array that represents the adjacency matrix
 */
int main(void) {
    int i, j, adj[v][v];
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            adj[i][j] = 0;
    for (i = 0; i < v; i++)
        adj[i][i] = 1;
/*    printf("Enter the edges(press letter to exit): \n");*/
/*    while (scanf("%d %d\n", &i, &j) == 2) {*/
    FILE* ptr = fopen("318.txt","r");
    if (ptr==NULL)
    {
        printf("no such file.");
        return 0;
    }
    while (fscanf(ptr, "%d %d\n", &i, &j) == 2) {
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
