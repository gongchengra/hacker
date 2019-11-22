#include <stdio.h>
/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}
int main(void)
{
    int i;
    char *month;
    for(i = 0; i< 14; i++)
    {
        month = month_name(i);
        printf("The name of %d th month is %s.\n", i, month);
        printf("The fisrt three characters of the month is %c%c%c.\n",month[0],month[1],month[2]);
    }
    return 0;
}
