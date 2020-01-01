#include "record.h"
#include <stdio.h>
#define maxN 100
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

