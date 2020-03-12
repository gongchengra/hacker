#include "c84.h"
int q; // 在使用全局变量q的文件里予以声明
// 结点的查找定位
int LocateNode(LinkList L, DataType e) // ,int &q
{
    ListNode *p = L->next;
    q = 0; // 为全局变量赋初值，用来记录结点位置序号
    while (p && e.expn < p->data.expn) {
        p = p->next;
        q++;
    }
    if (p == NULL || e.expn != p->data.expn)
        return 0;
    else
        return 1;
}
// 有序链表结点的插入
LinkList InsertNode(LinkList L, DataType e) {
    ListNode *s, *p;
    int i = 0;
    p = L;
    while (p->next && i < q) {
        p = p->next;
        i++;
    }
    s = (ListNode *)malloc(sizeof(ListNode));
    s->data.coef = e.coef;
    s->data.expn = e.expn;
    s->next = p->next;
    p->next = s;
    return L;
}
// 多项式链表的建立
LinkList CreatPolyn(int n) {
    LinkList pa;
    int i;
    DataType e;
    pa = (ListNode *)malloc(sizeof(ListNode)); // 生成链表头结点
    pa->next = NULL;
    for (i = 1; i <= n; i++) {
        scanf("%f %d", &e.coef, &e.expn);
        if (!LocateNode(pa, e))
            ; // 当前链表中不存在该指数项
        pa = InsertNode(pa, e);
    }
    return pa;
}
// 多项式链表的输出
void printList(LinkList L) {
    ListNode *p;
    p = L->next;
    while (p) {
        printf("%c %fx^%d", (p->data.coef > 0 ? '+' : ' '), p->data.coef,
               p->data.expn);
        p = p->next;
    }
    printf("\n");
}
// 多项式链表的相加
LinkList AddPolyn(LinkList La,
                  LinkList Lb) { // 两个有序链表La和Lb表示的多项式相加
    ListNode *pa, *pb, *pc, *s;
    LinkList Lc;
    float sum;
    pa = La->next;
    pb = Lb->next; // pa和pb分别指向两个链表的开始结点
    Lc = pc = La;  // 用La的头结点作为的Lc头结点
    while (pa && pb) {
        if (pa->data.expn > pb->data.expn) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else if (pa->data.expn < pb->data.expn) {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        } else {
            sum = pa->data.coef + pb->data.coef;
            if (fabs(sum) > 1e-6) { // 系数和不为零
                pa->data.coef = sum;
                pc->next = pa;
                pc = pa;
                pa = pa->next;
                s = pb;
                pb = pb->next;
                free(s);
            } else {
                s = pa;
                pa = pa->next;
                free(s);
                s = pb;
                pb = pb->next;
                free(s);
            }
        }
    }
    pc->next = pa ? pa : pb; // 插入链表剩余部分
    free(Lb);                // 释放Lb的头结点
    return Lc;
}
