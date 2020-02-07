#include <stdio.h>
#include <stdlib.h>
typedef struct node *link;
struct node {
    int item;
    struct node *next;
};
/*
 * Figure 3.7 p116
 * To reverse the order of a list, we maintain a pointer r to the portion of the
 * list already processed, and a pointer y to the portion of the list not yet
 * seen. This diagram shows how the pointers change for each node in the list.
 * We save a pointer to the node following y in t, change y's link to point to
 * r, and then move r to y and y to t.
 */
link reverse(link x) {
    link t, y = x, r = NULL;
    while (y != NULL) {
        t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    return r;
}
void print_list(link t) {
    while (t != NULL) {
        printf("%d ", t->item);
        t = t->next;
    }
    printf("\n");
}
int main(int argc, char *argv[]) {
    int i, N = atoi(argv[1]);
    link t = malloc(sizeof *t), head = t, x;
    t->item = 1;
    t->next = NULL;
    for (i = 2; i <= N; i++) {
        t->next = malloc(sizeof *x);
        t = t->next;
        t->item = i;
        t->next = NULL;
    }
    print_list(head);
    head = reverse(head);
    print_list(head);
    return 0;
}
