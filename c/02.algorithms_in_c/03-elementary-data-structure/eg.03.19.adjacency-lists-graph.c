#include <stdio.h>
#include <stdlib.h>
#define V 10
typedef struct node *link;
struct node {
    int v;
    link next;
};
link new (int v, link next) {
    link x = malloc(sizeof *x);
    x->v = v;
    x->next = next;
    return x;
}
void print_list(link t, int x) {
    printf("%d - ", x);
    while (t != NULL) {
        printf("%d ", t->v);
        t = t->next;
    }
    printf("\n");
}
int main(void) {
    int i, j;
    link adj[V];
    for (i = 0; i < V; i++)
        adj[i] = NULL;
    printf("Enter the edges(press letter to exit): \n");
    while (scanf("%d %d\n", &i, &j) == 2) {
        adj[j] = new (i, adj[j]);
        adj[i] = new (j, adj[i]);
    }
    for (i = 0; i < V; i++)
        print_list(adj[i], i);
    return 0;
}
/*
input:
0 6
0 2
0 7
0 1
0 5
6 4
2 7
7 4
7 1
5 3
5 4
4 3
q
output:


*/
