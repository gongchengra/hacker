#import <Foundation/Foundation.h>

int main()
{
const int  LENGTH = 10;
const int  WIDTH  = 5;
const char NEWLINE = '\n';
int area;  

area = LENGTH * WIDTH;
NSLog(@"value of area : %d", area);
NSLog(@"%c", NEWLINE);

return 0;
}
