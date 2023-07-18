#include <stdio.h>
#include <stdlib.h>

int main() 
{

    int n, i, factorial =1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n > 0){

        for(i=1; i<= n; i++){
            factorial *= i;
        }


        printf("Factorial = %d", factorial);
    }else if (n < 0){
        printf("Error!!! Factorial of negative number doesn't exist.");
    } else printf("Factorial = 1");


    return 0;

}