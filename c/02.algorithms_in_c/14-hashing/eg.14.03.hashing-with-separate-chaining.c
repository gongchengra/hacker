#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef char *Key;
struct record {
    Key keyVal;
    int value; // Can change value type
};
typedef struct record *Item;
#define maxN 1000
#define maxKey 100
#define NULLitem NULL
Item ITEMrand(Key key) {
    Item item = malloc(sizeof(Item));
    item->keyVal = malloc(sizeof(key));
    strcpy(item->keyVal, key);
    item->value = (rand() % maxN);
    return item;
}
void ITEMshow(Item item) {
    if (item != NULLitem)
        printf("key: %s, value: %d\n", item->keyVal, item->value);
    else
        printf("NULLitem \n");
}
Key key(Item item) { return (item == NULLitem) ? '\0' : item->keyVal; }
typedef struct STnode *link;
struct STnode {
    Item item;
    link next;
};
static link *heads, z;
static int N, M;
int hash(char *v, int M) {
    int h, a = 31415, b = 27183;
    for (h = 0; *v != '\0'; v++, a = a * b % (M - 1))
        h = (a * h + *v) % M;
    return h;
}
int eq(char *a, char *b) { return (strcmp(a, b) == 0); }
static link NEW(Item item, link next) {
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}
Item search(link h, Key v) {
    while (h != z) {
        if (eq(key(h->item), v))
            return h->item;
        h = h->next;
    }
    return z->item;
}
void STinit(int max) {
    int i;
    N = 0;
    M = max / 5;
    heads = malloc(M * sizeof(link));
    z = NEW(NULLitem, NULL);
    for (i = 0; i < M; i++)
        heads[i] = z;
}
void STinsert(Item item) {
    int i = hash(key(item), M);
    heads[i] = NEW(item, heads[i]);
    N++;
}
Item STsearch(Key v) { return search(heads[hash(v, M)], v); }
link delete (link h, Item item) {
    link l = h, t;
    if (l == z)
        return z;
    if (eq(key(l->item), key(item))) {
        free(l->next);
        h = z;
        return h;
    }
    t = l->next;
    while (t != z) {
        if (eq(key(t->item), key(item))) {
            l->next = t->next;
            free(t);
            break;
        }
        t = t->next;
    }
    return h;
}
void STdelete(Item item) {
    int i = hash(key(item), M);
    heads[i] = delete (heads[i], item);
}
#define S 3
int main(int argc, char *argv[]) {
    int N, i;
    Item item, itm;
    Key searched_key = malloc(2 * sizeof(char)), key = malloc(2 * sizeof(char));
    char init = 'a';
    srand(time(NULL));
    if (argc != 2)
        printf("Insufficient args. Enter N > 4!");
    else {
        N = atoi(argv[1]);
        if (N > 30) {
            printf("Enter 4 < value < 30\n");
            return 0;
        }
        STinit(N);
        for (i = 0; i < N; i++) {
            key[0] = init + i;
            key[1] = '\0';
            item = ITEMrand(key);
            ITEMshow(item);
            if (i == S)
                strcpy(searched_key, key);
            STinsert(item);
        }
        printf("\n");
        printf("Searching for element with key \'%s\'! ", searched_key);
        itm = STsearch(searched_key);
        ITEMshow(itm);
        printf("Deleting item!\n");
        STdelete(itm);
        printf("Searching for element with key \'%s\'! ", searched_key);
        ITEMshow(STsearch(searched_key));
    }
    return 0;
}
