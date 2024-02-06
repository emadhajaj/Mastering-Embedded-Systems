#include "linked_list.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char temp_text[40];
    while (1)
    {
        printf("\n===============================\n");
        printf("Choose One Of The Following Options: \n");
        printf("\t 1. Add Student\n");
        printf("\t 2. Delete Student\n");
        printf("\t 3. View Students\n");
        printf("\t 4. Delete All\n");
        printf("\t 5. Get nth Node From First\n");
        printf("\t 6. linked List Length\n");
        printf("\t 7. Get nth Node From End\n");
        printf("\t 8. Get Mid Node\n");
        printf("\t 9. Detect Loop In Linked List\n");
        printf("\t 10. Reverse Linked List\n");

        printf("Enter Option Number: ");
        gets(temp_text);
        printf("\n===============================\n");
        switch (atoi(temp_text))
        {
        case 1:
            AddStudent();
            break;
        case 2:
            DeleteStudent();
            break;
        case 3:
            PrintStudents();
            break;
        case 4:
            DeleteAll();
            break;
        case 5:
            GetNthNode();
            break;
        case 6:
            LinkedListLength();
            break;
        case 7:
            GetNthNodeEnd();
            break;
        case 8:
            MidNode();
            break;
        case 9:
            DetectLoop();
            break;
        case 10:
            ReverseLinkedList();
            break;
        default:
            printf("Wrong Option!!!\n");
            break;
        }
    }
    return 0;
}
