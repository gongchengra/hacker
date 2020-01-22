#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)                                                             \
    {                                                                          \
        Item t = A;                                                            \
        A = B;                                                                 \
        B = t;                                                                 \
    }
#define test(C, B, A) 4 * (C) + 2 * (B) + 1 * (A)
#define maxBQsize 10
#define z NULL
typedef int Item;
typedef struct pq *PQ;
typedef struct PQnode *PQlink;
struct PQnode {
    Item key;
    PQlink l, r;
};
struct pq {
    PQlink *bq;
};
PQ PQinit() {
    int i;
    PQ p = malloc(sizeof(struct pq));
    p->bq = malloc(maxBQsize * sizeof(PQlink));
    for (i = 0; i < maxBQsize; i++) {
        p->bq[i] = z;
    }
    return p;
}
int PQempty(PQ pq) {
    int i;
    for (i = 0; i < maxBQsize; i++)
        if (pq->bq[i] != z)
            return 0;
    return 1;
}
PQlink pair(PQlink p, PQlink q) {
    if (less(p->key, q->key)) {
        p->r = q->l;
        q->l = p;
        return q;
    } else {
        q->r = p->l;
        p->l = q;
        return p;
    }
}
PQlink PQinsert(PQ pq, Item v) {
    int i;
    PQlink c, t = malloc(sizeof *t);
    c = t;
    c->l = z;
    c->r = z;
    c->key = v;
    for (i = 0; i < maxBQsize; i++) {
        if (c == z)
            break;
        if (pq->bq[i] == z) {
            pq->bq[i] = c;
            break;
        }
        c = pair(c, pq->bq[i]);
        pq->bq[i] = z;
    }
    return t;
}
void BQjoin(PQlink *a, PQlink *b) {
    int i;
    PQlink c = z;
    for (i = 0; i < maxBQsize; i++)
        switch (test(c != z, b[i] != z, a[i] != z)) {
        case 2:
            a[i] = b[i];
            break;
        case 3:
            c = pair(a[i], b[i]);
            a[i] = z;
            break;
        case 4:
            a[i] = c;
            c = z;
            break;
        case 5:
            c = pair(c, a[i]);
            a[i] = z;
            break;
        case 6:
        case 7:
            c = pair(c, b[i]);
            break;
        }
}
Item PQdelmax(PQ pq) {
    int i, max;
    PQlink x;
    Item v;
    PQlink temp[maxBQsize];
    for (i = 0, max = -1; i < maxBQsize; i++)
        if (pq->bq[i] != z)
            if ((max == -1) || less(v, pq->bq[i]->key)) {
                max = i;
                v = pq->bq[max]->key;
            }
    x = pq->bq[max]->l;
    for (i = max; i < maxBQsize; i++)
        temp[i] = z;
    for (i = max; i > 0; i--) {
        temp[i - 1] = x;
        x = x->r;
        temp[i - 1]->r = z;
    }
    free(pq->bq[max]);
    pq->bq[max] = z;
    BQjoin(pq->bq, temp);
    return v;
}
void PQjoin(PQ a, PQ b) { BQjoin(a->bq, b->bq); }
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
