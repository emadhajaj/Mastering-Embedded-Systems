#include <stdio.h>
#include <string.h>

struct student
{
    char name[50];
    int roll;
    float marks;
};

struct student getData(struct student stu){
    printf("Enter name: ");
    gets(stu.name);
    printf("Enter roll: ");
    scanf("%d", &stu.roll);
    printf("Enter marks: ");
    scanf("%f", &stu.marks);

    return stu;
}

void displayData(struct student stu){
    printf("name: %s \n", stu.name);
    printf("roll: %d \n", stu.roll);
    printf("marks: %.2f \n" , stu.marks);
}

int main() {

    struct student stu1;

    printf("Enter information of studenst: \n\n");
    stu1 = getData(stu1);

    printf("\nDisplay information\n");
    displayData(stu1);
   
   return 0;
}
