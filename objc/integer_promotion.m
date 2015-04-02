#import <Foundation/Foundation.h>

int main()
{
    int  i = 17;
    char c = 'c'; /* ascii value is 99 */
    char a = 'a';
    char A = 'A';
    int sum;

    sum = i + c;
    NSLog(@"Value of sum : %d\n", sum );
    NSLog(@"Value of a : %d\n", a );
    NSLog(@"Value of A : %d\n", A );

    return 0;
}
