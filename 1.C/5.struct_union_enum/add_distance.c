#include <stdio.h>
#include <string.h>

struct distance
{
    int feet;
    float inch;
};

struct distance getData(struct distance dis){

    printf("Enter feet: ");
    scanf("%d", &dis.feet);
    printf("Enter inch: ");
    scanf("%f", &dis.inch);

    return dis;
}

void sum(struct distance d1, struct distance d2){
    struct distance d;
    d.feet = d1.feet + d2.feet;
    d.inch = d1.inch + d2.inch;
    while (d.inch > 12){
        d.feet ++;
        d.inch -= 12;
    }
    printf("\nSum of distance=%d'-%.1f\"\n" , d.feet, d.inch);
}

int main() {

    struct distance dis1, dis2;

    printf("Enter information for 1st distance:\n");
    dis1 = getData(dis1);

    printf("\nEnter information for 2nd distance: \n");
    dis2 = getData(dis2);

    sum(dis1, dis2);
   
   return 0;
}
