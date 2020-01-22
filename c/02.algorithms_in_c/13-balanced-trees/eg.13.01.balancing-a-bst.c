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
link insertR(link h, Item item) {
    Key v = key(item);
    Key t = (h->item == NULL) ? -1 : (key(h->item));
    if (h == z)
        return NEW(item, z, z, 1);
    if (less(v, t))
        h->l = insertR(h->l, item);
    else
        h->r = insertR(h->r, item);
    (h->N)++;
    return h;
}
void STinsert(Item item) { head = insertR(head, item); }
void sortR(link h, void (*visit)(Item)) {
    if (h == z)
        return;
    sortR(h->l, visit);
    visit(h->item);
    sortR(h->r, visit);
}
void STsort(void (*visit)(Item)) { sortR(head, visit); }
Item selectR(link h, int k) {
    int t;
    if (h == z) {
        printf("\nNULL\n");
        return NULLitem;
    }
    t = (h->l == z) ? 0 : h->l->N;
    if (t > k)
        return selectR(h->l, k);
    if (t < k)
        return selectR(h->r, k - t - 1);
    return h->item;
}
Item STselect(int k) { return selectR(head, k); }
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
link partR(link h, int k) {
    int t = h->l->N;
    if (t > k) {
        h->l = partR(h->l, k);
        h = rotR(h);
    }
    if (t < k) {
        h->r = partR(h->r, k - t - 1);
        h = rotL(h);
    }
    return h;
}
link balanceR(link h) {
    if (h->N < 2)
        return h;
    h = partR(h, (h->N) / 2);
    h->l = balanceR(h->l);
    h->r = balanceR(h->r);
    return h;
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
/*#define K N / 2*/
#define K 5
int main(int argc, char *argv[]) {
    int N, i;
    Item item, sitem;
    Key k, skey;
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
        printf("\n");
        sitem = STsearch(skey);
        printf("\nThe %d-th added item: %d, key: %d\n", K, sitem->value,
               sitem->keyVal);
        inordertraverse(head);
        Item t = STselect(K);
        printf("\n %dth key is %d, head value is %d \n", K + 1, key(t), val(t));
        printf("\n head key is %d, head value is %d \n", key(head->item),
               val(head->item));
        head = balanceR(head);
/*        head = partR(head, 2);*/
        printf("\n head key is %d, head value is %d \n", key(head->item),
               val(head->item));
        STsort(ITEMshow);
    }
    return 0;
}
