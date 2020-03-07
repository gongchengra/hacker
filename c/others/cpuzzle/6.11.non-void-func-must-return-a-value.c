#include <stdio.h>
#include <string.h>
int st(char[]);
// or
/*void st(char s[]) { strcpy(s, "How are you?"); }*/
int main() {
    char s[] = "Good Afternoon!";
    printf("%s\n", s);
    st(s);
    printf("%s\n", s);
    return 0;
}
int st(char s[]) {
    strcpy(s, "How are you?"); // 改变字符数组内容
    return 0;
}

