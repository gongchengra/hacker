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
static link head, z=NULL;
link NEW(Item item, link l, link r, int N) {
    link x = malloc(sizeof *x);
    x->item = item;
    x->l = l;
    x->r = r;
    x->N = N;
    return x;
}
#define NULLitem NULL
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
void STinsert(Item item) {
    Key v = key(item);
    link p = head, x = p;
    if(head == NULL){
        head = NEW(item, NULL, NULL, 1);
        return;
    }
    while(x != NULL){
        p = x;
        x = less(v, key(x->item))? x->l:x->r;
    }
    x = NEW(item, NULL, NULL, 1);
    if(less(v, key(p->item))) p->l = x;
    else p->r = x;
}
void sortR(link h, void (*visit) (Item))
{
  if (h == z)
    return;
  sortR(h->l, visit);
  visit(h->item);
  sortR(h->r, visit);
}
void STsort(void (*visit) (Item))
{
  sortR(head, visit);
}
//print
void inordertraverse(link h) {
    if (h == z)
        return;
    inordertraverse(h->l);
    printf("%d ", key(h->item));
/*    printf("%d %d\n", key(h->item), h->N);*/
    inordertraverse(h->r);
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
        STsort(ITEMshow);
        inordertraverse(head);
    }
    return 0;
}
