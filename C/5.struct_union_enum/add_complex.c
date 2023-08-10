#include <stdio.h>
#include <string.h>

struct complex 
{
    float real;
    float imag;
};

struct complex getData(struct complex num){
    printf("\nEnter real and imaginary respectevly: ");
    scanf("%f%f", &num.real, &num.imag);
    return num;
}

void sum(struct complex n1, struct complex n2){printf("\nSum=%.1f+%.1fi" , n1.real + n2.real, n1.imag + n2.imag);}

int main() {
    struct complex number1, number2;
    sum(getData(number1), getData(number2));
   return 0;
}
