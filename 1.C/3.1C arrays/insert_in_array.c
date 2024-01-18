#include <stdio.h>
#include <stdlib.h>

int main() 
{

    int num, i, j, ins, loc, arr[10], inserted_arr[11];

    printf("Enter no of elements : ");
    scanf("%d", &num);

    for (i = 0; i < num; ++i){
        arr[i]= i+1;
    }

    
    for (i = 0; i < num; ++i){
        printf("%d ", arr[i]);
    }

    printf("\nEnter the elements to be inserted : ");
    scanf("%d", &ins);

    printf("Enter the location : ");
    scanf("%d", &loc);

    for (i = 0, j = 0; i < num; ++i, ++j){
        if(loc == i+1){
            inserted_arr[j] = ins;
            j++;
        }
        inserted_arr[j]=arr[i];
    }


    for (i = 0; i < num+1; ++i){
        printf("%d ", inserted_arr[i]);
    }


    return 0;
}