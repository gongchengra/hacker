/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 90.sortnumber.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2023-08-03
* Last Modified : 2023-08-03 20:22:18+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define N (100000063/64)

struct bitset {
    uint64_t bits[N];
};

static struct bitset *
number_new() {
    struct bitset *S = (struct bitset *)malloc(sizeof(*S));
    memset(S, 0, sizeof(*S));
    return S;
}

static void
number_delete(struct bitset *S) {
    if (S)
        free(S);
}

static void
number_insert(struct bitset *S, uint32_t v) {
    assert(v < N * 64);
    S->bits[v / 64] |= 1 << (v % 64);
}

static void
number_writefile(const char * filename, struct bitset *S) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL)
        return;
    int i,j;
    for (i=0;i<N;i++) {
            uint64_t v = S->bits[i];
            for (j = 0; j < 64 && v != 0; j++) {
                        if (v & 1) {
                                        fprintf(f, "%d\n", i * 64 + j);
                                    }
                        v >>= 1;
                    }
        }
    fclose(f);
}

static void
number_readfile(const char * filename, struct bitset *S) {
    FILE *f = fopen(filename, "rb");
    char line[1024];
    for (;;) {
            char * s = fgets(line, sizeof(line), f);
            if (s == NULL)
                return;
            uint32_t v;
            if (sscanf(s, "%d", &v) == 1) {
                        number_insert(S, v);
                    }
        }
}

#ifdef TEST_MAIN

int
main() {
    struct bitset *S = number_new();
    printf("READ\n");
    number_readfile("number.txt", S);
    printf("WRITE\n");
    number_writefile("sorted.txt", S);
    number_delete(S);
    return 0;
}

#endif

#ifdef GEN_TEST_NUMBER

#include <stdlib.h>

#define NL 80000000

int
main() {
    FILE *f = fopen("number.txt", "w");
    if (f == NULL)
        return 1;
    int i;
    for (i=0;i<NL;i++) {
            uint16_t a = rand() % 10000;
            uint16_t b = rand() % 10000;
            uint32_t n = (a * 10000 + b ) % 89999999 + 10000000;
            fprintf(f, "%d\n", n);
        }

    fclose(f);
    return 0;
}

#endif
