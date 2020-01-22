#include "item.h"
#include "st.h"
#include <stdio.h>
#include <stdlib.h>
Key ITEMrand(int maxN) { return (rand() % maxN); }
Item ITEMscan(Item *x) { return scanf("%d", x); }
void ITEMshow(Item x) { printf("%d ", x); }
Key key(Item item) { return (item); }
