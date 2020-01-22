#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// item
typedef char *Item;
#define less(A, B) (strcmp(key(A), key(B)) < 0)
#define eq(A, B) (!less(A, B) && !less(B, A))
typedef char *Key;
Key key(Item item) { return (item); }
#define NULLitem NULL
#define maxKey 1000
#define null(A) (eq(key(A), key(NULLitem)))
#define maxN 100000
#define maxQ 100
static char text[maxN];
// st
static Item *st;
static int M = maxKey;
static int lenN = 0;
void STinit(int M) {
    int i;
    st = malloc((M + 1) * sizeof(Item));
    for (i = 0; i <= M; i++)
        st[i] = NULLitem;
}
int STcount() {
    int i, N = 0;
    for (i = 0; i < M; i++)
        if (st[i] != NULLitem)
            N++;
    return N;
}
void STinsert(Item t) {
    st[t-text] = t;
}
Item STsearch(Key v) {
    for(int i = 0; i<= lenN;i++){
        if (strncmp(st[i], v, strlen(v)) == 0)
            return st[i];
    }
    return NULLitem;
}
// main
int main(int argc, char *argv[]) {
    int i, t, N = 0;
    char query[maxQ];
    char *v;
    FILE *corpus = fopen(*++argv, "r");
    while ((t = getc(corpus)) != EOF) {
        if (N < maxN - 1)
            text[N++] = t;
        else
            break;
    }
    text[N] = '\0';
    lenN = N;
    STinit(maxN);
    for (i = 0; i < N; i++)
        STinsert(&text[i]);
    while (scanf("%s", query) == 1) {
        if (!null(v = STsearch(query)))
            printf("%11ld %s\n", v - text, query);
        else
            printf("(not found) %s\n", query);
    }
    return 0;
}
