#include <stdio.h>
#include <stdlib.h>

int main() 
{

    int a[10][10], transpose[10][10], r, c, i, j;

    printf("Enter rows and columns of matrix: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            transpose[j][i] = a[i][j];

    

    printf("\nEntered matrix: \n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\nTranspose of Matrix:\n");
    for (i = 0; i < c; ++i) {
        for (j = 0; j < r; ++j)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }

    return 0;
}