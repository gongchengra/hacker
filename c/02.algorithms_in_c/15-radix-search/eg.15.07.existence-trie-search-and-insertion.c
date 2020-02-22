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
    link next[R];
};
static link head;
void STinit() { head = NULL; }
link NEW() {
    int i;
    link x = malloc(sizeof *x);
    for (i = 0; i < R; i++)
        x->next[i] = NULL;
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
    return searchR(h->next[i], v, w + 1);
}
Item STsearch(Key v) { return searchR(head, v, 0); }
link insertR(link h, Item item, int w) {
    Key v = key(Item);
    int i = digit(v, w);
    if (h == NULL)
        h = NEW();
    if (i == NULLdigit)
        return h;
    h->next[i] = insertR(h->next[i], v, w + 1);
    return h;
}
void STinsert(Item item) { head = insertR(head, item, 0); }
