#ifndef _H_RECORD_H_A // 条件编译
#define _H_RECORD_H_A
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
extern int count;
typedef struct address {
    char name[8];
    char tel[20];
    struct address *next;
} ADDR;
// 声明函数原型
ADDR *add_record(ADDR *);
// void display(ADDR *);
void display(const ADDR *top);
// void save(ADDR *);
void save(const ADDR *top);
ADDR *load(ADDR *);
int menu_select(void);
void handle_menu(ADDR *);
ADDR *delete_record(ADDR *);
#endif
