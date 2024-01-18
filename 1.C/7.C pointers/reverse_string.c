#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i=0, j;

    printf("Enter a string to reverse: ");
    gets(str);

    j = strlen(str);

    char *ptr = str +j - 1;

    printf("Reverse of the string: ");

    while (i < j) {
        printf("%c", *ptr);
        j--; ptr--;
    }


    return 0;
}