#include "item.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
static Item *q;
static int n, head, tail;
void QUEUEinit(int maxn) {
    q = malloc((maxn + 1) * sizeof(Item));
    n = maxn + 1;
    head = n;
    tail = 0;
}
int QUEUEempty(void) { return head % n == tail; }
void qprint(void) {
    printf("qprint: ");
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    printf("\n");
}
void QUEUEput(Item item) {
    q[tail++] = item;
    tail = tail % n;
    qprint();
}
Item QUEUEget() {
    qprint();
    head = head % n;
    return q[head++];
}
