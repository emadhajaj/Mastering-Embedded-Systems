#include <stdio.h>

int main() {

    int m = 29;
    printf("Address of m : 0x%llx\n", &m);
    printf("Value of m : %d", m);

    int *ab = &m;
    printf("\n\nNow ab is assigned with the address of m.\n");
    printf("Address of pointer ab : 0x%llx\n", ab);
    printf("Content of pointer ab : %d", *ab);

    *ab = 7;
    printf("\n\nThe pointer variable is assigned with value 7 now.\n");
    printf("Address of m 0x%llx\n", &m);
    printf("Value of m : %d", m);

   return 0;
}
