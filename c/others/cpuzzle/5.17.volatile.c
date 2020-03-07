#include <stdio.h>
void delayWorks(void) {
    int i;
    volatile int result;
    volatile int num1 = 12;
    volatile int num2 = 35;
    for (i = 0; i < 1863; ++i) {
        result = num1 * num2;
    }
}
void delayDoesnotWork(void) {
    int i;
    int result;
    for (i = 0; i < 1863; ++i)
        result = 12 * 35;
}
int main() {
    for (int i = 0; i < 100000; i++) {
        delayWorks();
        /*    delayDoesnotWork();*/
    }
    return 0;
}
