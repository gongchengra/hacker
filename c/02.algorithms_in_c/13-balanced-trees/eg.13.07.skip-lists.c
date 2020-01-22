#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define less(A, B) ((A) < (B))
#define eq(A, B) ((A) == (B))
#define key(A) ((A)->keyVal)
#define val(A) ((A)->value)
#define maxN 1000
#define maxKey 100
#define lgNmax 5
#define NULLitem NULL
typedef int Key;
struct record {
    Key keyVal;
    int value; // Can change value type
};
typedef struct record *Item;
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
    link *next;
    int sz;
};
static link head, z;
static int N, lgN;
link NEW(Item item, int k) {
    int i;
    link x = malloc(sizeof *x);
    x->next = malloc(k * sizeof(link));
    x->item = item;
    x->sz = k;
    for (i = 0; i < k; i++)
        x->next[i] = z;
    return x;
}
void STinit() {
    N = 0;
    lgN = 0;
    z = NEW(NULLitem, 0);
    head = NEW(NULLitem, lgNmax+1);
}
int randX() {
    int i, j, t = rand();
    for (i = 1, j = 2; i < lgNmax; i++, j += j)
        if (t > RAND_MAX / j)
            break;
    if (i > lgN)
        lgN = i;
    return i;
}
void insertR(link t, link x, int k) {
    Key v = key(x->item);
    printf("v=%5d\n", v);
/*    printf("t=%5d\n", key(t->next[k]->item));*/
    return;
    if (less(v, key(t->next[k]->item))) {
        if (k < x->sz) {
            x->next[k] = t->next[k];
            t->next[k] = x;
        }
        if (k == 0)
            return;
        insertR(t, x, k - 1);
        return;
    }
    insertR(t->next[k], x, k);
}
void STinsert(Item item) {
    insertR(head, NEW(item, randX()), lgN);
    N++;
}
Item searchR(link t, Key v, int k) {
    if (t == z)
        return NULLitem;
    if (eq(v, key(t->item)))
        return t->item;
    if (less(v, key(t->next[k]->item))) {
        if (k == 0)
            return NULLitem;
        return searchR(t, v, k - 1);
    }
    return searchR(t->next[k], v, k);
}
Item STsearch(Key v) { return searchR(head, v, lgN); }
void deleteR(link t, Key v, int k) {
    link x = t->next[k];
    if (!less(key(x->item), v)) {
        if (eq(v, key(x->item))) {
            t->next[k] = x->next[k];
        }
        if (k == 0) {
            free(x);
            return;
        }
        deleteR(t, v, k - 1);
        return;
    }
    deleteR(t->next[k], v, k);
}
void STdelete(Key v) {
    deleteR(head, v, lgN);
    N--;
}
#define K N / 2
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
/*        ITEMshow(head->item);*/
/*        for (i = 0; i < N;) {*/
            k = ITEMrandkey();
            item = ITEMrand(k);
            printf("%5d\n", item->value);
            printf("%5d\n", lgN);
            printf("%5d\n", randX());
            STinsert(item);
/*            i++;*/
/*            if (i == K - 1)*/
/*                skey = k;*/
/*        }*/
/*        printf("\n");*/
/*        sitem = STsearch(skey);*/
/*        if (sitem != NULLitem) {*/
/*            printf("\nThe %d-th added item: %d, key: %d\n", K, sitem->value,*/
/*                   sitem->keyVal);*/
/*        }*/
/*        printf("\n head key is %d, head value is %d \n", key(head->item),*/
/*               val(head->item));*/
    }
    return 0;
}
