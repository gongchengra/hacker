#include <stdio.h>
#include <stdlib.h>
#define N 8
#include "link.h"
#include "init.h"
void traverse(int k, void (*visit)(int)) {
    nlink t;
    (*visit)(k);
    visited[k] = 1;
    for (t = adj[k]; t != NULL; t = t->next) {
        if (!visited[t->v])
            traverse(t->v, visit);
    }
}
int main(void) {
    int i;
    // create list-graph representation
    adj = make_list();
    // all nodes are not visited yet
    for (i = 0; i <= N; i++)
        visited[i] = 0;
    // traverse list-graph
    traverse(0, print_val);
    printf("\n\n");
    // print the list-graph
    print_list_array(adj, N);
    return 0;
}

