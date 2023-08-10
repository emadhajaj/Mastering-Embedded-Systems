#include <stdio.h>
#include <string.h>

struct student
{
    char name[50];
    int roll;
    float marks;
};

struct student getData(struct student stu, int rollNumber){
    stu.roll = rollNumber;
    printf("\nFor roll number %d\n", stu.roll);
    printf("Enter name: ");
    fgets(stu.name, sizeof(stu.name), stdin);
    printf("Enter marks: ");
    scanf("%f", &stu.marks);
    getchar();
    return stu;
}

void displayData(struct student stu){
    printf("Information of roll number %d:\n", stu.roll);
    printf("name: %s \n", stu.name);
    printf("marks: %.2f \n" , stu.marks);
}

int main() {

    struct student students[10];  int i;

    printf("Enter information of students:\n");
    for(i=0; i<10; i++){ 
        students[i] = getData(students[i], i+1);
        //getchar();  // consumes the newline character entered after entering marks
    }

    printf("Display information of students:\n");
    for(i=0; i<10; i++){ displayData(students[i]);}
   
    return 0;
}