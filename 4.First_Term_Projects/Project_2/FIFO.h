#ifndef _FIFO_H_
#define _FIFO_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>



// =============== The Student ===============

typedef struct {
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[16];
} student_t;



// =============== The FIFO ===============

#define el_type uint8_t
#define width   55

typedef struct
{
    el_type   length;
    el_type   count;
    student_t *base;
    student_t *head;
    student_t *tail;
} FIFO_t;


typedef enum
{
    FIFO_NO_ERROR,
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL
} FIFO_STATUS;



// =============== FIFO APIs ===============

FIFO_STATUS Fifo_Init(FIFO_t *fifo_buf, student_t *student, uint32_t length);
FIFO_STATUS Fifo_Enqueue(FIFO_t *fifo_buf, student_t item);
FIFO_STATUS Fifo_Dequeque(FIFO_t *fifo_buf);
void print_student(student_t *stu);
FIFO_STATUS Fifo_IsFull(FIFO_t *fifo_buf);
void Print_Fifo(FIFO_t *fifo, student_t *buffer);



// =============== Database APIs ===============

void add_student_file(FIFO_t *queue, student_t *buffer);
void add_student_manually(FIFO_t *queue, student_t *buffer);
int  find_rl(int findRollNumber, FIFO_t *queue, student_t *buffer);
void find_fn(const char *findFirstName, FIFO_t *queue, student_t *buffer);
void find_c(int id, FIFO_t *queue, student_t *buffer);
void tot_s(FIFO_t *queue);
void del_s(FIFO_t *queue, student_t *buffer);
void up_s(FIFO_t *queue, student_t *buffer);



#endif
