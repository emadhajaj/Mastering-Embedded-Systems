#include <stdio.h>
#include <stdlib.h>

int main() 
{

    float n;

    printf("Enter a number: ");
    scanf("%f", &n);

    if (n > 0){
        printf("%f is positive.", n);
    }else if (n < 0){
        printf("%f is nigative.", n);
    } else printf("You entered zero.");


    return 0;

}