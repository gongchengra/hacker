#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
typedef struct pq *PQ;
typedef struct PQnode *PQlink;
struct PQnode {
    Item key;
    PQlink prev, next;
};
struct pq {
    PQlink head, tail;
};
PQ PQinit() {
    PQ pq = malloc(sizeof(*pq));
    PQlink h = malloc(sizeof(*h));
    PQlink t = malloc(sizeof(*t));
    h->prev = t;
    h->next = t;
    t->prev = h;
    t->next = h;
    pq->head = h;
    pq->tail = t;
    return pq;
}
int PQempty(PQ pq) { return pq->head->next->next == pq->head; }
PQlink PQinsert(PQ pq, Item v) {
    PQlink t = malloc(sizeof(*t));
    t->key = v;
    t->next = pq->head->next;
    t->next->prev = t;
    t->prev = pq->head;
    pq->head->next = t;
    return t;
}
Item PQdelmax(PQ pq) {
    Item max;
    struct PQnode *t, *x = pq->head->next;
    for (t = x; t->next != pq->head; t = t->next)
        if (t->key > x->key)
            x = t;
    max = x->key;
    x->next->prev = x->prev;
    x->prev->next = x->next;
    free(x);
    return max;
}
void PQchange(PQ pq, PQlink x, Item v) { x->key = v; }
void PQdelete(PQ pq, PQlink x) {
    x->next->prev = x->prev;
    x->prev->next = x->next;
    free(x);
}
void PQjoin(PQ a, PQ b) {
    a->tail->prev->next = b->head->next;
    b->head->next->prev = a->tail->prev;
    a->head->prev = b->tail;
    b->tail->next = a->head;
    free(a->tail);
    free(b->head);
}
int main(int argc, char *argv[]) {
    int N, M, i;
    Item x;
    PQ q1, q2;
    srand(time(NULL));
    if (argc < 3)
        printf("You have not entered enough arguments: N and Mrequired!\n ");
    else {
        N = atoi(argv[1]);
        M = atoi(argv[2]);
        q1 = PQinit();
        q2 = PQinit();
        printf("Creating first queue: ");
        for (i = 0; i < N; i++) {
            x = rand() % 1000;
            printf("%d ", x);
            PQinsert(q1, x);
        }
        printf("\nCreating the second queue: ");
        for (i = 0; i < M; i++) {
            x = rand() % 1000;
            printf("%d ", x);
            PQinsert(q2, x);
        }
        printf("\nMax from Q1: %d", PQdelmax(q1));
        printf("\nMax form Q2: %d", PQdelmax(q2));
        printf("\nMerged queues: ");
        PQjoin(q1, q2);
        while (!PQempty(q1))
            printf("%d ", PQdelmax(q1));
        printf("\n");
    }
    return 0;
}
