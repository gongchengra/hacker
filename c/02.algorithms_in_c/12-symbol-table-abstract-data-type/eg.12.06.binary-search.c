#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define less(A, B) ((A) < (B))
#define eq(A, B) ((A) == (B))
// item
typedef int Key;
struct record {
    Key keyVal;
    int value; // Can change value type
};
typedef struct record *Item;
#define maxN 1000
#define maxKey 100
#define NULLitem NULL
#define key(A) ((A)->keyVal)
Key ITEMrandkey() { return (rand() % maxKey); }
Item ITEMrand(Key key) {
    Item item = malloc(sizeof(Item));
    key(item) = key;
    item->value = (rand() % maxN);
    return item;
}
void ITEMshow(Item item) {
    printf("key: %d, value: %d\n", item->keyVal, item->value);
}
// st
static Item *st;
static int N;
void STinit(int M) {
    st = malloc((M) * sizeof(Item));
    N = 0;
}
int STcount() { return N; }
void STinsert(Item item) {
    int j = N++;
    Key v = key(item);
    while (j > 0 && less(v, key(st[j - 1]))) {
        st[j] = st[j - 1];
        j--;
    }
    st[j] = item;
}
Item search(int l, int r, Key v) {
    int m = (l + r) / 2;

    if (l > r)
        return NULLitem;
    if (eq(v, key(st[m])))
        return st[m];
    if (l == r)
        return NULLitem;
    if (less(v, key(st[m])))
        return search(l, m - 1, v);
    else
        return search(m + 1, r, v);
}
Item STsearch(Key v) { return search(0, N - 1, v); }
Item STselect(int k) { return st[k]; }
void STsort(void (*visit)(Item)) {
    int i;
    for (i = 0; i < N; i++)
        visit(st[i]);
}
#define K N/2
int main(int argc, char *argv[]) {
    int N, i;
    Item item, sitem;
    Key key, skey;
    srand(time(NULL));
    if (argc != 2)
        printf("Insufficient args. Enter N!");
    else {
        N = atoi(argv[1]);
        STinit(N);
        for (i = 0; i < N;) {
            key = ITEMrandkey();
            if (STsearch(key) != NULLitem) {
                printf(" Duplicate key! ");
                continue;
            }
            item = ITEMrand(key);
            printf("%d ", item->value);
            STinsert(item);
            i++;
            if (i == K - 1)
                skey = key;
        }
        printf("\n");
        STsort(ITEMshow);
        printf("\n");
        sitem = STsearch(skey);
        printf("\nThe %d-th item: %d, key: %d\n", K, sitem->value,
               sitem->keyVal);
    }
    return 0;
}
