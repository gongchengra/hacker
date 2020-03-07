#include <stdio.h>
int corn(int n) {
    int day = n, x = 1;
    while (day > 0) {
        x = (x + 1) * 2; // 递推
        day--;           // 递推计数器
    }
    return x;
}
int cf(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = (res + 1) * 2;
    }
    return res;
}
int cn(int n) { return n < 1 ? 1 : cn(n - 1) * 2 + 2; }
int main() {
    printf("玉米总数=%d\n", corn(9));
    printf("玉米总数=%d\n", cf(9));
    printf("玉米总数=%d\n", cn(9));
}
