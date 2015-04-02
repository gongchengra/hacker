#import <Foundation/Foundation.h>

@interface SampleClass:NSObject

- (NSNumber *)multiplyA:(NSNumber *)a withB:(NSNumber *)b;

@end

@implementation SampleClass

- (NSNumber *)multiplyA:(NSNumber *)a withB:(NSNumber *)b
{
    float number1 = [a floatValue];
    float number2 = [b floatValue];
    float product = number1 * number2;
    NSNumber *result = [NSNumber numberWithFloat:product];
    return result;
}

@end

int main()
{
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    SampleClass *sampleClass = [[SampleClass alloc]init];
    NSNumber *a = [NSNumber numberWithFloat:10.5];
    NSNumber *b = [NSNumber numberWithFloat:10.0];
    NSNumber *result = [sampleClass multiplyA:a withB:b];
    NSString *resultString = [result stringValue];
    NSLog(@"The product is %@",resultString);

    [pool drain];
    return 0;
}

