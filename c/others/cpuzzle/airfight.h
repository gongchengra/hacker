// airfight.h
#ifndef HH_AIR_HH
#define HH_AIR_HH
#include <stdio.h>
//#include <conio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#define N 35
void print(int [][N]); // 输出函数
void movebul(int [][N]); // 子弹移动函数
void movepla(int [][N]); // 敌机移动函数
void set_game(void); // 设置函数
void set_menu(void); // 使用说明函数
extern int scr[22][N];
// 声明全局变量：界面、我机初始位置
// 界面宽度、敌机速度、敌机密度、得分、坠毁
extern int pl,width,speed,density,score,death;
#endif // HH_AIR_HH
