#import <Foundation/Foundation.h>

#define tokenpaster(n) NSLog (@"token" #n " = %d", token##n)

int main(void)
{
    int token34 = 40;

    tokenpaster(34);
    return 0;
}
