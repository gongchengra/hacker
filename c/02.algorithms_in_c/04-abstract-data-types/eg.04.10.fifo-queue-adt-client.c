#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int n;
    printf("Enter the length of the queue: ");
    scanf("%d", &n);
    QUEUEinit(n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        QUEUEput(rand());
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", QUEUEget());
    }
    return 0;
}
