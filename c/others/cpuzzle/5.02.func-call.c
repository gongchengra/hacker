#include <stdio.h>
void room1();
void room2();
int main() {
    printf("I am in main and call room1.\n");
    room1();
    room2();
}
void room1() { printf("Now I am in room1.\n"); }
void room2() { printf("Now I am in room2.\n"); }
