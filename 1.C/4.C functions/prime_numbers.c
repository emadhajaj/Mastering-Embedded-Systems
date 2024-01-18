#include <stdio.h>
#include <string.h>

void prime(int val1, int val2);

int main() {

    int val1, val2;

    printf("Enter two numbers(intervals): ");
    scanf("%d%d", &val1, &val2);
    


    prime(val1, val2);
   
   return 0;
}


void prime(int val1, int val2){

    int i, j, count;
    printf("Prime numbers between %d and %d are:", val1, val2);

    for (i = val1; i <= val2; i++){
        count =0;
        for ( j = 2; j < i; j++)
        {
            if ((i%j) == 0)
            {
                count++;
            }
        }
        if (count == 0){
            printf(" %d", i);
        }
    }
    
    
}