#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define bitsword 32
#define bitsbyte 1
#define R (1 << bitsbyte)
#define digit(A, B) (((A) >> (bitsword - ((B) + 1) * bitsbyte)) & (R - 1))
#define MAX 100
Item aux[MAX];
void radixLSD(Item a[], int l, int r) {
    int i, j, w, count[R + 1];
    for (w = bitsword - 1; w >= 0; w--) {
        for (j = 0; j < R; j++)
            count[j] = 0;
        for (i = l; i <= r; i++)
            count[digit(a[i], w) + 1]++;
        for (j = 1; j < R; j++)
            count[j] += count[j - 1];
        for (i = l; i <= r; i++)
            aux[count[digit(a[i], w)]++] = a[i];
        for (i = l; i <= r; i++)
            a[i] = aux[i - l];
    }
}
void sort(Item a[], int l, int r) { radixLSD(a, l, r); }
int main(int argc, char *argv[]) {
    int i = 0, N, sw;
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
            while (i < N && scanf("%d", &a[i]) == 1)
                i++;
        printf("Initial: ");
        for (i = 0; i < N; i++)
            printf("%4d", a[i]);
        printf("\nAfter: ");
        sort(a, 0, N - 1);
        for (i = 0; i < N; i++)
            printf("%4d", a[i]);
        printf("\n");
    }
    return 0;
}
