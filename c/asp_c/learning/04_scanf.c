#include <stdio.h>

int main(void)
{
    int age;         //年龄
    char name[20];    //姓名

    printf("请输入你的年龄：");
    scanf("%d", &age);      //&age表示变量age的地址

    printf("请输入你的姓名：");
    scanf("%s", name);      //name单独使用就表示变量name的地址

    printf("\n姓名=%s\t年龄=%d\n",name,age);

    return 0;
}
