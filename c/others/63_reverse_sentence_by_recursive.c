#include <stdio.h>
void reverseSentence(){
    char c;
    scanf("%c", &c);
    if(c != '\n'){
        reverseSentence();
        printf("%c", c);
    }
}
int main(int argc, char **argv){
    printf("Enter a sentence: ");
    reverseSentence();
    return 0;
}
