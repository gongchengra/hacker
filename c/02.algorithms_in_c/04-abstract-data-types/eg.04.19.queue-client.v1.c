#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define eq(a, b) ((a) == (b))
typedef struct queue *Q;
typedef struct QUEUEnode *link;
struct queue {
    link head;
    link tail;
};
struct QUEUEnode {
    Item item;
    link next;
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
#define M 10
/*
 * Program 4.19 is a driver program that exemplifies such a client.
 * It randomly assigns N items to one of 1\J FIFO queues, then prints
 * out the contents of the queues, by removing the items one by one.
 */
int main(int argc, char *argv[]) {
    int i, j, N = atoi(argv[1]);
    Q queues[M];
    srand(time(NULL));
    for (i = 0; i < M; i++)
        queues[i] = QUEUEinit(N);
    for (j = 0; j < N; j++)
        QUEUEput(queues[rand() % M], j);
    for (i = 0; i < M; i++, printf("\n"))
        for (j = 0; !QUEUEempty(queues[i]); j++)
            printf("%3d ", QUEUEget(queues[i]));
    return 0;
}
