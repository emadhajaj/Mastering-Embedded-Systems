#include <stdio.h>
#include <string.h>

void rev(char arr[]);

int main() {

    char sen[100];

    printf("Enter a sentence: ");
    fgets(sen, sizeof(sen), stdin);
    
    rev(sen);
   
   return 0;
}


void rev(char arr[]){
    int i;
    for ( i = strlen(arr); i >= 0; i--){
        printf("%c", arr[i]);
    }
    
}