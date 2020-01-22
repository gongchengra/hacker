#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//item
typedef int Item;
typedef int Key;
Key ITEMrand(int maxN) { return (rand() % maxN); }
Item ITEMscan(Item *x) { return scanf("%d", x); }
void ITEMshow(Item x) { printf("%d ", x); }
Key key(Item item) { return (item); }
#define NULLitem -1
#define maxKey 1000
//st
static Item *st;
static int M = maxKey;
void STinit(int maxN) {
    int i;
    st = malloc((M + 1) * sizeof(Item));
    for (i = 0; i <= M; i++)
        st[i] = NULLitem;
}
int STcount() {
    int i, N = 0;
    for (i = 0; i < M; i++)
        if (st[i] != NULLitem)
            N++;
    return N;
}
void STinsert(Item item) { st[key(item)] = item; }
Item STsearch(Key v) { return st[v]; }
void STdelete(Item item) { st[key(item)] = NULLitem; }
Item STselect(int k) {
    int i;
    for (i = 0; i < M; i++)
        if (st[i] != NULLitem)
            if (k-- == 0)
                return st[i];
    return -1;
}
void STsort(void (*visit)(Item)) {
    int i;
    for (i = 0; i < M; i++)
        if (st[i] != NULLitem)
            visit(st[i]);
}
//main
int main(int argc, char *argv[]) {
    int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    Item item;
    srand(time(NULL));
    STinit(maxN);
    for (N = 0; N < maxN; N++) {
        if (sw)
            item = ITEMrand(maxN);
        else if (ITEMscan(&item) == EOF)
            break;
        if (STsearch(item) != NULLitem)
            continue;
        printf("%d ", item);
        STinsert(item);
    }
    STsort(ITEMshow);
    printf("\n");
    printf("%d keys ", N);
    printf("%d distinct keys\n", STcount());
    return 0;
}

