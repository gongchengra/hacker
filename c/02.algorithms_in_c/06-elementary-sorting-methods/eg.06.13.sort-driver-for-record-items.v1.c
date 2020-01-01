#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxN 100
struct record {
    char name[30];
    int num;
};
typedef struct record *Item;
#define exch(A, B)                                                             \
    {                                                                          \
        Item t = A;                                                            \
        A = B;                                                                 \
        B = t;                                                                 \
    }
#define compexch(A, B)                                                         \
    if (less(B, A))                                                            \
        exch(A, B);
struct record data[maxN];
int Nrecs = 0;
int ITEMscan(struct record **x) {
    *x = &data[Nrecs];
    int s =scanf("%30s %d\n", data[Nrecs].name, &data[Nrecs].num);
    Nrecs++;
    return s;
}
void ITEMshow(struct record *x) { printf("%3d %s\n", x->num, x->name); }
void scaninit(Item a[], int N) {
    int i = 0;
    for (i = 0; i < N; i++)
        if (ITEMscan(&a[i]) != 2)
            break;
}
void show(Item a[], int l, int r) {
    int i;
    for (i = l; i <= r; i++)
        ITEMshow(a[i]);
    printf("\n");
}
int less(Item a, Item b) { return a->num < b->num; }
void sort(Item a[], int l, int r) {
    int i, j;
    for (i = l + 1; i <= r; i++)
        for (j = i; j > l; j--)
            compexch(a[j - 1], a[j]);
}
int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    Item *a;
    printf("Enter records: \n");
    a = malloc(maxN * sizeof(Item));
    scaninit(a, N);
    printf("\nInitial: \n");
    show(a, 0, N - 1);
    sort(a, 0, N - 1);
    printf("Sorted: \n");
    show(a, 0, N - 1);
    return 0;
}
