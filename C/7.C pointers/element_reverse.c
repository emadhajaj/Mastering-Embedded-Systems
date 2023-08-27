#include <stdio.h> 

int main(){ 
    int n, i, elements[15], *ptr; 

    printf(" Input the number of elements to store in the array (max 15) : "); 
    scanf ("%d" ,&n) ; 

    ptr = &elements[0];
    printf(" Input %d number of elements in the array : \n",n); 
    
    for(i=0;i<n;i++) { 
        printf(" element - %d : ",i+1); 
        scanf("%d",ptr);
        ptr++; 
    } 
    
    ptr = &elements[n - 1]; 
    printf("\n The elements of array in reverse order are :"); 
    for (i = n; i > 0; i--) { 
        printf("\n element - %d : %d ", i, *ptr); 
        ptr--; 
    } 

    return 0;
}