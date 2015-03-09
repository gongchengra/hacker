/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : ex6.c

* Author : gongchengra@gmail.com

* Purpose :

* Creation Date : 2015-02-03

* Last Modified :

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";

    printf("You are %d miles away.\n", distance);
    printf("You are %d miles away.\n", 0123);
    printf("You are %d miles away.\n", 0x123);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c. %s.\n",
            first_name, initial, last_name);
    printf("Test empty string. %s Return\n","");
    return 0;
}
