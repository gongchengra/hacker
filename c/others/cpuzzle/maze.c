#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define m 8
// 定义表示位置的结构
struct position {
    int x, y;
};
// 数组的形式表示八个方向
int move[8][2] = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                  {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
int main() {
    int top;                     // 栈顶
    char stop = '0';             // 结束标志
    int i = 0, x = 0, y = 0, ok; // 记录和输出迷宫探路中的相关符号
    char maze[m + 2][m + 2];     // 设定m*m的方阵迷宫
    struct position stack[m * m + 1]; // 用栈来存储探路过程中的数据
    struct position p;
    while (1) {
        // 二维数组的第0行、第m+1行、第0列、第m+1列元素全部设置为"1"以表示
        // 迷宫的边界；第1行第1列元素和第m行第m列元素全部设置为"0"，表示
        // 迷宫的入口和出口；其余元素值用随机函数产生。
        srand(time(0));
        for (x = 1; x <= m; x++)
            for (y = 1; y <= m; y++)
                maze[x][y] = 48 + rand() % 2;
        maze[1][1] = '0';
        maze[m][m] = '0';
        for (x = 0; x <= m + 1; x++) {
            maze[x][0] = '1';
            maze[x][m + 1] = '1';
        }
        for (y = 0; y <= m + 1; y++) {
            maze[0][y] = '1';
            maze[m + 1][y] = '1';
        }
        // 输出迷宫
        printf("随机产生的迷宫结构如下:\n");
        for (x = 1; x < m + 1; x++) {
            for (y = 1; y < m + 1; y++)
                printf("%c ", maze[x][y]);
            printf("\n");
        }
        p.x = 1;
        p.y = 1;
        top = 1;
        stack[top] = p;
        maze[1][1] = '.';
        // 开始探路
        do {
            p = stack[top];
            ok = 0;
            i = 0;
            while ((ok == 0) && (i < 8)) {
                x = p.x + move[i][0];
                y = p.y + move[i][1];
                if (maze[x][y] == '0') {
                    p.x = x;
                    p.y = y;
                    stack[++top] = p;
                    maze[x][y] = '.';
                    ok = 1;
                }
                i++;
            }
            if (i == 8) {
                maze[p.x][p.y] = '*';
                top--;
            }
        } while ((top > 0) && ((p.x != m) || (p.y != m)));
        // 输出探路迷宫留下的踪迹
        printf("走迷宫的结果如下:\n");
        for (x = 1; x <= m; x++) {
            printf("\n");
            for (y = 1; y <= m; y++)
                printf("%c ", maze[x][y]);
        }
        printf("\n");
        // 输出探路结果
        if (top == 0)
            printf("结论:没有路径\n");
        else
            printf("结论:有路径\n");
        printf("输入1退出，其他键继续。请回答:");
        scanf("%c", &stop);
        if (stop == '1') {
            printf("再见!\n");
            return 0;
        }
    }
    return 0;
}
