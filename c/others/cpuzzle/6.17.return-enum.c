#include <stdio.h>
enum weekday get_weekday(int, int); // 返回枚举的函数原型
void print_today(enum weekday);     // 输出星期几的函数原型
enum weekday {
    monday = 1,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
};
int main() {
    int month, day;
    enum weekday today;
    printf("Input month and day:");
    scanf("%d%d", &month, &day);
    today = get_weekday(month, day);
    print_today(today);
}
enum weekday get_weekday(int month, int day) {
    int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0, alldays = 0, origin_day = 3;
    for (i = 1; i < month; i++)
        alldays += m[i - 1];
    alldays += day - 1;
    alldays = ((alldays + origin_day) % 7);
    if (alldays == 0)
        return 7;
    return alldays;
}
void print_today(enum weekday today) {
    switch (today) {
    case 1:
        printf("today is %s\n", "monday");
        break;
    case 2:
        printf("today is %s\n", "tuesday");
        break;
    case 3:
        printf("today is %s\n", "wednesday");
        break;
    case 4:
        printf("today is %s\n", "thursday");
        break;
    case 5:
        printf("today is %s\n", "friday");
        break;
    case 6:
        printf("today is %s\n", "saturday");
        break;
    case 7:
        printf("today is %s\n", "sunday");
        break;
    }
}
