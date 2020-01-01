#include <stdio.h>
#include <stdlib.h>
#define N 8
typedef int Item;
typedef struct node *nlink;
struct node {
    int v;
    nlink next;
};
nlink new_node(int v, nlink next) {
    nlink x = malloc(sizeof *x);
    x->v = v;
    x->next = next;
    return x;
}

typedef struct queue *Q;
typedef struct QUEUEnode *link;
struct QUEUEnode {
    Item item;
    link next;
};
struct queue {
    link head;
    link tail;
};
link new (Item item, link next) {
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}
Q QUEUEinit(int maxN) {
    Q q = malloc(sizeof *q);
    q->head = NULL;
    return q;
}
int QUEUEempty(Q q) { return q->head == NULL; }
void QUEUEput(Q q, Item item) {
    if (q->head == NULL) {
        q->tail = new (item, q->head);
        q->head = q->tail;
        return;
    }
    q->tail->next = new (item, q->tail->next);
    q->tail = q->tail->next;
}
Item QUEUEget(Q q) {
    Item item = q->head->item;
    link t = q->head->next;
    free(q->head);
    q->head = t;
    return item;
}
/*
                         0
                    _____|_____
                   /  /  |  \  \
                  /  /   |   \  \
                 /   1---7---2   \
                /        |        6
                5----3   |       /
                 \    \ /       /
                  \____4_______/
  0 -> 7 -> 5 -> 2 -> 1 -> 6
  1 -> 7 -> 0
  2 -> 7 -> 0
  3 -> 5 -> 4
  4 -> 6 -> 5 -> 7 -> 3
  5 -> 0 -> 4 -> 3
  6 -> 4 -> 0
  7 -> 1 -> 2 -> 0 -> 4
 */
Q q;
int visited[N];
nlink *adj;
nlink *make_list(void) {
    nlink *l;
    l = malloc(N * sizeof(l));
    l[0] =
        new_node(7, new_node(5, new_node(2, new_node(1, new_node(6, NULL)))));
    l[1] = new_node(7, new_node(0, NULL));
    l[2] = new_node(7, new_node(0, NULL));
    l[3] = new_node(5, new_node(4, NULL));
    l[4] = new_node(6, new_node(5, new_node(7, new_node(3, NULL))));
    l[5] = new_node(0, new_node(4, new_node(3, NULL)));
    l[6] = new_node(4, new_node(0, NULL));
    l[7] = new_node(1, new_node(2, new_node(0, new_node(4, NULL))));
    return l;
}
void print_list_array(nlink *l, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d -> ", i);
        while (l[i] != NULL) {
            printf("%d ", l[i]->v);
            l[i] = l[i]->next;
        }
        printf("\n");
    }
}
void traverse(int k, void (*visit)(int)) {
    nlink t;
    q = QUEUEinit(N);
    QUEUEput(q, k);
    while (!QUEUEempty(q))
        if (visited[k = QUEUEget(q)] == 0) {
            (*visit)(k);
            visited[k] = 1;
            for (t = adj[k]; t != NULL; t = t->next)
                if (visited[t->v] == 0)
                    QUEUEput(q, t->v);
        }
}
void print_val(int k) { printf("%d ", k); }
int main(void) {
    int i;
    // create list-graph representation
    adj = make_list();
    // all nodes are not visited yet
    for (i = 0; i <= N; i++)
        visited[i] = 0;
    // traverse list-graph
    traverse(0, print_val);
    printf("\n\n");
    // print the list-graph
    print_list_array(adj, N);
    return 0;
}
