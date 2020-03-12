#include "letter.h" // 包含自定义的头文件
// 显示内存动态记录数据
void display(ADDR *top) {
    ADDR *p;
    if (count == 0) {
        printf("\n现在没有记录!\n");
        return;
    }
    p = top;
    printf("\n现在共有如下 %d 条记录：\n", count);
    printf("代号\t电话\n");
    while (p != NULL) {
        printf("%s\t%s\n", p->name, p->tel);
        p = p->next;
    }
}
