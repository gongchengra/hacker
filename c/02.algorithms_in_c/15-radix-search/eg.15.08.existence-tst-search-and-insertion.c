#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Key;
typedef int Item;
#define bitsword 32
#define bitsbyte 1
#define R (1 << bitsbyte)
#define digit(A, B) (((A) >> (bitsword - ((B) + 1) * bitsbyte)) & (R - 1))
typedef struct STnode *link;
struct STnode {
    int d;
    link l, m, r;
};
static link head;
void STinit() { head = NULL; }
link NEW(int d) {
    link x = malloc(sizeof *x);
    x->d = d;
    x->l = NULL;
    x->m = NULL;
    x->r = NULL;
    return x;
}
#define NULLitem NULL
#define NULLdigit NULL
Item searchR(link h, Key v, int w) {
    init i = digit(v, w);
    if (h == NULL)
        return NULLitem;
    if (i == NULLdigit)
        return v;
    if (i < h->d)
        return searchR(h->l, v, w);
    if (i == h->d)
        return searchR(h->m, v, w);
    if (i > h->d)
        return searchR(h->r, v, w);
}
Item STsearch(Key v) { return searchR(head, v, 0); }
link insertR(link h, Item item, int w) {
    Key v = key(Item);
    int i = digit(v, w);
    if (h == NULL)
        h = NEW(i);
    if (i == NULLdigit)
        return h;
    if (i < h->d)
        h->l = insertR(h->l, v, w);
    if (i == h->d)
        h->m = insertR(h->m, v, w+1);
    if (i > h->d)
        h->r = insertR(h->r, v, w);
    return h;
}
void STinsert(Item item) { head = insertR(head, item, 0); }
