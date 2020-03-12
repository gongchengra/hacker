#include "airfight.h"
int scr[22][N] = {0};
// 定义全局变量：界面、我机初始位置
// 界面宽度、敌机速度、敌机密度、得分、坠毁
int pl = 9, width = 24, speed = 3, density = 30, score = 0, death = 0;
int main() {
    int i = 0, j = 0;
    scr[21][pl] = 1;
    scr[0][5] = 3;
    set_menu();
    while (1) {
        switch (getch()) // 控制左右移动和进入菜单
        {
        case 'a':
        case 'A':
            if (pl > 0)
                scr[21][pl] = 0, scr[21][--pl] = 1;
            break;
        case 'd':
        case 'D':
            if (pl < width - 2)
                scr[21][pl] = 0, scr[21][++pl] = 1;
            break;
        case 'w':
        case 'W':
            scr[20][pl] = 2;
            break;
        case 27:
            set_game();
            break;
        case 's':
        case 'S':
            printf("再见!\n");
            return 0;
        }
        if (++j % density == 0) // 控制生产敌机的速度
        {
            j = 0;
            srand(time(NULL));
            scr[0][rand() % width] = 3;
        }
        if (++i % speed == 0) // 控制敌机移动速度，相对于子弹移动速度
            movepla(scr);
        movebul(scr);
        print(scr);
        if (i == 30000)
            i = 0; // 以免i越界
    }
}
