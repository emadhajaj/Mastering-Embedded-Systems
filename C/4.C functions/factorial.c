#include <stdio.h>
#include <string.h>

int factorial(int val1);

int main() {

    int val1;

    printf("Enter an positive integer: ");
    scanf("%d", &val1);

    printf("Factorial of %d = %d", val1, factorial(val1));
   
   return 0;
}


int factorial(int val1){
    if (val1 > 0){
        return val1 * factorial(val1-1);
    } else {return 1;}
}