/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg.15.11.tst-search-for-symbol-table-adt.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-10
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
Item searchR(link h, Key v, int w) {
    int i = digit(v, w);
    if (h == NULL)
        return NULLitem;
    if (internal(h)) {
        if (i < h->d)
            return searchR(h->l, v, w);
        if (i == h->d)
            return searchR(h->m, v, w + 1);
        if (i > h->d)
            return searchR(h->r, v, w);
    }
    if
        eq(v, key(h->item)) return h->item;
    return NULLitem;
}
Item STsearch(Key v) { return searchR(heads[digit(v, 0)], v, 1); }
int main(int argc, char **argv) {}
