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
Key ITEMrandkey() { return (rand() % maxKey); }
Item ITEMrand(Key key) {
    Item item = malloc(sizeof(Item));
    item->keyVal = key;
    item->value = (rand() % maxN);
    return item;
}
void ITEMshow(Item item) {
    printf("key: %d, value: %d\n", item->keyVal, item->value);
}
#define key(A) ((A)->keyVal)
#define val(A) ((A)->value)
/*Key key(Item item) { return (item == NULLitem) ? -1 : item->keyVal; }*/
/*Key val(Item item) { return (item == NULLitem) ? -1 : item->value; }*/
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
    Key v = item->keyVal;
    Key t = (h->item == NULLitem) ? -1 : (h->item->keyVal);
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
link joinLR(link a, link b) {
    if (b == z)
        return a;
    b = partR(b, 0);
    b->l = a;
    return b;
}
link deleteR(link h, Key v) {
    link x;
    Key t = key(h->item);
    if (h == z)
        return z;
    if (less(v, t))
        h->l = deleteR(h->l, v);
    if (less(t, v))
        h->r = deleteR(h->r, v);
    if (eq(v, t)) {
        x = h;
        h = joinLR(h->l, h->r);
        free(x);
    }
    return h;
}
void STdelete(Key v) { head = deleteR(head, v); }
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
void fixN(link h) {
    if (h->item == NULLitem) {
        h->N = 0;
    } else {
        fixN(h->l);
        fixN(h->r);
        h->N = (h->l->N) + (h->r->N) + 1;
    }
}
link joinR(link a, link b);
link STjoin(link a, link b);
link joinR(link a, link b) {
    if (a == z)
        return b;
    b = insertR(b, a->item);
    b->l = STjoin(a->l, b->l);
    b->r = STjoin(a->r, b->r);
    fixN(b);
    free(a);
    return b;
}
link STjoin(link a, link b) {
/*    printf("%d %d\n", a->N, b->N);*/
    /*    return b;*/
    if ((rand() / (RAND_MAX / (a->N + b->N + 1) + 1)) < a->N)
        return joinR(a, b);
    else
        return joinR(b, a);
}
/*link STjoin(link a, link b) {*/
/*    if (b == z)*/
/*        return a;*/
/*    if (a == z)*/
/*        return b;*/
/*    b = insertT(b, a->item);*/
/*    b->l = STjoin(a->l, b->l);*/
/*    b->r = STjoin(a->r, b->r);*/
/*    free(a);*/
/*    return b;*/
/*}*/
void inordertraverse(link h) {
    if (h == z)
        return;
    inordertraverse(h->l);
    /*    printf("%d ", key(h->item));*/
    printf("%d %d %d\n", key(h->item), val(h->item), h->N);
    inordertraverse(h->r);
}
int main(int argc, char *argv[]) {
    int N, i;
    Item item, sitem;
    Key key, skey;
    link a, b;
    z = NEW(NULLitem, 0, 0, 0);
    a = b = z;
    srand(time(NULL));
    if (argc != 2)
        printf("Insufficient args. Enter N!\n");
    else {
        N = atoi(argv[1]);
        for (i = 0; i < N; i++) {
            key = ITEMrandkey();
            item = ITEMrand(key);
            /*            printf("insert a %d\n", item->value);*/
            a = insertR(a, item);
            skey = (1 + rand() % 10) * key;
            sitem = ITEMrand(skey);
            /*            printf("insert b %d\n", sitem->value);*/
            b = insertR(b, sitem);
        }
        printf("traverse a:\n");
        inordertraverse(a);
        printf("traverse b:\n");
        inordertraverse(b);
        printf("traverse joined b:\n");
        inordertraverse(STjoin(a, b));
/*                fixN(b);*/
/*                inordertraverse(b);*/
    }
    return 0;
}
