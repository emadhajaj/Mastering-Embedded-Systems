#include <stdio.h>
#include <stdlib.h>

int main() 
{

    char letter;

    printf("Enter an character: ");
    scanf("%c", &letter);

    if ( ((letter > 64) && (letter < 91)) || ((letter > 96) && (letter < 123))){
        printf("%c is an alphabet.", letter);
    } else printf("%c is not an alphabet.", letter);


    return 0;

}