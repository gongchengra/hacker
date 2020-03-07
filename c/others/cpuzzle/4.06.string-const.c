#include <stdio.h>
int main() {
    int i = 0;
    char st[16], *p, *s;
    p = s = "we are here!";
    printf("1 p输出%s s输出%s\n", p, s);
/*    while ((st[i++] = *s++)); // 为字符数组赋值结束时，s指向\0*/
    while ((st[i] = *s++)) i++;
    printf("st输出%s\n", st);
    printf("2 p输出%s s输出%s\n", p, s); // s指向\0，输出为空，但p指向w
    s = s - 10;                        // s指向a
    printf("3 p输出%s s输出%s\n", p, s); // s输出are here!
}
