#include "eg.04.18.first-class-adt-interface-for-queues.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
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
