// 完整的源程序
#include <stdio.h>
#include <stdlib.h>
// 定义数据结构和函数原型声明
typedef struct node {
    int data;
    struct node *next;
} ListNode;
typedef ListNode *LinkList;
LinkList InitRing(int n, LinkList R);
LinkList DeleteDeath(int n, int k, LinkList R);
void OutRing(int n, LinkList R);
// 主程序
int main() {
    LinkList R = NULL;
    int n, k;
    printf("总人数n=");
    scanf("%d", &n);
    printf("报数上限k=");
    scanf("%d", &k);
    R = InitRing(n, R);
    printf("出局名单如下:\n");
    R = DeleteDeath(n, k, R);
    printf("生还者名单如下:\n");
    OutRing(n, R);
}
// 具体函数设计
/*****************************
 * 建立循环单链表函数 *
 *****************************/
// 数字域的值从1开始。因为尾结点是整数n，所以可以直接赋值。
LinkList InitRing(int n, LinkList R) {
    ListNode *p, *q;
    int i;
    R = q = (ListNode *)malloc(sizeof(ListNode));
    if (R == NULL) {
        printf("内存分配错误");
        exit(1);
    }
    for (i = 1; i < n; i++) {
        p = (ListNode *)malloc(sizeof(ListNode));
        if (p == NULL) {
            printf("内存分配错误");
            exit(1);
        }
        q->data = i;
        q->next = p;
        q = p;
    }
    p->data = n; // 尾结点赋值
    p->next = R; // 链表首尾相接
    R = p;       // R指向循环链表尾结点
    return R;
}
/*****************************
 * 生者与死者选择函数 *
 *****************************/
LinkList DeleteDeath(int n, int k, LinkList R) {
    int i, j;
    ListNode *p, *q;
    p = R;
    for (i = 1; i <= n / 2; i++) // 循环次数n/2
    {
        for (j = 1; j <= k - 1; j++) // 沿链前进k-1步
            p = p->next;
        q = p->next;            // q为被删除结点
        p->next = q->next;      // 删除q指向的结点
        printf("%4d", q->data); // 输出一个抛入大海者
        if (i % 5 == 0)
            printf("\n");
        free(q); // 释放空间
    }
    printf("\n");
    R = p;
    return R;
}
/*****************************
 * 输出所有生者函数 *
 *****************************/
void OutRing(int n, LinkList R) {
    int i;
    ListNode *p;
    p = R;
    if (n % 2 == 0)
        n = n / 2; // 偶数则为一半
    else
        n = n / 2 + 1; // 奇数则生还者比死者多1个
    for (i = 1; i <= n; i++, p = p->next) {
        printf("%4d", p->data);
        if (i % 5 == 0)
            printf("\n");
    }
    printf("\n");
}
