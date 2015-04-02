#import <Foundation/Foundation.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(void)
{
    NSLog(@"Max between 20 and 10 is %d\n", MAX(10, 20));
    return 0;
}
