#include <stdio.h>
#include <stdlib.h>

int main() 
{

    float num, sum=0;
    int i,n;


    printf("Enter the number of data: ");
    scanf("%d", &n);

    
    for(i=0; i<n; i++){
        printf("%d. Enter number: ", i+1);
        scanf("%f", &num);
        sum += num;
    }   
 
    printf("Average = %.2f", sum/n);

    return 0;
}