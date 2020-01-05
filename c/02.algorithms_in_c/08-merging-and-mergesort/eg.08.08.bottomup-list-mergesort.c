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
static link *q;
static int n, head, tail;
void QUEUEinit(int maxn) {
    q = malloc((maxn + 1) * sizeof(link));
    n = maxn + 1;
    head = n;
    tail = 0;
}
int QUEUEempty(void) { return head % n == tail; }
void QUEUEput(link item) {
    q[tail++] = item;
    tail = tail % n;
}
link QUEUEget() {
    head = head % n;
    return q[head++];
}
int N;
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
link msort(link t) {
    link u;
    for (QUEUEinit(N); t != NULL; t = u) {
        u = t->next;
        t->next = NULL;
        QUEUEput(t);
    }
    t = QUEUEget();
    while (!QUEUEempty()) {
        QUEUEput(t);
        t = merge(QUEUEget(), QUEUEget());
    }
    return t;
}
int main(int argc, char *argv[]) {
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
