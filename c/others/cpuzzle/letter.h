#ifndef _H_LETTER_H_A
#define _H_LETTER_H_A
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASK(p)                                                                 \
    do {                                                                       \
        p = (ADDR *)malloc(sizeof(ADDR));                                      \
        if (p == NULL) {                                                       \
            printf("memory fail!");                                            \
            exit(-1);                                                          \
        }                                                                      \
    } while (0)
#define LEN sizeof(ADDR)
extern int count; // 声明外部全局变量
typedef struct address {
    char name[8];
    char tel[20];
    struct address *next;
} ADDR;
ADDR *input(ADDR *);
void display(ADDR *);
int menu_select(void);
void handle_menu(ADDR *);
ADDR *del(ADDR *);
#endif
