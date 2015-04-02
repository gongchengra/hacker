#import <Foundation/Foundation.h>

#define  message_for(a, b)  \
    NSLog(@#a " and " #b ": We love you!\n")

int main(void)
{
    message_for(Carole, Debra);
    return 0;
}
