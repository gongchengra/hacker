/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_06_06_mem_simulate_define.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-20
* Last Modified : 2020-04-20 16:51:32+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTOK 1000
#define MAXLN 2000
#define HASHSIZE 101
#define MAXWORD 100
typedef struct node *link;
struct node {
    link next;
    char *name;
    char *defn;
};
link hashtab[HASHSIZE];
unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 37 * hashval;
    }
    return hashval % HASHSIZE;
}
void undef(char *name) {
    unsigned hashval = hash(name);
    link prev = hashtab[hashval], to_free = NULL;
    if (prev == NULL) {
        return;
    }
    if (strcmp(prev->name, name) == 0) {
        hashtab[hashval] = prev->next;
        to_free = prev;
    } else {
        for (to_free = prev->next; to_free;
             prev = to_free, to_free = to_free->next) {
            if (strcmp(to_free->name, name) == 0) {
                prev->next = to_free->next;
                break;
            }
        }
    }
    if (to_free) {
        free(to_free->name);
        free(to_free->defn);
        free(to_free);
    }
}
link lookup(char *s) {
    link np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }
    return NULL;
}
link install(char *name, char *defn) {
    link np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {
        np = (link)malloc(sizeof(struct node));
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free((void *)np->defn);
    }
    if ((np->defn = strdup(defn)) == NULL) {
        return NULL;
    }
    return np;
}
int getnexttoken(char *word, int lim) {
    int c;
    char *w = word;
    short in_comment = 0;
    *w = '\0';
    if ((c = getchar()) != EOF) {
        *w++ = c;
    } else {
        return EOF;
    }
    if (isalpha(c) || c == '_' || c == '#') {
        for (; --lim > 0; w++) {
            if (!isalnum((unsigned char)(*w = getchar())) && *w != '_') {
                ungetc(*w, stdin);
                break;
            }
        }
    } else if (c == '\'' || c == '"') {
        for (; --lim > 0; w++) {
            if ((*w = getchar()) == '\\') {
                *++w = getchar();
            } else if (*w == c) {
                w++;
                break;
            }
        }
    } else if (c == '/') {
        if ((*w = getchar()) == '*') {
            in_comment = 1;
            while (in_comment) {
                while (getchar() != '*')
                    ;
                if ((c = getchar()) == '/') {
                    in_comment = 0;
                } else {
                    ungetc(c, stdin);
                }
            }
            return getnexttoken(word, lim);
        } else {
            ungetc(*w, stdin);
        }
    }
    *w = '\0';
    return word[0];
}
void get_rest_of_line(char *s, int lim) {
    char c;
    while ((c = getchar()) != '\n' && isspace(c))
        ;
    while (--lim > 0 && c != '\n' && c != '\r' && c != EOF) {
        *s++ = c;
        c = getchar();
    }
    *s = '\0';
    ungetc(c, stdin);
}
void process_define(void) {
    char c, token[MAXTOK], name[MAXTOK], defn[MAXTOK];
    while (c != '\n' && isspace(c = getnexttoken(token, MAXTOK)))
        ;
    strcpy(name, token);
    get_rest_of_line(defn, MAXLN);
    printf("token=%s, defn=%s\n", name, defn);
    install(name, defn);
}
void process_undef(void) {
    char c, token[MAXTOK];
    while (c != '\n' && isspace(c = getnexttoken(token, MAXTOK)))
        ;
    undef(token);
}
int main(int argc, char **argv) {
    char token[MAXTOK], c;
    link entry;
    while ((c = getnexttoken(token, MAXTOK)) != EOF) {
        switch (c) {
        case '#':
            if (!strcmp(token, "#define")) {
                process_define();
            } else if (!strcmp(token, "#undef")) {
                process_undef();
            } else {
                printf("%s", token);
            }
            break;
        default:
            if (!isalnum(c) && c != '_') {
                printf("%s", token);
            } else {
                if ((entry = lookup(token))) {
                    printf("%s", entry->defn);
                } else {
                    printf("%s", token);
                }
            }
        }
    }
    return 0;
}
