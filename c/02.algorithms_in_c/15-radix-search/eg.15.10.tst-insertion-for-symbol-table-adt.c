/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg.15.10.tst-insertion-for-symbol-table-adt.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-10
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#define NULLdigit '\0'
#define internal(A) ((A->d) != NULLdigit)
link NEWx(link h, int d) {
    link x = malloc(sizeof *x);
    x->item = NULLitem;
    x->d = d;
    x->l = NULL;
    x->r = NULL;
    return x;
}
link split(link p, link q, int w) {
    int pd = digit(p->item, w), qd = digit(q->item, w);
    link t = NEW(NULLitem, qd);
    if (pd < qd) {
        t->m = q;
        t->l = NEWx(p, pd);
    }
    if (pd == qd) {
        t->m = split(p, q, w + 1);
    }
    if (pd > qd) {
        t->m = p;
        t->l = NEWx(p, pd);
    }
}
link insertR(link h, Item item, int w) {
    Key v = key(item);
    int i = digit(v, w);
    if(h == NULL) {
        return NEWx(NEW(item, NULLdigit), i);
    }
    if(!internal(h)) {
        return split(NEW(item, NULLdigit), h, w);
    }
    if (i < h->d) {
        h->l = insertR(h->l, v, w);
    }
    if (i == h->d) {
        h->m = insertR(h->m, v, w+1);
    }
    if (i > h->d) {
        h->r = insertR(h->r, v, w);
    }
    return h;
}
void STinsert(Key key) {
    int i = digit(key, 0);
    heads[i] = insertR(heads[i], key, 1);
}
int main(int argc, char **argv) {}
