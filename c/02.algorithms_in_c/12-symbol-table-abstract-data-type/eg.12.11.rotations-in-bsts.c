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
#define key(A) ((A)->keyVal)
#define val(A) ((A)->value)
Key ITEMrandkey() { return (rand() % maxKey); }
Item ITEMrand(Key k) {
    Item item = malloc(sizeof(Item));
    key(item) = k;
    item->value = (rand() % maxN);
    return item;
}
void ITEMshow(Item item) {
    printf("key: %d, value: %d\n", item->keyVal, item->value);
}
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
link rotR(link h) {
    link x = h->l;
    h->l = x->r;
    x->r = h;
    return x;
}
link rotL(link h) {
    link x = h->r;
    h->r = x->l;
    x->l = h;
    return x;
}
#define NULLitem NULL
void STinit(void) { head = (z = NEW(NULLitem, 0, 0, 0)); }
int STcount(void) { return head->N; }
Item searchR(link h, Key v) {
    Key t = key(h->item);
    if (h == z)
        return NULLitem;
    if (eq(v, t))
        return h->item;
    if (less(v, t))
        return searchR(h->l, v);
    else
        return searchR(h->r, v);
}
Item STsearch(Key v) { return searchR(head, v); }
link insertT(link h, Item item) {
    Key v = key(item);
    if (h == z)
        return NEW(item, z, z, 1);
    if (less(v, key(h->item))) {
        h->l = insertT(h->l, item);
        h = rotR(h);
    } else {
        h->r = insertT(h->r, item);
        h = rotL(h);
    }
    return h;
}
void STinsert(Item item) { head = insertT(head, item); }
// print
void inordertraverse(link h) {
    if (h == z)
        return;
    inordertraverse(h->l);
        printf("%d ", key(h->item));
/*    printf("%d %d %d\n", key(h->item), val(h->item), h->N);*/
    inordertraverse(h->r);
}
#define K N/2
int main(int argc, char *argv[]) {
    int N, i;
    Item item, sitem;
    Key k, skey;
    srand(time(NULL));
    if (argc != 2)
        printf("Insufficient args. Enter N!");
    else {
        N = atoi(argv[1]);
        for (i = 0; i < N;) {
            k = ITEMrandkey();
            item = ITEMrand(k);
            printf("%d ", item->value);
            STinsert(item);
            i++;
            if (i == K - 1)
                skey = k;
        }
        printf("\n");
        sitem = STsearch(skey);
        printf("\nThe %d-th item: %d, key: %d\n", K, sitem->value,
               sitem->keyVal);
        inordertraverse(head);
    }
    return 0;
}
