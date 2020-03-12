#include "airfight.h"
void print(int a[][N]) {
    int i, j;
    system("clear");
    for (i = 0; i < 22; i++) {
        a[i][width - 1] = 4;
        for (j = 0; j < width; j++) {
            if (a[i][j] == 0)
                printf(" ");
            if (a[i][j] == 1)
                printf("\5"); // 输出我机的符号
            if (a[i][j] == 2)
                printf("."); // 子弹
            if (a[i][j] == 3)
                printf("\3"); // 输出敌机符号
            if (a[i][j] == 4)
                printf("|");
            if (i == 0 && j == width - 1)
                printf(" 得分：%d", score); // 右上角显示得分
            if (i == 1 && j == width - 1)
                printf(" 坠毁：%d", death);
            if (i == 2 && j == width - 1)
                printf(" 设置：Esc");
        }
        printf("\n");
    }
}
void movebul(int a[][N]) {
    int i, j;
    for (i = 0; i < 22; i++)
        for (j = 0; j < width; j++) {
            if (i == 0 && a[i][j] == 2)
                a[i][j] = 0;
            if (a[i][j] == 2) {
                if (a[i - 1][j] == 3)
                    score += 10, printf("\7");
                a[i][j] = 0, a[i - 1][j] = 2;
            }
        }
}
void movepla(int a[][N]) {
    int i, j;
    for (i = 21; i >= 0; i--) // 从最后一行往上是为了避免把敌机直接冲出数组
        for (j = 0; j < width; j++) {
            if (i == 21 && a[i][j] == 3)
                a[i][j] = 0; // 底行赋值为0以免越界
            if (a[i][j] == 3)
                a[i][j] = 0, a[i + 1][j] = 3;
        }
    if (a[20][pl] == 3 && a[21][pl] == 1)
        death++;
}
void set_game(void) {
    int sw = 0, i, j;
    system("clear");
    do {
        sw = 0;
        printf("\n 游戏界面的大小：1.大2.小>> ");
        switch (getchar()) {
        case '1':
            width = 34;
            break;
        case '2':
            width = 24;
            break;
        default:
            printf("\n 错误，请重新选择...\n");
            sw = 1;
        }
    } while (sw);
    do {
        sw = 0;
        printf("\n 请选择敌机密度：1.大2.中3.小>> ");
        switch (getchar()) {
        case '0':
            density = 10;
            break;
        case '1':
            density = 20;
            break;
        case '2':
            density = 30;
            break;
        case '3':
            density = 40;
            break;
        default:
            printf("\n 错误，请重新选择...\n");
            sw = 1;
        }
    } while (sw);
    do {
        sw = 0;
        printf("\n 敌机的飞行速度：1.快2.中3.慢>> ");
        switch (getchar()) {
        case '1':
            speed = 2;
            break;
        case '2':
            speed = 3;
            break;
        case '3':
            speed = 4;
            break;
        default:
            printf("\n 错误，请重新选择...\n");
            sw = 1;
        }
    } while (sw);
    for (i = 0; i < 22; i++)
        for (j = 0; j < 45; j++)
            scr[i][j] = 0;
    scr[21][pl = 9] = 1;
    printf("\n 按任意键保存...");
    getch();
}
void set_menu(void) {
    printf("按键说明：\n");
    printf("按A或D来控制我机左右飞行\n");
    printf("W 发射子弹\n按Esc设置参数\n");
    printf("任意键开始游戏，游戏中按S键结束游戏\n");
    if (getchar() == 27)
        set_game();
}
