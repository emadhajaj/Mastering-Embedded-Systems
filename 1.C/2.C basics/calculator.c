#include <stdio.h>
#include <stdlib.h>

int main() 
{

    float a, b;
    char operator;

    printf("Enter operator either + or - or * or divide : ");
    scanf("%c", &operator);

    printf("Enter two eperands: ");
    scanf("%f", &a);
    scanf("%f", &b);
    


    switch (operator)
    {
    case '+':
        printf("%.1f + %.1f = %.1f", a, b, a+b);
        break;

    case '-':
        printf("%.1f - %.1f = %.1f", a, b, a-b);
        break;

    case '*':
        printf("%.1f * %.1f = %.1f", a, b, a*b);
        break;

    case '/':
        printf("%.1f / %.1f = %.1f", a, b, a/b);
        break;
    
    default:
        break;
    }




    return 0;

}