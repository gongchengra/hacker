#include "record.h"
ADDR *add_record(ADDR *top) {
    ADDR *old;
    ADDR *star;
    FILE *fp;
    if ((fp = fopen("sname", "rb")) == NULL) // 判别是否已有文件
    {
        printf("还没有建立文件, 退出时别忘记存文件。\n");
    } else {
        fclose(fp);
        if (count == 0) {
            printf("请稍候，取已有文件...\n");
            top = load(top);
        }
    }
    ASK(star);
    old = top;
    while (old->next != NULL) {
        old = old->next;
    }
    printf("输入数据，输入0时结束。\n");
    --count;
    do {
        ++count;
        printf("代号:");
        gets(star->name);
        if (strcmp(star->name, "0") == 0)
            break;
        printf("电话:");
        gets(star->tel);
        if (count == 0)
            top = star;
        old->next = star;
        old = star;
        ASK(star);
    } while (star->name[0] != '0');
    old->next = NULL;
    free(star);
    return (top);
}
// 显示内存动态记录数据
void display(const ADDR *top) {
    const ADDR *p;
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
