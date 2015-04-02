#import <Foundation/Foundation.h>

int main ()
{
    int  var1;
    char var2[10];

    NSLog(@"Address of var1 variable: %x\n", &var1  );
    NSLog(@"Address of var2 variable: %x\n", &var2  );

    return 0;
}
