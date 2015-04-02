#import <Foundation/Foundation.h>

int main ()
{
    int  var = 20;   /* actual variable declaration */
    int  *ip;        /* pointer variable declaration */

    ip = &var;  /* store address of var in pointer variable*/

    NSLog(@"Address of var variable: %x\n", &var  );

    /* address stored in pointer variable */
    NSLog(@"Address stored in ip variable: %x\n", ip );

    /* access the value using the pointer */
    NSLog(@"Value of *ip variable: %d\n", *ip );

    return 0;
}

