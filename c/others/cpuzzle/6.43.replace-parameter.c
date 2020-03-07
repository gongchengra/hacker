#include <stdio.h> // 预编译命令
#include <string.h>
void Find(char lake[][50]);
int main() {
    int i;
    char lake[5][50]; // 字符数组用来存放名次
    // 传输参数求解
    Find(lake);
    // 按照从大到小的顺序输出这4个湖
    for (i = 1; i <= 4; i++)
        printf("%d %s ", i, lake[i]);
    printf("\n");
}
void Find(char lake[5][50]) {
    int As, Bs, Cs, Ds;                           // 定义每个人说的话
    int Dongting, Hongze, Poyang, Tai;            // 定义4个湖
    for (Dongting = 1; Dongting <= 4; Dongting++) // 循环控制变量为Dongting
        for (Hongze = 1; Hongze <= 4; Hongze++) {
            // 循环控制变量为Hongze
            if (Hongze == Dongting) // 不让两个变量相同
                continue;
            for (Poyang = 1; Poyang <= 4; Poyang++) {
                if (Poyang == Hongze || Poyang == Dongting) // 不让两个变量相同
                    continue;
                Tai = 10 - Dongting - Hongze - Poyang; // 计算变量Tai
                As = (Dongting == 1) + (Hongze == 4) + (Poyang == 3);
                // A说的话
                Bs = (Hongze == 1) + (Dongting == 4) + (Poyang == 2) +
                     (Tai == 3);
                // B说的话
                Cs = (Hongze == 4) + (Dongting == 3);
                // C说的话
                Ds = (Poyang == 1) + (Tai == 4) + (Hongze == 2) +
                     (Dongting == 3);
                // D说的话
                if (As == 1 && Bs == 1 && Cs == 1 &&
                    Ds == 1) { // 每个人说对一句
                    strcpy(lake[Dongting], "洞庭湖");
                    strcpy(lake[Hongze], "洪泽湖");
                    strcpy(lake[Poyang], "鄱阳湖");
                    strcpy(lake[Tai], "太湖");
                } // endif
            }     // End Poyang
        }         // End Hongze
}
