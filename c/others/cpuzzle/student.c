#include "student.h"
/**************************
 * 初始化
 **************************/
int numStus = 0;         // 记录的学生数
StuInfo *records = NULL; // 记录学生信息的数组
char savedTag = 0; // 信息是否已保存的标志，1为未保存，0为已保存
int arraySize;     // 数组大小
char *subject[] = {"语文", "数学", "英语", "物理", "化学"};
/**************************
 * 主函数
 **************************/
int main() {
    // 初始化数组
    records = (StuInfo *)malloc(sizeof(StuInfo) * INITIAL_SIZE);
    if (records == NULL) {
        printf("memory fail!");
        exit(-1);
    }
    arraySize = INITIAL_SIZE;
    printf("\n");
    printf("\t****************************\n");
    printf("\t* 这是一个 *\n");
    printf("\t* 学生成绩管理程序 *\n");
    printf("\t* 可以对学生成绩进行管理 *\n");
    printf("\t* 欢迎使用管理程序 *\n");
    printf("\t****************************\n");
    printf("\n");
    handle_menu();
}
/**************************
 * 菜单处理函数
 **************************/
void handle_menu(void) {
    for (;;) {
        switch (menu_select()) {
        case 1:
            addRecord();
            break;
        case 2:
            modifyRecord();
            break;
        case 3:
            display();
            break;
        case 4:
            queryInfo();
            break;
        case 5:
            removeRecord();
            break;
        case 6:
/*            sortInfo();*/
            break;
        case 7:
            saveRecords();
            break;
        case 8:
            loadRecords();
            break;
        case 9:
            quit();
        }
    }
}
/****************************
 * 菜单选择函数menu_selected
 ****************************/
int menu_select() {
    char s[2];
    int cn = 0;
    printf("\n");
    printf("\t1. 增加学生信息\n");
    printf("\t2. 修改学生信息\n");
    printf("\t3. 显示学生信息\n");
    printf("\t4. 查询学生信息\n");
    printf("\t5. 删除学生信息\n");
    printf("\t6. 对学生信息进行排序\n");
    printf("\t7. 保存学生信息至记录文件\n");
    printf("\t8. 从记录文件读取学生信息\n");
    printf("\t9. 结束运行\n");
    printf("\n\t左边数字对应功能选择，请选1-8: ");
    for (;;) {
        gets(s);
        cn = atoi(s);
        // 处理键入的非数字键，过滤出数字0
        if (cn == 0 && (strcmp(s, "0") != 0))
            cn = 11;
        if (cn < 0 || cn > 9)
            printf("\n\t输入错误，重选0-9：");
        else
            break;
    }
    return cn;
}
/**********************************
 * 结束运行，退出
 * 参数 void
 **********************************/
void quit(void) {
    char str[5];
    if (savedTag == 1) {
        printf("是否保存原来的记录？(Y/n)");
        gets(str);
        if (str[0] != 'n' && str[0] != 'N')
            saveRecords();
    }
    free(records);
    exit(0);
}
