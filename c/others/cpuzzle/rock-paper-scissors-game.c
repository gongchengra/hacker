#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    char gamer;   // 玩家出拳
    int computer; // 电脑出拳
    int result;   // 比赛结果
    // 使用菜单循环玩剪刀、石头、布游戏
    while (1) {
        printf(
            "这是一个剪刀、石头、布的对弈出拳游戏，下面给出它们的替代字符。\n");
        printf("A:剪刀\nB:石头\nC:布\nD:退出\n");
        printf("字符不分大小写。请选择对应字符：");
        scanf("%c%*c", &gamer);
        switch (gamer) {
        case 65: // A
        case 97: // a
            gamer = 4;
            break;
        case 66: // B
        case 98: // b
            gamer = 7;
            break;
        case 67: // C
        case 99: // c
            gamer = 10;
            break;
        case 68:  // D
        case 100: // d
            printf("结束游戏，再见!\n");
            return 0;
        default:
            printf("你选的是 %c, 选择错误,替你选择默认的石头。", gamer);
            gamer = 7;
            printf("按回车键看结果。\n");
            getchar();
/*            system("clear"); // 清屏*/
            break;
        }
        srand((unsigned)time(NULL)); // 随机数种子
        computer = rand() % 3; // 产生随机数并取余，得到电脑出拳
        result =
            (int)gamer + computer; // gamer为char类型，数学运算时要强制转换类型
        printf("电脑出了");
        switch (computer) {
        case 0:
            printf("剪刀\n");
            break;
        case 1:
            printf("石头\n");
            break;
        case 2:
            printf("布\n");
            break;
        }
        printf("你出了");
        switch (gamer) {
        case 4:
            printf("剪刀\n");
            break;
        case 7:
            printf("石头\n");
            break;
        case 10:
            printf("布\n");
            break;
        }
        if (result == 6 || result == 7 || result == 11)
            printf("你赢了!\n");
        else if (result == 5 || result == 9 || result == 10)
            printf("电脑赢了!\n");
        else
            printf("平手\n");
        printf("按回车键继续玩。\n");
/*        system("pause>nul&&cls"); // 暂停并清屏*/
    }
    return 0;
}
