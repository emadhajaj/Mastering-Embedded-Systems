#include <stdio.h>
#include <string.h>

int npower(int base, int power);

int main() {

    int num , pwr;

    printf("Enter base number: ");
    scanf("%d", &num);

    printf("Enter power number(positive integer): ");
    scanf("%d", &pwr);

    printf("%d ^ %d = %d", num, pwr, npower(num, pwr));
   
   return 0;
}


int npower(int base, int power){
    if (power > 0){
        return base * npower(base, power-1);
    } else {return 1;}
}