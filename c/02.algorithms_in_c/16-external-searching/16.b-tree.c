#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define M 4
#define maxN 1000
#define maxKey 100
#define NULLitem NULL
typedef char *Key;
struct record {
    Key keyVal;
    int value; // Can change value type
};
typedef struct record *Item;
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
typedef struct {
    Key key;
    union {
        link next;
        Item item;
    } ref;
} entry;
struct STnode {
    entry b[M];
    int m;
};
static link head;
static int H, N;
int eq(char *a, char *b) { return (strcmp(a, b) == 0); }
int less(char *a, char *b) { return (strcmp(a, b) < 0); }
link NEW() {
    link x = malloc(sizeof *x);
    x->m = 0;
    return x;
}
void STinit() {
    head = NEW();
    H = 0;
    N = 0;
}
Item searchR(link h, Key v, int H) {
    int j;
    if (H == 0)
        for (j = 0; j < h->m; j++)
            if (eq(v, h->b[j].key))
                return h->b[j].ref.item;
    if (H != 0)
        for (j = 0; j < h->m; j++)
            if ((j + 1 == h->m) || less(v, h->b[j + 1].key))
                return searchR(h->b[j].ref.next, v, H - 1);
    return NULLitem;
}
Item STsearch(Key v) { return searchR(head, v, H); }
link split(link h) {
    int j;
    link t = NEW();
    for (j = 0; j < M / 2; j++)
        t->b[j] = h->b[M / 2 + j];
    h->m = M / 2;
    t->m = M / 2;
    return t;
}
link insertR(link h, Item item, int H) {
    int i, j;
    Key v = key(item);
    entry x;
    link t, u;
    x.key = v;
    x.ref.item = item;
    if (H == 0)
        for (j = 0; j < h->m; j++)
            if (less(v, h->b[j].key))
                break;
    if (H != 0)
        for (j = 0; j < h->m; j++)
            if ((j + 1 == h->m) || less(v, h->b[j + 1].key)) {
                t = h->b[j++].ref.next;
                u = insertR(t, item, H - 1);
                if (u == NULL)
                    return NULL;
                x.key = u->b[0].key;
                x.ref.next = u;
                break;
            }
    for (i = (h->m)++; i > j; i--)
        h->b[i] = h->b[i - 1];
    h->b[j] = x;
    if (h->m < M)
        return NULL;
    else
        return split(h);
}
void STinsert(Item item) {
    link t, u = insertR(head, item, H);
    if (u == NULL)
        return;
    t = NEW();
    t->m = 2;
    t->b[0].key = head->b[0].key;
    t->b[0].ref.next = head;
    t->b[1].key = u->b[0].key;
    t->b[1].ref.next = u;
    head = t;
    H++;
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
        STinit();
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
    }
    return 0;
}
