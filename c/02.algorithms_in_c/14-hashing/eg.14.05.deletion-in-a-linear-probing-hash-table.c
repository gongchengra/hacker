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
#define null(A) (key(st[A]) == key(NULLitem))
static int N, M;
static Item *st;
int hash(char *v, int M) {
    int h, a = 31415, b = 27183;
    for (h = 0; *v != '\0'; v++, a = a * b % (M - 1))
        h = (a * h + *v) % M;
    return h;
}
int eq(char *a, char *b) { return (strcmp(a, b) == 0); }
void STinit(int max) {
    int i;
    N = 0;
    M = 2 * max;
    st = malloc(M * sizeof(Item));
    for (i = 0; i < M; i++)
        st[i] = NULLitem;
}
int STcount(void) { return N; }
void STinsert(Item item) {
    Key v = key(item);
    int i = hash(v, M);
    while (!null(i))
        i = (i + 1) % M;
    st[i] = item;
    N++;
}
Item STsearch(Key v) {
    int i = hash(v, M);
    while (!null(i))
        if (eq(v, key(st[i])))
            return st[i];
        else
            i = (i + 1) % M;
    return NULLitem;
}
void STdelete(Item item) {
    int j, i = hash(key(item), M);
    Item v;

    while (!null(i))
        if (eq(key(item), key(st[i])))
            break;
        else
            i = (i + 1) % M;
    if (null(i))
        return;
    st[i] = NULLitem;
    N--;
    for (j = i + 1; !null(j); j = (j + 1) % M, N--) {
        v = st[j];
        st[j] = NULLitem;
        STinsert(v);
    }
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
