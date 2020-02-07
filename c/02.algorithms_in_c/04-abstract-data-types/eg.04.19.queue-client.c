#include "eg.04.18.first-class-adt-interface-for-queues.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
