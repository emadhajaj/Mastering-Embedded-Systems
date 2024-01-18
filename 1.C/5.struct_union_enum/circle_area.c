#include <stdio.h>
#define pi 22.0/7
#define area(r) (pi*r*r) 

int main()
{
    float radius;
    printf("Enter the radius: ");
    scanf("%f", &radius);
    printf("Area=%.2f", area(radius));
    return 0;
}
