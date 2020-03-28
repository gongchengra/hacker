#include <stdio.h>
#include <string.h>
#include <time.h>
const char *names[] = {"Sunday",   "Monday", "Tuesday",  "Wednesday",
                       "Thursday", "Friday", "Saturday", NULL};
void print_today(int today) {
    switch (today) {
    case 1:
        printf("Today is %s\n", "monday");
        break;
    case 2:
        printf("Today is %s\n", "tuesday");
        break;
    case 3:
        printf("Today is %s\n", "wednesday");
        break;
    case 4:
        printf("Today is %s\n", "thursday");
        break;
    case 5:
        printf("Today is %s\n", "friday");
        break;
    case 6:
        printf("Today is %s\n", "saturday");
        break;
    case 7:
        printf("Today is %s\n", "sunday");
        break;
    }
}
int get_weekday(char *str) {
    struct tm tm;
    memset((void *)&tm, 0, sizeof(tm));
    /*    if (strptime(str, "%d-%m-%Y", &tm) != NULL) {*/
    if (strptime(str, "%Y-%m-%d", &tm) != NULL) {
        time_t t = mktime(&tm);
        if (t >= 0) {
            return localtime(&t)->tm_wday; // Sunday=0, Monday=1, etc.
        }
    }
    return -1;
}
// https://stackoverflow.com/questions/6054016/c-program-to-find-day-of-week-given-date
const char *wd(int year, int month, int day) {
    /* using C99 compound literals in a single line: notice the splicing */
    return ((const char *[]){
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
        "Sunday"})[(day +
                    ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
                    (365 * (year + 4800 - ((14 - month) / 12))) +
                    ((year + 4800 - ((14 - month) / 12)) / 4) -
                    ((year + 4800 - ((14 - month) / 12)) / 100) +
                    ((year + 4800 - ((14 - month) / 12)) / 400) - 32045) %
                   7];
}
int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900,
           tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    print_today(tm.tm_wday);
    /*    print_today(get_weekday("2020-03-26"));*/
    /*    printf("2020-03-26 is %s", names[get_weekday("2020-03-26")]);*/
    char day[20];
    scanf("%s", day);
    printf("%s is %s\n", day, names[get_weekday(day)]);
    printf("%d-%02d-%02d: %s\n", 2038, 1, 19, wd(2038, 1, 19));
}
