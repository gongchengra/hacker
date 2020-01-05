#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
typedef int Item;
typedef struct node *link;
struct node {
    Item item;
    link next;
};
link init(int N) {
    int i;
    link t, head = malloc(sizeof(link));
    srand(time(NULL));
    head->item = rand() % 1000;
    head->next = NULL;
    for (i = 0, t = head; i < N - 1; i++) {
        t->next = malloc(sizeof *t);
        t = t->next;
        t->item = rand() % 1000;
    }
    t->next = NULL;
    return head;
}
void print_list(link t) {
    while (t != NULL) {
        printf("%d ", t->item);
        t = t->next;
    }
    printf("\n");
}
link merge(link a, link b) {
    struct node head;
    link c = &head;
    while ((a != NULL) && (b != NULL))
        if (less(a->item, b->item)) {
            c->next = a;
            c = a;
            a = a->next;
        } else {
            c->next = b;
            c = b;
            b = b->next;
        }
    c->next = (a == NULL) ? b : a;
    return head.next;
}
link msort(link c) {
    link a, b;
    if (c == NULL || c->next == NULL)
        return c;
    a = c;
    b = c->next;
    while ((b != NULL) && (b->next != NULL)) {
        c = c->next;
        b = b->next->next;
    }
    b = c->next;
    c->next = NULL;
    return merge(msort(a), msort(b));
}
int main(int argc, char *argv[]) {
    int N;
    link a;
    if (argc < 2)
        printf("You have not entered enough arguments: N required!\n ");
    else {
        N = atoi(argv[1]);
        a = init(N);
        printf("Before: ");
        print_list(a);
        printf("After: ");
        print_list(msort(a));
    }
    return 0;
}
