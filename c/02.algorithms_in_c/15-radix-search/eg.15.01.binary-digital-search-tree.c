#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// item
typedef int Key;
struct record {
    Key keyVal;
    int value; // Can change value type
};
typedef struct record *Item;
#define maxN 1000
#define maxKey 1000
#define key(A) ((A)->keyVal)
#define bitsword 32
#define bitsbyte 1
#define R (1 << bitsbyte)
#define digit(A, B) (((A) >> (bitsword - ((B) + 1) * bitsbyte)) & (R - 1))
Key ITEMrandkey() { return (rand() % maxKey); }
Item ITEMrand(Key k) {
    Item item = malloc(sizeof(Item));
    key(item) = k;
    item->value = (rand() % maxN);
    return item;
}
// st
typedef struct STnode *link;
struct STnode {
    Item item;
    link l;
    link r;
    int N;
};
static link head, z;
link NEW(Item item, link l, link r, int N) {
    link x = malloc(sizeof *x);
    x->item = item;
    x->l = l;
    x->r = r;
    x->N = N;
    return x;
}
#define NULLitem NULL
void STinit(void) { head = (z = NEW(NULLitem, 0, 0, 0)); }
int STcount(void) { return head->N; }
Item searchR(link h, Key v, int w) {
    Key t = key(h->item);
    if (h == z)
        return NULLitem;
    if (digit(v, w) == 0)
        return searchR(h->l, v, w+1);
    else
        return searchR(h->r, v, w+1);
}
Item STsearch(Key v) { return searchR(head, v, 20); }
link insertR(link h, Item item, int w) {
    Key v = key(item);
/*    printf("\ndigit(v, w) is %d ", digit(v,w));*/
    if (h == z)
        return NEW(item, z, z, 1);
    if (digit(v, w) == 0 && w < 31)
        h->l = insertR(h->l, item, w+1);
    else
        h->r = insertR(h->r, item, w+1);
    (h->N)++;
    return h;
}
void STinsert(Item item) { head = insertR(head, item, 20); }
int main(int argc, char *argv[]) {
    int N, i;
    Item item, sitem;
    Key k, key;
    srand(time(NULL));
    if (argc != 2)
        printf("Insufficient args. Enter N!");
    else {
        N = atoi(argv[1]);
        STinit();
        for (i = 0; i < N;) {
            k = ITEMrandkey();
            item = ITEMrand(k);
            printf("%d ", item->value);
            STinsert(item);
            i++;
        }
    }
    return 0;
}
