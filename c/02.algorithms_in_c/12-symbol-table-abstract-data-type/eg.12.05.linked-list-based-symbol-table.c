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
// st
typedef struct STnode *link;
struct STnode {
    Item item;
    link next;
};
static link head, z;
static int N;
static link NEW(Item item, link next) {
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}
void STinit(int max) {
    N = 0;
    head = (z = NEW(NULLitem, NULL));
}
int STcount() { return N; }
Item searchR(link t, Key v) {
    if (t == z)
        return NULLitem;
    if (eq(key(t->item), v))
        return t->item;
    return searchR(t->next, v);
}
Item STsearch(Key v) { return searchR(head, v); }
void STinsert(Item item) {
    head = NEW(item, head);
    N++;
}
#define S 4
int main(int argc, char *argv[]) {
    int N, i;
    Item item;
    Key key, searched_key;
    srand(time(NULL));
    if (argc != 2)
        printf("Insufficient args. Enter N > 4!");
    else {
        N = atoi(argv[1]);
        STinit(N);
        for (i = 0; i < N; i++) {
            key = ITEMrandkey();
            if (STsearch(key) != NULLitem) {
                printf(" Duplicate key! ");
                continue;
            }
            item = ITEMrand(key);
            if (i == S)
                searched_key = key;
            printf("%d ", item->value);
            STinsert(item);
        }
        printf("\n");
        printf("The element with the key %d is: ", searched_key);
        ITEMshow(STsearch(searched_key));
    }
    return 0;
}
