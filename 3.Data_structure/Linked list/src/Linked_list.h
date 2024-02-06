#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct SData
{
    unsigned int ID;
    char name[40];
    float height;
};

typedef struct SLinkedList
{
    struct SData student;
    struct SLinkedList *next;
} sList_t;

void AddStudent();
int DeleteStudent();
void PrintStudents();
void DeleteAll();
void GetNthNode();
int LinkedListLength();
int GetNthNodeEnd();
int MidNode();
int DetectLoop();
void ReverseLinkedList();

#endif
