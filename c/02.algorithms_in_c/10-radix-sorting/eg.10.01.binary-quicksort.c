#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define exch(A, B)                                                             \
    {                                                                          \
        Item t = A;                                                            \
        A = B;                                                                 \
        B = t;                                                                 \
    }
#define bitsword 32
#define bitsbyte 1
#define bytesword 4
#define R (1 << bitsbyte)
#define digit(A, B) (((A) >> (bitsword - ((B) + 1) * bitsbyte)) & (R - 1))
/*#define digit(A, B) (key(A) & (int)1 << (bitsword - (B)-1)) ? 1 : 0*/
/*int digit(int a, int b) { return (a & (int)1 << (bitsword - b - 1)) ? 1 : 0; }*/
/*int digit(int a, int b) { return a >> (bitsword - b - 1) & 1; }*/
void quicksortB(Item a[], int l, int r, int w) {
    int i = l, j = r;
    if (r <= l || w > bitsword)
        return;
    while (j != i) {
        while (digit(a[i], w) == 0 && (i < j))
            i++;
        while (digit(a[j], w) == 1 && (j > i))
            j--;
        if (i != j){
            exch(a[i], a[j]);
        }
    }
    if (digit(a[r], w) == 0)
        j++;
    quicksortB(a, l, j - 1, w + 1);
    quicksortB(a, j, r, w + 1);
}
// (1000)10 = (00000000000000000000001111101000)2
// so it is save to start from 20th bit.
void sort(Item a[], int l, int r) { quicksortB(a, l, r, 20); }
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
