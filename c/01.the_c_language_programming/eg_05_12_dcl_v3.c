/***
   NAME
     parse_dcl
   PURPOSE
     This program parses C declaratations (reading from stdin)
     and outputs an English language description of each declaration's
     meaning to stdout.
   NOTES
     This program is  a lsightly different version of the program
     given in Section 5.12 (pages 122--126) of the K & R book,
     second edition.
     A simplified form of C declaration is used, as described
     in the following BNF:
     <typed_declaration> ::= <type> <declaration>
     <declaration> ::= { '*' } <direct_declaration>
     <direct_declaration> ::= <name>
                            | '(' <declaration> ')'
                            | <declaration> '(' ')'
                            | <declaration> '[' <dimension> ']'
     <name> ::= a sequence of characters
     <dimension> ::=  { <digit>  }
   EXAMPLES
     Assuming the program is called parse_c_decs, then
     parse_c_decs << XXXX
        char *** abc;
        char *simple();
        char (*foo)();
        char (*(*bar())[])();
        int (*(*foobar[2][3])())();
        float (*(*f)())[5]();
     XXXX
      produces:
        abc is a  pointer to pointer to pointer to char
        simple is a  function returning pointer to char
        foo is a  pointer to function returning char
        bar is a  function returning pointer to array[] of pointer to function
        returning char
        foobar is a  array[2] of array[3] of pointer to function returning
        pointer to function returning int
        f is a  pointer to function returning pointer to array[5] of function
        returning float
   BUGS
     This is demonstration program only.  It does not
     understand the full C syntax of declarations.
     For examples, structs are not supported, type qualifiers
     like "const" or "volatile" are not supported, function argument
     types are not supported, etc.
   HISTORY
     kclowes (Ken Clowes) - Sept 25, 1993: Created.
***/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MAX_TOKEN_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 1000
enum {
    NAME,
    BOTH_PARENS,
    BRACKETS,
    LEFT_PARENS,
    RIGHT_PARENS,
    DECLARATION_END
};
typedef struct {
    int type;
    char value[MAX_DESCRIPTION_LENGTH];
} token_t;
static token_t token; /* next token from input stream */
static char description[MAX_DESCRIPTION_LENGTH];
static char name[MAX_TOKEN_LENGTH];
static int line;
static int n_errors;
void declaration(void);
int gettoken(void);
void direct_declaration(void);
int main() {
    char data_type[MAX_TOKEN_LENGTH];
    for (line = 1, n_errors = 0; gettoken() != EOF; line++) {
        /* 1st token is data declaration type */
        strcpy(data_type, token.value);
        description[0] = '\0';
        declaration();
        if (token.type != DECLARATION_END) {
            fprintf(stderr, "Syntax error on line %d\n", line);
            n_errors++;
        }
        printf("%s is a %s %s\n", name, description, data_type);
    }
    exit(n_errors);
}
/**
NAME:
  int gettoken()
PURPOSE:
  Reads the next token from stdin and set the global variable
  token to it.
ARGS:
  > None
RETURNS:
  < The token type: i.e. NAME, BOTH_PARENS, BRACKETS, LEFT_PAREN,
     RIGHT_PARENS, or the last return value form getchar
NOTES:
  The "last return value" from getchar may, or course, be EOF.
**/
int gettoken() {
    int ch;
    char *p = token.value;
    while ((ch = getchar()) == ' ' || ch == '\t' || ch == '\n')
        ;
    if (ch == '(') {
        if ((ch = getchar()) == ')') {
            strcpy(token.value, "()");
            return token.type = BOTH_PARENS;
        } else {
            ungetc(ch, stdin);
            return token.type = LEFT_PARENS;
        }
    } else if (ch == '[') {
        for (*p++ = ch; (*p++ = getchar()) != ']';)
            ;
        *p = '\0';
        return token.type = BRACKETS;
    } else if (isalpha(ch)) {
        for (*p++ = ch; isalnum(ch = getchar());)
            *p++ = ch;
        *p = '\0';
        ungetc(ch, stdin);
        return token.type = NAME;
    } else if (ch == ';')
        return token.type = DECLARATION_END;
    else if (ch == ')')
        return token.type = RIGHT_PARENS;
    else
        return token.type = ch;
}
/**
NAME:
  declaration
PURPOSE:
  Parses the following BNF.
     <declaration> ::= { '*' } <direct_declaration>
ARGS:
  > None.
RETURNS:
  < Nothing.
NOTES:
**/
void declaration(void) {
    int num_stars;
    for (num_stars = 0; gettoken() == '*'; num_stars++)
        ;
    direct_declaration();
    while (num_stars-- > 0)
        strcat(description, " pointer to");
}
/**
NAME:
  direct_declaration
PURPOSE:
  Implements the parsing of:
     <direct_declaration> ::= <name>
                            | '(' <declaration> ')'
                            | <declaration> '(' ')'
                            | <declaration> '[' <dimension> ']'
ARGS:
  >  None
RETURNS:
  <  Nothing
NOTES:
  Called from declaration, so leading <declaration>, if any, already
  parsed.
**/
void direct_declaration(void) {
    if (token.type == NAME)
        strcpy(name, token.value);
    else if (token.type == LEFT_PARENS) {
        declaration();
        if (token.type != RIGHT_PARENS) {
            fprintf(stderr, "missing ) on line %d\n", line);
            n_errors++;
        }
    } else {
        fprintf(stderr, "expected name or (dcl) on line %d\n", line);
        n_errors++;
    }
    for (gettoken(); token.type == BOTH_PARENS || token.type == BRACKETS;
         gettoken())
        if (token.type == BOTH_PARENS)
            strcat(description, " function returning");
        else {
            strcat(description, " array");
            strcat(description, token.value);
            strcat(description, " of");
        }
}
