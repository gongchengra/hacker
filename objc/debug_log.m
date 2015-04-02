#import <Foundation/Foundation.h>

#if DEBUG == 0
#define DebugLog(...)
#elif DEBUG == 1
#define DebugLog(...) NSLog(__VA_ARGS__)
#endif

int main()
{
    DebugLog(@"Debug log, our custom addition gets \
            printed during debug only" );
    NSLog(@"NSLog gets printed always" );
    return 0;
}
