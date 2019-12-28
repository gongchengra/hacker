#include "item.h"
#include "stack.h"
#include <stdlib.h>
static Item *s;
static int N;
void STACKinit(int maxn) {
    s = malloc(maxn * sizeof(Item));
    N = 0;
}
int STACKempty(void) { return N == 0; }
void STACKpush(Item item) { s[++N] = item; }
Item STACKpop(void) { return s[N--]; }
