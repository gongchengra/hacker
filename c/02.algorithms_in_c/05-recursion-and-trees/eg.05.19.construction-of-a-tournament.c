#include <stdio.h>
#include <stdlib.h>
typedef char Item;
typedef struct node *link;
struct node {
    Item item;
    link l;
    link r;
};
link new_node(Item item, link l, link r) {
    link x = malloc(sizeof *x);
    x->item = item;
    x->r = r;
    x->l = l;
    return x;
}
link max(Item a[], int l, int r) {
    int m = (l + r) / 2;
    Item u, v;
    link x = new_node(a[m], NULL, NULL);
    if (l == r)
        return x;
    x->l = max(a, l, m);
    x->r = max(a, m + 1, r);
    u = x->l->item;
    v = x->r->item;
    if (u > v)
        x->item = u;
    else
        x->item = v;
    return x;
}
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
    printnode(x->item, h);
    show(x->l, h + 1);
}
int main(void) {
    Item a[] = {'A', 'M', 'P', 'L', 'E'};
    link root;
    root = max(a, 0, 4);
    show(root, 1);
    return 0;
}
