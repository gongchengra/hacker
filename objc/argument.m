#import <Foundation/Foundation.h>

int main( int argc, char *argv[] )
{
    if( argc == 2 )
    {
        NSLog(@"The argument supplied is %s\n", argv[1]);
    }
    else if( argc > 2 )
    {
        NSLog(@"Too many arguments supplied.\n");
    }
    else
    {
        NSLog(@"One argument expected.\n");
    }
}
