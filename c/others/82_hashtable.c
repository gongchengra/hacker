/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 82_hashtable.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-20
* Last Modified : 2020-04-20 21:47:17+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXLN 256
#define HASHSIZE 1000
typedef struct node *link;
struct node {
    link next;
    char *key;
    char *val;
};
link hashtab[HASHSIZE];
unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 37 * hashval;
    }
    return hashval % HASHSIZE;
}
link lookup(char *s) {
    link np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->key) == 0) {
            return np;
        }
    }
    return NULL;
}
link set(char *key, char *val) {
    link np;
    unsigned hashval;
    if ((np = lookup(key)) == NULL) {
        np = (link)malloc(sizeof(struct node));
        if (np == NULL || (np->key = strdup(key)) == NULL) {
            return NULL;
        }
        hashval = hash(key);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free((void *)np->val);
    }
    if ((np->val = strdup(val)) == NULL) {
        return NULL;
    }
    return np;
}
void del(char *key) {
    unsigned hashval = hash(key);
    link prev = hashtab[hashval], to_free = NULL;
    if (prev == NULL) {
        return;
    }
    if (strcmp(prev->key, key) == 0) {
        hashtab[hashval] = prev->next;
        to_free = prev;
    } else {
        for (to_free = prev->next; to_free;
             prev = to_free, to_free = to_free->next) {
            if (strcmp(to_free->key, key) == 0) {
                prev->next = to_free->next;
                break;
            }
        }
    }
    if (to_free) {
        free(to_free->key);
        free(to_free->val);
        free(to_free);
    }
}
void printhash(link np) {
    if (np == NULL) {
        return;
    }
    for (link head = np; head; head = head->next) {
        printf("key: %s, val: %s\n", head->key, head->val);
    }
}
static char *rand_string(char *str, size_t size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int)(sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}
int main(int argc, char **argv) {
    link entry;
    char key[MAXLN], val[MAXLN], menu;
    short flag = 1;
    srand(time(NULL));
    for (int i = 0; i < HASHSIZE * 2; i++) {
        entry = set(rand_string(key, (10 + rand() % 10)),
                    rand_string(val, (10 + rand() % 10)));
    }
    for (; flag == 1;) {
        printf("Input menu input('i' or 'I'), del('d' or 'D'),"
               " search ('s' or 'S'), list ('l' or 'L') or quit('q' or 'Q'): ");
        while ((menu = getchar()) == '\n')
            ;
        switch (menu) {
        case 'i':
        case 'I':
            for (;;) {
                printf("Input key to hashtab: ");
                scanf("%s", key);
                if (strcmp(key, "quit") == 0) {
                    break;
                }
                printf("Input value to hashtab: ");
                scanf("%s", val);
                entry = set(key, val);
            }
            break;
        case 'd':
        case 'D':
            for (;;) {
                printf("Input the key you want to del: ");
                scanf("%s", key);
                if (strcmp(key, "quit") == 0) {
                    break;
                }
                del(key);
            }
            break;
        case 's':
        case 'S':
            for (;;) {
                printf("Input the key you want to find: ");
                scanf("%s", key);
                if (strcmp(key, "quit") == 0) {
                    break;
                }
                link s = lookup(key);
                if (s == NULL) {
                    continue;
                }
                for (link head = s; head; head = head->next) {
                    if (strcmp(head->key, key) == 0) {
                        printf("key: %s, val: %s\n", head->key, head->val);
                    }
                }
            }
            break;
        case 'l':
        case 'L':
            for (int i = 0; i < HASHSIZE; i++) {
                if (hashtab[i] != NULL) {
                    printf("%d\n", i);
                    printhash(hashtab[i]);
                }
            }
            break;
        case 'q':
        case 'Q':
            flag = 0;
            break;
        }
    }
    return 0;
}
