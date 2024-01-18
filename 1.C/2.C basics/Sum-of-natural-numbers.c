#include <stdio.h>
#include <stdlib.h>

int main() 
{

    int n, i, sum=0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    for(i=0; i<n+1; i++){
        sum += i;
    }

    printf("Sum = %d", sum);

    return 0;

}