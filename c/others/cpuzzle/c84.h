#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// 多项式链表结点类型定义
typedef struct {
    float coef; // 系数
    int expn;   // 指数
} DataType;
typedef struct node {
    DataType data;
    struct node *next;
} ListNode, *LinkList;
// 5个函数原型声明
// 结点的查找定位函数
int LocateNode(LinkList, DataType);
// 有序链表结点的插入函数
LinkList InsertNode(LinkList, DataType);
// 多项式链表的建立函数
LinkList CreatPolyn(int);
// 多项式链表的输出函数
void printList(LinkList);
// 多项式链表的相加函数
LinkList AddPolyn(LinkList, LinkList);
extern int q; // 声明全局变量
