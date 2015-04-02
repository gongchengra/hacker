#import <Foundation/Foundation.h>

@interface SampleClass:NSObject

-(NSString *) getEmployeeNameForID:(int) id withError:(NSError **)errorPtr;

@end

@implementation SampleClass

-(NSString *) getEmployeeNameForID:(int) id withError:(NSError **)errorPtr{
    if(id == 1)
    {
        return @"Employee Test Name";
    }
    else
    {
        NSString *domain = @"com.MyCompany.MyApplication.ErrorDomain";
        NSString *desc =@"Unable to complete the process";
        NSDictionary *userInfo = [[NSDictionary alloc]
            initWithObjectsAndKeys:desc,
            @"NSLocalizedDescriptionKey",NULL];
        *errorPtr = [NSError errorWithDomain:domain code:-101
                                    userInfo:userInfo];
        return @"";
    }
}

@end


int main()
{
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    SampleClass *sampleClass = [[SampleClass alloc]init];
    NSError *error = nil;
    NSString *name1 = [sampleClass getEmployeeNameForID:1 withError:&error];

    if(error)
    {
        NSLog(@"Error finding Name1: %@",error);
    }
    else
    {
        NSLog(@"Name1: %@",name1);
    }

    error = nil;

    NSString *name2 = [sampleClass getEmployeeNameForID:2 withError:&error];

    if(error)
    {
        NSLog(@"Error finding Name2: %@",error);
    }
    else
    {
        NSLog(@"Name2: %@",name2);
    }

    [pool drain];
    return 0;

}
