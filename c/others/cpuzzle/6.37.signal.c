#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
static jmp_buf jmpbuf;
void Handler(int sig) {
    printf("捕获到%d信号\n", sig);
    longjmp(jmpbuf, 1);
}
int main() {
    printf("主程序启动...\n");
    signal(SIGFPE, Handler);
    if (setjmp(jmpbuf) == 0) {
        int a = 0;
        a = 1 / a;
    } else {
        printf("已完成信号捕获，并跳转离开异常语句\n");
    }
    printf("主程序继续运行...\n");
    return 0;
}
