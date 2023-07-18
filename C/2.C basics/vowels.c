#include <stdio.h>
#include <stdlib.h>

int main() 
{

    char letter;

    printf("Enter an alphapit: ");
    scanf("%c", &letter);

    if ((letter == 'a') || (letter == 'A') || (letter == 'e') || (letter == 'E') || (letter == 'i') || (letter == 'I') || (letter == 'o') || (letter == 'O') || (letter == 'u') || (letter == 'U') ){
        printf("%c is a vowel.", letter);
    } else printf("%c is a consonant.", letter);


    return 0;

}