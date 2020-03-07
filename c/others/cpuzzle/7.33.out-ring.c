#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct person {
    char name[10];
    struct person *next;
};
struct person *pBegin;
struct person *pCurrent;
struct person *pTmp;
int number;
int interval;
void Countx(int m);
void Dispx();
void Clsx();
void Find();
void Find1();
void Find2();
void SetRing(int n);
void Initial();
// 主函数
int main() {
    Initial();       // 取得参加游戏的人数number和间隔数interval
    SetRing(number); // 根据参加游戏的人数number建立循环链表
    Find();          // 求解
    return 0;
}
// 其他函数
/*****************************
 * SetRing函数 *
 * 功能：建立循环链表 *
 * 参数：n 循环链表长度 *
 *****************************/
void SetRing(int n) {
    int i;
    char s[10];
    pBegin = (struct person *)malloc(n * sizeof(struct person));
    pCurrent = pBegin;
    for (i = 1; i <= n; i++, pCurrent = pCurrent->next) {
        pCurrent->next = pBegin + i % n;
        printf("输入第%d个人的名字:", i);
        fgets(s, 10, stdin);
        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n')
            s[len - 1] = '\0';
        // s[strcspn(s, "\n")] = '\0';
        strcpy(pCurrent->name, s);
    }
    pCurrent = &pBegin[n - 1];
}
/*****************************
 * Countx函数 *
 * 功能：间隔计数 *
 * 参数n： 间隔长度 *
 *****************************/
void Countx(int m) {
    int i;
    for (i = 0; i < m; i++) {
        pTmp = pCurrent;
        pCurrent = pTmp->next;
    }
}
/******************************
 * Dispx函数 *
 * 功能：输出出局者信息 *
 ******************************/
void Dispx() { printf("%s ", pCurrent->name); }
/*****************************
 * Clsx函数 *
 * 功能：删除出局者结点 *
 *****************************/
void Clsx() {
    pTmp->next = pCurrent->next;
    pCurrent = pTmp;
}
/**********************************
 * Initial函数 *
 * 功能：接受游戏的人数和间隔数 *
 * number：参加游戏的人数 *
 * interval：间隔数 *
 **********************************/
void Initial() {
    printf("输入参加游戏的人数：");
    scanf("%d", &number);
    printf("输入间隔数：");
    scanf("%d", &interval);
    getchar();
}
/****************************
 * Find函数 *
 * 功能：求解 *
 ****************************/
void Find() {
    Find1();
    Find2();
}
// 根据参加游戏的人数number和间隔数interval求解
/****************************
 * Find1函数 *
 * 功能：求解并输出死者名单 *
 ****************************/
void Find1() {
    int i;
    printf("出局名单如下：\n");
    for (i = 1; i <= number / 2; i++) {
        Countx(interval); // 数间隔数interval
        Dispx();          // 输出出局者名字
        Clsx();           // 删除出局者结点
        if (i % 5 == 0)
            printf("\n");
    }
    printf("\n");
}
/****************************
 * Find2函数 *
 * 功能：输出生还者名单 *
 ****************************/
void Find2() {
    int i, num;
    num = number - number / 2; // 生还者数量
    printf("生还者名单如下：\n");
    for (i = 1; i <= num; i++) {
        pTmp = pCurrent;
        pCurrent = pTmp->next;
        Dispx(); // 输出生还者名单
        if (i % 5 == 0)
            printf("\n");
    }
    printf("\n");
}
