#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
#define less(A, B) ((A) < (B))
#define eq(A, B) ((A) == (B))
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
link insertR(link h, Item item) {
    Key v = key(item);
    Key t = (h->item == NULL) ? -1 : (key(h->item));
    if (h == z)
        return NEW(item, z, z, 1);
    srand(time(NULL));
    if(rand()<RAND_MAX/(h->N+1))
        return insertT(h, item);
    if (less(v, t))
        h->l = insertR(h->l, item);
    else
        h->r = insertR(h->r, item);
    (h->N)++;
    return h;
}
void STinsert(Item item) { head = insertR(head, item); }
#define K 4 // The K-th item is searched
int main(int argc, char *argv[]) {
    int N, i;
    Item item, sitem;
    Key key, skey;
    srand(time(NULL));
    if (argc != 2)
        printf("Insufficient args. Enter N!\n");
    else {
        N = atoi(argv[1]);
        STinit();
        for (i = 0; i < N; i++) {
            key = ITEMrandkey();
            item = ITEMrand(key);
            printf("%d ", item->value);
            STinsert(item);
            if (i == K - 1)
                skey = key;
        }
        sitem = STsearch(skey);
        printf("\nThe %d-th item: %d, key: %d\n", K, sitem->value,
               sitem->keyVal);
    }
    return 0;
}
