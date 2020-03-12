#include "letter.h" // 包含自定义的头文件
// 输入信息函数
ADDR *input(ADDR *top) {
    ADDR *old;
    ADDR *star;
    ASK(star);
    old = top;
    while (old->next != NULL) {
        old = old->next;
    }
    printf("输入数据，输入0时结束。\n");
    --count;
    do {
        ++count;
        printf("姓名:");
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
