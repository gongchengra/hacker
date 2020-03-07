#include <stdio.h>
int main() {
    int year, month, day, i, leap = 0;
    static int day_tab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    printf("输入格式示范：2003 1 8\n输入: ");
    scanf("%d%d%d", &year, &month, &day);
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 0; i < month; ++i)
        day += day_tab[leap][i];
    printf("%d\n", day);
}
