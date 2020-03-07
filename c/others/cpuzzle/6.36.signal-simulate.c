#include <stdio.h>
int n = 8;
// 信号处理函数
void sigfunc() { printf("接收到信号：%d\n", n); }
// 模拟处理函数
void sigproc(int n, void (*p)()) {
    printf("信号：%d\n", n);
    p();
}
// 主函数
int main() {
    printf("主函数开始运行...\n");
    // 假设出现异常，执行模拟处理函数sigproc
    sigproc(n, sigfunc);
    printf("主函数继续运行...\n");
    return 0;
}
