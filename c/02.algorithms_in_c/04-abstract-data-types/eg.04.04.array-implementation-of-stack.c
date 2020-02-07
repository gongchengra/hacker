#include "item.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
static Item *s;
static int N;
void STACKinit(int maxn) {
    s = malloc(maxn * sizeof(Item));
    N = 0;
}
void STACKprint() {
    for (int i = 0; i <= N; i++)
        printf("%d ", s[i]);
    printf("\n");
}
int STACKempty(void) { return N == 0; }
void STACKpush(Item item) { s[++N] = item; }
Item STACKpop(void) { return s[N--]; }
