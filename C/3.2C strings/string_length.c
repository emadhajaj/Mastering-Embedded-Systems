#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{

    char string[256];
    unsigned int i, sum=0;


    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);//safer than scanf() for reading strings with spaces.

    for ( i = 0; i < 256; i++){
        if ('\0' == string[i]){
            printf("Length of string : %d", sum-1);
            return 0;
        }
        sum ++;
    }
    
    return 0;
}