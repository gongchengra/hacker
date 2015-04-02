#import <Foundation/Foundation.h>

struct Books
{
    NSString *title;
    NSString *author;
    NSString *subject;
    int   book_id;
};

@interface SampleClass:NSObject

/* function declaration */
- (void) printBook:( struct Books) book ;

@end

@implementation SampleClass 

- (void) printBook:( struct Books) book
{
    NSLog(@"Book title : %@\n", book.title);
    NSLog(@"Book author : %@\n", book.author);
    NSLog(@"Book subject : %@\n", book.subject);
    NSLog(@"Book book_id : %d\n", book.book_id);
}
@end

int main( )
{
    struct Books Book1;        /* Declare Book1 of type Book */
    struct Books Book2;        /* Declare Book2 of type Book */

    /* book 1 specification */
    Book1.title = @"Objective-C Programming";
    Book1.author = @"Nuha Ali"; 
    Book1.subject = @"Objective-C Programming Tutorial";
    Book1.book_id = 6495407;

    /* book 2 specification */
    Book2.title = @"Telecom Billing";
    Book2.author = @"Zara Ali";
    Book2.subject = @"Telecom Billing Tutorial";
    Book2.book_id = 6495700;

    SampleClass *sampleClass = [[SampleClass alloc]init];
    /* print Book1 info */
    [sampleClass printBook: Book1];

    /* Print Book2 info */
    [sampleClass printBook: Book2];

    return 0;
}
