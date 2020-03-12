#include "c84.h"
// 主函数
int main() {
    LinkList La, Lb, Lc;
    int n; // 注意这里是局部变量，不要与全局变量混淆
    printf("输入第一个多项式的项数： ");
    scanf("%d", &n);
    printf("输入第一个多项式的每一项的系数，指数：\n");
    La = CreatPolyn(n);
    printf("第一个多项式为：");
    printList(La);
    printf("输入第二个多项式的项数： ");
    scanf("%d", &n);
    printf("输入第二个多项式的每一项的系数，指数：\n");
    Lb = CreatPolyn(n);
    printf("第二个多项式为：");
    printList(Lb);
    Lc = AddPolyn(La, Lb);
    printf("\n相加后的和多项式为： ");
    printList(Lc);
    return 0;
}
