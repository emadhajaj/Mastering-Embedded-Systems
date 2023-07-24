#include <stdio.h>
#include <stdlib.h>

int main() 
{

    int num, i, searched, arr[10];

    printf("Enter no of elements : ");
    scanf("%d", &num);

    for (i = 0; i < num; ++i){
        arr[i]= (i+1)*11;
    }

    
    for (i = 0; i < num; ++i){
        printf("%d ", arr[i]);
    }

    printf("\nEnter the elements to be searched : ");
    scanf("%d", &searched);

    for (i = 0; i < num; ++i){
        if(searched == arr[i]){
            printf("Number found at the location = %d", i+1);
        }
    }


    return 0;
}