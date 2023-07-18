#include <stdio.h>
#include <stdlib.h>

int main() 
{

    float a, b, c;

    printf("Enter three numbers: ");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    if (b > a){
        if (b > c){
            printf("Largest number = %f", b);
        } else printf("Largest number = %f", c);
    } else if (c > a){
        printf("Largest number = %f", c);
    } else printf("Largest number = %f", a);


    return 0;

}