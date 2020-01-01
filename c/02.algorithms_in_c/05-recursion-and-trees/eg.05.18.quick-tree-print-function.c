#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "root.h"

void printnode(char c, int h) {
    int i;
    for (i = 0; i < h; i++)
        printf("   ");
    printf("%c\n", c);
}

void show(link x, int h) {
    if (x == NULL) {
        printnode('*', h);
        return;
    }
    show(x->r, h + 1);
    printnode(x->val, h);
    show(x->l, h + 1);
}

int main(void) {
    link root = init();
    show(root, 1);
    return 0;
}
