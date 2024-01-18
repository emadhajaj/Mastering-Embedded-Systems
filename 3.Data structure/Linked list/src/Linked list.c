#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

sList_t *gpFirstStd = NULL;

void AddStudent()
{
    sList_t *pNewStd;
    sList_t *pLaststd;
    char temp[40];

    pNewStd = (sList_t *)malloc(sizeof(sList_t));
    if (gpFirstStd == NULL)
    {
        gpFirstStd = pNewStd;
    }
    else
    {
        pLaststd = gpFirstStd;
        while (pLaststd->next)
        {
            pLaststd = pLaststd->next;
        }
        pLaststd->next = pNewStd;
    }

    printf("Enter ID: ");
    gets(temp);
    pNewStd->student.ID = atoi(temp);

    printf("Enter Name: ");
    gets(pNewStd->student.name);

    printf("Enter Height: ");
    gets(temp);
    pNewStd->student.height = atof(temp);

    pNewStd->next = NULL;
}

int DeleteStudent()
{
    char temp[40];
    printf("Enter An ID To Be Deleted: ");
    gets(temp);
    int selectedId = atoi(temp);

    if (gpFirstStd == NULL)
    {
        printf("Empty List !!!\n");
        return 0;
    }
    sList_t *currStd = gpFirstStd;
    sList_t *prevStd = NULL;

    while (currStd)
    {
        if (currStd->student.ID == selectedId)
        {
            if (prevStd)
            {
                prevStd->next = currStd->next;
                printf("Student With ID: %d Deleted !!\n", selectedId);
                return 1;
            }
            else
            {
                gpFirstStd = gpFirstStd->next;
            }
            free(currStd);
        }
        prevStd = currStd;
        currStd = currStd->next;
    }

    printf("There Is No Student With ID: %d\n", selectedId);
    return 0;
}

void PrintStudents()
{
    unsigned int count = 0;
    if (!gpFirstStd)
        printf("Empty List!!!!\n");
    else
    {
        sList_t *currStd = gpFirstStd;

        while (currStd)
        {
            printf("\n Record Number: %d\n", count + 1);
            printf("\n\t ID: %d", currStd->student.ID);
            printf("\n\t Name: %s", currStd->student.name);
            printf("\n\t height: %.2f", currStd->student.height);
            printf("\n=======================\n");

            currStd = currStd->next;
            count++;
        }
    }
}

void DeleteAll()
{
    if (!gpFirstStd)
        printf("Empty List!!!!\n");
    else
    {
        sList_t *currStd = gpFirstStd;

        while (currStd)
        {
            sList_t *temp = currStd;
            currStd = currStd->next;
            free(temp);
        }
        gpFirstStd = NULL;
    }
}

void GetNthNode()
{
    char temp[40];
    printf("Enter A Node From The First: ");
    gets(temp);
    int selectedNode = atoi(temp);
    int i = selectedNode - 1;

    sList_t *currNode = gpFirstStd;
    while (i--)
    {
        currNode = currNode->next;
    }
    if (!currNode)
    {
        printf("Invaild ID :( !!!\n");
    }
    else
    {
        printf("\nThe (%d)nth Node Contains: \n", selectedNode);
        printf("\tID: %d\n", currNode->student.ID);
        printf("\tName: %s\n", currNode->student.name);
        printf("\tHeight: %.2f\n", currNode->student.height);
    }
}

int LinkedListLength()
{
    int length;
    sList_t *curr = gpFirstStd;
    if (!curr)
    {
        printf("Empty List!!");
        return 0;
    }
    else
    {
        while (curr)
        {
            curr = curr->next;
            length++;
        }
    }
    printf("\nThe Length Of This Linked List Is: %d\n", length);

    return length;
}

int GetNthNodeEnd()
{
    sList_t *selectedNode = gpFirstStd;
    sList_t *lastNode = gpFirstStd;
    char temp[40];
    printf("Enter The nth Node From The End: ");
    gets(temp);
    int n = atoi(temp);

    while (lastNode)
    {
        if (n)
        {
            lastNode = lastNode->next;
            n--;
        }
        else
        {
            lastNode = lastNode->next;
            selectedNode = selectedNode->next;
        }
    }

    if (selectedNode)
    {
        printf("\nThe (%s)nth Node Contains: \n", temp);
        printf("\tID: %d\n", selectedNode->student.ID);
        printf("\tName: %s\n", selectedNode->student.name);
        printf("\tHeight: %.2f\n", selectedNode->student.height);
    }
    else
    {
        printf("\n There NO %sth Node From The End!!\n", temp);
    }

    return atoi(temp);
}

int MidNode()
{
    sList_t *pFast = gpFirstStd;
    sList_t *pSlow = gpFirstStd;
    int length = 0;

    while (pFast && pFast->next)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        length++;
    }

    // pSlow = pSlow->next;

    printf("The Mid Node In This Linked List Is the (%d)th Node\n", length + 1);
    printf("\tID: %d\n", pSlow->student.ID);
    printf("\tName: %s\n", pSlow->student.name);
    printf("\tHeight: %.2f\n", pSlow->student.height);

    return length;
}

int DetectLoop()
{
    sList_t *pFast = gpFirstStd;
    sList_t *pSlow = gpFirstStd;

    while (pSlow && pFast && pFast->next)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pFast == pSlow)
        {
            printf("\nLoop Detected In This Linked List !!!\n");
            return 0;
        }
        }

    printf("\nNo Loop Detected :)\n");
    return 1;
}

void ReverseLinkedList()
{
    sList_t *prev = NULL;
    sList_t *current = gpFirstStd;
    sList_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    gpFirstStd = prev;
    printf("\n Linked List Reversed :))\n");
}
