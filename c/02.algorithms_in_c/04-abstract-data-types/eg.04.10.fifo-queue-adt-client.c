#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
#define MAX 1000
int main(void) {
    int n;
    /*    printf("Enter the length of the queue: ");*/
    /*    scanf("%d", &n);*/
    n = LEN;
    QUEUEinit(n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        QUEUEput(rand() % MAX);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", QUEUEget());
    }
    return 0;
}
