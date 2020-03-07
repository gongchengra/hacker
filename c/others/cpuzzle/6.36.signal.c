#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void sighandler(int);
int main() {
    // prototype void (*signal(int sig, void (*func)(int)))(int)
    signal(SIGINT, sighandler);
    while (1) {
        printf("开始休眠一秒钟...\n");
        sleep(1);
    }
    return (0);
}
void sighandler(int signum) {
    printf("捕获信号 %d，跳出...\n", signum);
    exit(1);
}
