#import <Foundation/Foundation.h>

int main ()
{
    NSString *str1 = @"Hello";
    NSString *str2 = @"World";
    NSString *str3;
    int  len ;

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    /* uppercase string */
    str3 = [str2 uppercaseString];
    NSLog(@"Uppercase String :  %@\n", str3 );

    /* concatenates str1 and str2 */
    str3 = [str1 stringByAppendingFormat:@"World"];
    NSLog(@"Concatenated string:   %@\n", str3 );

    /* total length of str3 after concatenation */
    len = [str3 length];
    NSLog(@"Length of Str3 :  %d\n", len );

    /* InitWithFormat */
    str3 = [[NSString alloc] initWithFormat:@"%@ %@",str1,str2];   
    NSLog(@"Using initWithFormat:   %@\n", str3 );
    [pool drain];

    return 0;
}
