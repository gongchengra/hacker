#include <stdio.h>
#include <stdlib.h>

typedef int Item;
int eq(Item x, Item y) { return (x == y); }

typedef struct node *link;
struct node {
    Item item;
    link next;
};
link new (Item item) {
    link t = malloc(sizeof(struct node));
    t->item = item;
    t->next = NULL;
    return t;
}

#define N 10
int count(link x) {
    if (x == NULL)
        return 0;
    return 1 + count(x->next);
}
void traverse(link h, void (*visit)(link)) {
    if (h == NULL)
        return;
    (*visit)(h);
    traverse(h->next, visit);
}
void traverseR(link h, void (*visit)(link)) {
    if (h == NULL)
        return;
    traverseR(h->next, visit);
    (*visit)(h);
}
link delete (link x, Item v) {
    if (x == NULL)
        return NULL;
    if (eq(x->item, v)) {
        link t = x->next;
        free(x);
        return t;
    }
    x->next = delete (x->next, v);
    return x;
}
void node_print(link t) { printf("%d ", t->item); }

int main(void) {
    link head, l;
    int i;
    head = new (0);
    for (i = 1, l = head; i < N; i++) {
        l->next = new (i);
        l = l->next;
    }
    printf("\nCount: %d\n", count(head));
    traverse(head, node_print);
    printf("\n");
    traverseR(head, node_print);
    printf("\n");
    delete(head, 3);
    delete(head, 5);
    traverse(head, node_print);
    printf("\n");
    return 0;
}
