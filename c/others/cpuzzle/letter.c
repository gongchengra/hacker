#include "letter.h" // 包含自定义的头文件
int count;          // 声明全局记录计数变量
int main() {
    ADDR *top;
    ASK(top);
    top->next = NULL;
    count = 0;
    handle_menu(top);
}
// 菜单处理函数
void handle_menu(ADDR *top) {
    for (;;) {
        switch (menu_select()) {
        case 1:
            top = input(top);
            break;
        case 2:
            display(top);
            break;
        case 3:
            top = del(top);
            break;
        case 4:
            printf("退出操作，再见！\n");
            exit(0);
        }
    }
}
// 菜单选择函数menu_selected
int menu_select() {
    char s[2];
    int cn = 0;
    printf("\n");
    printf("1. 输入记录\n");
    printf("2. 显示记录\n");
    printf("3. 删除记录\n");
    printf("4. 结束运行\n");
    printf("\n左边数字对应功能选择，请选1-4: ");
    for (;;) {
        gets(s);
        cn = atoi(s);
        if (cn < 1 || cn > 6)
            printf("\n输入错误，重选1-4：");
        else
            break;
    }
    return cn;
}
