#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
void sort(Item a[], int l, int r) {
    int i, j;
    for (i = l; i < r; i++) {
        int min = i;
        for (j = i + 1; j <= r; j++)
            if (less(a[j], a[min]))
                min = j;
        exch(a[i], a[min]);
    }
}
int main(int argc, char *argv[]) {
    int i, N, sw;
    int *a = malloc(N * sizeof(int));
    srand(time(NULL));
    if (argc < 3)
        printf("You have not entered enough arguments: N and sw required!\n ");
    else {
        N = atoi(argv[1]);
        sw = atoi(argv[2]);
        if (sw)
            for (i = 0; i < N; i++)
                a[i] = 1000 * (1.0 * rand() / RAND_MAX);
        else
            for (i = 0; scanf("%d", &a[i]) == 1 && i < N; i++)
                ;
        printf("Initial: ");
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\nAfter: ");
        sort(a, 0, N - 1);
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\n");
    }
    return 0;
}
