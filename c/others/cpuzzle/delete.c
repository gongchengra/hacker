#include "letter.h" // 包含自定义的头文件
ADDR *del(ADDR *top) {
    char choose[5], input[30];
    int cn = 0;
    ADDR *old, *star;
    if (count == 0) {
        printf("记录已经为空表，退出删除操作！");
        return top;
    }
    printf("1. 通过代号\n");
    printf("2. 通过号码\n");
    gets(choose);
    while (1) {
        cn = atoi(choose);
        if (cn != 1 && cn != 2) {
            printf("输入错误，重选1-2：");
            gets(choose);
        } else
            break;
    }
    switch (cn) {
    case 1:
        printf("请输入代号：");
        break;
    case 2:
        printf("请输入号码：");
    }
    gets(input);
    old = star = top;
    while (star != NULL) {
        if ((cn == 1 && strcmp(input, star->name) == 0) ||
            (cn == 2 && strcmp(input, star->tel) == 0)) {
            if (star == top)
                top = star->next;
            else
                old->next = star->next;
            free(star);
            --count;             // 调整计数器
            printf("delete..."); // 给出删除成功的信息
            if (count == 0) {
                ASK(top);
                ASK(star);
                top->next = NULL;
            }
            return top;
        } else {
            old = star;
            star = star->next;
        }
    }
    printf("没有找到相应的记录。");
    return top;
}
