#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "root.h"
#include "stack.h"

void traverse(link h, void (*visit)(link)) {
    STACKinit(MAX);
    STACKpush(h);
    while (!STACKempty()) {
        (*visit)(h = STACKpop());
        if (h->r != NULL)
            STACKpush(h->r);
        if (h->l != NULL)
            STACKpush(h->l);
    }
}

int main(void) {
    link root = init();
    traverse(root, print_node);
    printf("\n");
    return 0;
}
