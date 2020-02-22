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
#define val(A) ((A)->value)
#define eq(A, B) ((A) == (B))
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
void STinit(void) {
    head = (z = NEW(NULLitem, 0, 0, -1));
    head->l = head;
    head->r = head;
}
Item searchR(link h, Key v, int w) {
    if (h->bit <= w)
        return h->item;
    if (digit(v, h->bit) == 0)
        return searchR(h->l, v, h->bit);
    else
        return searchR(h->r, v, h->bit);
}
Item STsearch(Key v) {
    Item t = searchR(head->l, v, -1);
    return eq(v, key(t)) ? t : NULLitem;
}

link insertR(link h, Item item, int w, link p) {
    link x;
    Key v = key(item);
    if ((h->bit >= w) || (h->bit <= p->bit)) {
        x = NEW(item, 0, 0, w);
        x->l = digit(v, x->bit) ? h : x;
        x->r = digit(v, x->bit) ? x : h;
        return x;
    }
    if (digit(v, h->bit) == 0)
        h->l = insertR(h->l, item, w, h);
    else
        h->r = insertR(h->r, item, w, h);
    return h;
}
void STinsert(Item item) {
    int i;
    Key v = key(item);
    Key t = key(searchR(head->l, v, -1));
    if (v == t)
        return;
    for (i = 0; digit(v, i) == digit(t, i); i++)
        ;
    head->l = insertR(head->l, item, i, head);
}
void sortR(link h, void(*visit)(Item), int w){
    if(h->bit <= w){visit(h->item);return;}
    sortR(h->l, visit, h->bit);
    sortR(h->r, visit, h->bit);
}
void STsort(void (*visit)(Item)){
    sortR(head->l, visit, -1);
}
// print
void inordertraverse(link h) {
    if (h == z)
        return;
    inordertraverse(h->l);
    /*    printf("%d ", key(h->item));*/
    printf("%d %d %d\n", key(h->item), val(h->item), h->N);
    inordertraverse(h->r);
}
#define K N / 2
int main(int argc, char *argv[]) {
    int N, i;
    Item item, sitem;
    Key k, key, skey;
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
            if (i == K - 1)
                skey = k;
        }
        sitem = STsearch(skey);
        if (sitem == NULLitem) {
            printf("%s", "not found!");
        } else {
            printf("\nThe %d-th added item: %d, key: %d\n", K, key(sitem),
                   val(sitem));
        }
        inordertraverse(head);
    }
    return 0;
}
