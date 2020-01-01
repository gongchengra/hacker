#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "root.h"
#include "queue.h"
#define MAX 8
void traverse(link h, void (*visit)(link)) {
    QUEUEinit(MAX);
    QUEUEput(h);
    while (!QUEUEempty()) {
        (*visit)(h = QUEUEget());
        if (h->l != NULL)
            QUEUEput(h->l);
        if (h->r != NULL)
            QUEUEput(h->r);
    }
}
int main(void) {
    link root = init();
    traverse(root, print_node);
    printf("\n");
    return 0;
}
