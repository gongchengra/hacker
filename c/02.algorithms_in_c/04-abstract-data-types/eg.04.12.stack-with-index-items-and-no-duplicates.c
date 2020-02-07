#include "stack.h"
#include <stdlib.h>
static int *s, *t;
static int N;
void STACKinit(int maxn) {
    int i;
    s = malloc(maxn * sizeof(int));
    t = malloc(maxn * sizeof(int));
    for (i = 0; i < maxn; i++)
        t[i] = 0;
    N = 0;
}
int STACKempty(void) { return !N; }
void STACKpush(int item) {
    if (t[item] == 1)
        return;
    s[N++] = item;
    t[item] = 1;
}
int STACKpop(void) {
    N--;
    t[s[N]] = 0;
    return s[N];
}
