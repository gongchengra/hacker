#include <stdio.h>
enum { OUT = 0, IN = 1 };
// 根据输入类型，字符返回1，其他为0
// get_input函数决定input状态0还是1
int get_input(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? IN : OUT;
    /*    if (c >= 'a' && c <= 'z')*/
    /*        return IN;*/
    /*    if (c >= 'A' && c <= 'Z')*/
    /*        return IN;*/
    /*    return OUT;*/
}
int main() {
    int words = 0, state = OUT, input = OUT;
    char c;
    while ((c = getchar()) != '#') {
        input = get_input(c); // 调用状态函数
        // 起始状态为0，无输入，保持state=0
        if ((state == OUT) && (input == OUT)) {
            state = OUT;
        }
        // state=0，input=1，置state=1并计数
        else if ((state == OUT) && (input == IN)) {
            state = IN;
            words++;
            // input=1，state从0变到1，单词起点
        }
        // state=1，等待input=0，置state=0，一个单词结束
        else if ((state == IN) && (input == OUT)) {
            state = OUT;
        }
        // state=1，input=1，置state=1，继续输入
        if ((state == IN) && (input == IN)) {
            state = IN;
        }
    }
    printf("word count:%d\n", words);
    return 0;
}
