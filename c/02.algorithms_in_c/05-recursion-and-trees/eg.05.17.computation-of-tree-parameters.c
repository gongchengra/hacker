#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "root.h"
int count(link h) {
    if (h == NULL)
        return 0;
    return count(h->l) + count(h->r) + 1;
}
int height(link h) {
    int u, v;
    if (h == NULL)
        return -1;
    u = height(h->l);
    v = height(h->r);
    if (u > v)
        return u + 1;
    else
        return v + 1;
}
int main(void) {
    link root =init();
    printf("Number of nodes: %d\n", count(root));
    printf("Height of the tree: %d\n", height(root));
    return 0;
}
