#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "root.h"

void preordertraverse(link h, void (*visit)(link)) {
    if (h == NULL)
        return;
    (*visit)(h);
    preordertraverse(h->l, visit);
    preordertraverse(h->r, visit);
}
void inordertraverse(link h, void (*visit)(link)) {
    if (h == NULL)
        return;
    inordertraverse(h->l, visit);
    (*visit)(h);
    inordertraverse(h->r, visit);
}
void postordertraverse(link h, void (*visit)(link)) {
    if (h == NULL)
        return;
    postordertraverse(h->l, visit);
    postordertraverse(h->r, visit);
    (*visit)(h);
}
int main(void) {
    link root = init();
    preordertraverse(root, print_node);
    printf("\n");
    inordertraverse(root, print_node);
    printf("\n");
    postordertraverse(root, print_node);
    printf("\n");
    return 0;
}
