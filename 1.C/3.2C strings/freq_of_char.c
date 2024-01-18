#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{

    char character, string[256];
    unsigned int i, sum=0;


    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);//safer than scanf() for reading strings with spaces.
    
    printf("Enter a charecter to find frequency: ");
    scanf("%c", &character);

    for ( i = 0; i < strlen(string); i++){
        if (character == string[i]){
            sum ++;
        }
        
    }
    

    printf("Frequency of %c = %d", character, sum);

    return 0;
}