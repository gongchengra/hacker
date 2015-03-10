#include <stdio.h>
int main ( void )
{
   static const char filename[] = "file.txt";
   FILE *file = fopen ( filename, "r" );
   if ( file != NULL )
   {
      char line [ 128 ]; /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
         fputs ( line, stdout ); /* write the line */
      }
      fclose ( file );
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }
   return 0;
}
/* file.txt
This text is the contents of the file named, "file.txt".
It is being used with some example code to demonstrate reading a file line by
line. More interesting things could be done with the output, but I'm trying to
keep this example very simple.
*/
/* my output
This text is the contents of the file named, "file.txt".
It is being used with some example code to demonstrate reading a file line by
line. More interesting things could be done with the output, but I'm trying to
keep this example very simple.
*/
