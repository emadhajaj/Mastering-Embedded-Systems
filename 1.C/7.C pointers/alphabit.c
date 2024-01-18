#include <stdio.h>
int main() { 
    char alph[27]; 
    int x; 
    char *ptr; 
    printf("Pointer : Print all the alphabets:\n");
    
    ptr = alph;

    for (x=0;x<26;x++){ 
        *ptr=x+'A'; // increment on the ASKII of 'A'
        ptr++;
    }

    ptr = alph;

    printf(" The Alphabets are : \n");
    for (x=0;x<26;x++){ 
        printf(" %c ", *ptr); 
        ptr++;
    }
    
    printf("\n\n");
    return 0;
}