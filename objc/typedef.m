#import <Foundation/Foundation.h>

typedef struct Books
{
    NSString *title;
    NSString *author;
    NSString *subject;
    int book_id;

} Book;

int main( )
{

    Book book;
    book.title = @"Objective-C Programming";
    book.author = @"TutorialsPoint";
    book.subject = @"Programming tutorial";
    book.book_id = 100;
    NSLog( @"Book title : %@\n", book.title);
    NSLog( @"Book author : %@\n", book.author);
    NSLog( @"Book subject : %@\n", book.subject);
    NSLog( @"Book Id : %d\n", book.book_id);

    return 0;
}
