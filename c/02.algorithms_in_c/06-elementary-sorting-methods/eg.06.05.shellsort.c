#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(Item a[], int l, int r) {
    int i, j, h;
    for (h = 1; h <= (r - l) / 9; h = 3 * h + 1)
        ;
    //printf("\n h is %d\n", h);
    for (; h > 0; h /= 3)
        for (i = l + h; i <= r; i++) {
            int j = i;
            //printf("\ni = %d, j = %d, h = %d\n", i, j, h);
            Item v = a[i];
            while (j >= l + h && less(v, a[j - h])) {
            //for (int k = 0; k < 10; k++) printf("%3d ", a[k]);
            //printf("\na[j] %d = a[j - h] %d\n", a[j], a[j-h]);
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = v;
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
        sort(a, 0, N - 1);
        printf("\nAfter: ");
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\n");
    }
    return 0;
}
