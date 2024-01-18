#include "FIFO.h"

int FirstStudentFlag = 0;



// ============================== Students Database FIFO ==============================
#define studentsNumber      55

FILE *students_file;


// ============================== FIFO Functions ==============================

FIFO_STATUS Fifo_Init(FIFO_t *fifo_buf, student_t *student, uint32_t length)
{
    if (student == NULL)
        return FIFO_NULL;

    fifo_buf->head = student;
    fifo_buf->base = student;
    fifo_buf->tail = student;
    fifo_buf->length = length;
    fifo_buf->count = 1;

    return FIFO_NO_ERROR;
}

FIFO_STATUS Fifo_Enqueue(FIFO_t *fifo_buf, student_t item)
{
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_NULL;

    if (Fifo_IsFull(fifo_buf) == FIFO_FULL)
    {
        return FIFO_FULL;
    }

    *(fifo_buf->head) = item;
    fifo_buf->count++;

    if (fifo_buf->head == fifo_buf->base + fifo_buf->length * sizeof(el_type))
        fifo_buf->head = fifo_buf->base;
    else
        fifo_buf->head++;

    return FIFO_NO_ERROR;
}

FIFO_STATUS Fifo_Dequeque(FIFO_t *fifo_buf)
{
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_NULL;

    if (fifo_buf->count == 0)
    {
        return FIFO_EMPTY;
    }

    fifo_buf->count--;

    if (fifo_buf->tail == fifo_buf->base + fifo_buf->length * sizeof(el_type))
        fifo_buf->tail = fifo_buf->base;
    else
        fifo_buf->tail++;

    return FIFO_NO_ERROR;
}

void print_student(student_t *stu){
	int j;
	printf("The Student Details are:\n");
		printf("First name is: %s\n", stu->fname);
		printf("Last name is: %s\n", stu->lname);
		printf("Roll Number is: %d\n", stu->roll);
		printf("The GPA is : %f\n", stu->GPA);
		printf("The course ID of each course\n");
		for (j = 0; j < 5; ++j) {
			printf("The course ID are %d\n", stu->cid[j]);
		}
		printf("------------------------------------------------");
}


FIFO_STATUS Fifo_IsFull(FIFO_t *fifo_buf)
{
    if (!fifo_buf->head || !fifo_buf->tail || !fifo_buf->base)
        return FIFO_NULL;

    if (fifo_buf->count == fifo_buf->length)
    {
        return FIFO_FULL;
    }

    return FIFO_NO_ERROR;
}

void Print_Fifo(FIFO_t *fifo, student_t *buffer)
{

	if (!fifo->head || !fifo->tail || !fifo->base){
    	printf("[Error] Fifo has a problem at head or tail or base !!!!\n\n");
    	return;
    }

	int i;
	student_t *start = fifo->tail;
    if (fifo->count == 0)
    {
        printf("Fifo Is Empty !!!!\n\n");
    }
    else
    {
        printf("\n============= Print FIFO =================\n");
		
		
        for (i = 0; i < (fifo->count)-1; i++)
        {
        	print_student(start);
            printf("\n");

			if (start == fifo->base + fifo->length * sizeof(el_type))
				start = fifo->base;
			else
				start++;
        }
    }
}








// ============================== Database Functions ==============================

void add_student_file(FIFO_t *queue, student_t *buffer){

	student_t tempStu;
	int i, flag =0;

	students_file = fopen("students.txt", "r");

	// Check the file
	if(students_file == NULL){
		printf("\n [ERROR] students.txt file not found.");
		printf("\n [ERROR] adding students from file failed.");
		return;
	}

	while(!feof(students_file)){ // Read all the file
		flag =0;
		fscanf(students_file, "%d", &tempStu.roll);

		// Check if the roll number is exists

		for (i = 0; (i < queue->count -1) || (flag = 0); i++){

			if(find_rl(tempStu.roll, queue, buffer) == buffer[i].roll){
				printf("\n[ERROR] Roll number %d is already taken", tempStu.roll);

				// Ignore the rest of the line
				fscanf(students_file, "%*[^\n]");

				flag =1;
				break;
			}
		}

		if (!flag){
			fscanf(students_file, "%s", tempStu.fname);
			fscanf(students_file, "%s", tempStu.lname);
			fscanf(students_file, "%f", &tempStu.GPA);

			for (i = 0; i < 5; ++i){
				fscanf(students_file, "%d", &tempStu.cid[i]);
			}

			// Enqueue
			if((Fifo_Enqueue(queue, tempStu))== FIFO_NO_ERROR){
				printf("\n[INFO] Roll number %d is saved successfully", tempStu.roll);
			}
			else{
				printf("\n[ERROR] Adding students by file failed");
				return;
			}
		}
	}

	printf("\n[INFO] Students details are saved successfully");

	// close
	fclose(students_file);

	//Print_Fifo(queue);
}


void add_student_manually(FIFO_t *queue, student_t *buffer){

    student_t tempStu;
    int i;

    printf("\n------------------------------------------------\n\n");

    printf("Enter the Roll Number:");
    scanf("%d", &tempStu.roll);

	// Check if the roll number is free
	for (i = 0; i < queue->count -1; i++){
		if(find_rl(tempStu.roll, queue, buffer) == buffer[i].roll){
			printf("\n[ERROR] Roll number %d is already taken", tempStu.roll);
			printf("\n[ERROR] Adding student manually failed");
			return;
		}
	}

    printf("Enter the first name of student:");
    scanf("%s",tempStu.fname);

    printf("Enter the last name of student:");
    scanf("%s",tempStu.lname);

	printf("Enter the GPA you obtained:");
	scanf("%f", &tempStu.GPA);

	printf("Enter the course ID of each course\n");
	for (i = 0; i < 5; ++i) {
		printf("Course %d id: ", i+1);
		scanf("%d", &tempStu.cid[i]);
	}

	// Add new student
	if(Fifo_Enqueue(queue, tempStu) == FIFO_NO_ERROR)
	{
		printf("\n[INFO] Student details are saved successfully\n");
	}
	else
	{
		printf("\n[ERROR] Adding student manually failed\n");
		return;
	}

    //Print_Fifo(&queue);

	printf("\n ------------------------------------------------");
	tot_s(queue);
}


int find_rl(int findRollNumber, FIFO_t *queue, student_t *buffer){
	int i;

	// check if the roll number exists
	for (i = 0; i < (queue->count) -1; i++){
		if(findRollNumber == buffer[i].roll){
			return i + 1;
		}
	}

	return 0;
}


void find_fn(const char *findFirstName, FIFO_t *queue, student_t *buffer){
	int i, flag = 0;

	for (i = 0; i < (queue->count) -1; i++){
		if(strcmp(findFirstName, buffer[i].fname) == 0){
			print_student(&buffer[i]);
			flag ++;
		}
	}

	if (flag){
		printf("\n[INFO] Successfully found %d students", flag);
	} else{
		printf("\n[ERROR] No matches for this first name");
	}
}


void find_c(int id, FIFO_t *queue, student_t *buffer){

	int i, j, counter =0;

	// check if the roll number exists
	for (i = 0; i < (queue->count) -1; i++){
		for (j = 0; j < 5; j++){
			if(id == buffer[i].cid[j]){
				print_student(&buffer[i]);
				printf("\n");
				counter ++;
			}
		}
	}

	printf("\n[INFO] Total Number of Students Enrolled: %d", counter);
}


void tot_s(FIFO_t *queue){

	printf("\n[INFO] The total number of Student is: %d", queue->count -1);
	printf("\n[INFO] You can add up to %d Students", studentsNumber);
	printf("\n[INFO] You can add %d more students", studentsNumber - (queue->count) +1);
}


void del_s(FIFO_t *queue, student_t *buffer){

	int num, index, i;

	printf("Enter the Roll Number which you want to delete:");
	scanf("%d", &num);

	if (find_rl(num,queue, buffer) == 0){
		printf("\n[ERROR] The Roll Number %d not Found", num);
	} else {
		if (Fifo_Dequeque(queue) == FIFO_NO_ERROR){
			index =find_rl(num, queue, buffer) -1;

			for ( i = 0; i < index; i++){
				buffer[index] = buffer[index-1];
				index--;
			}
			
			printf("\n[INFO] The Roll Number is removed Successfully");
		} else{
			printf("\n[ERROR] The Roll Number faild to remove!");
		}
	}
}


void up_s(FIFO_t *queue, student_t *buffer){
	int num, index, i;

    printf("Enter the roll number to update the entry:");
	scanf("%d", &num);

	if (find_rl(num,queue, buffer) == 0){
		printf("\n[ERROR] The Roll Number %d not Found", num);
	} else {
		index =find_rl(num, queue, buffer) -1;

		printf("Enter the Roll Number:");
		scanf("%d", &buffer[index].roll);

		// Check if the roll number is free
		for (i = 0; i < queue->count -1; i++){
			if((find_rl(buffer[index].roll, queue, buffer) == buffer[i].roll) && (num != buffer[i].roll)){
				printf("\n[ERROR] Roll number %d is already taken", buffer[index].roll);
				printf("\n[ERROR] Adding student manually failed");
				return;
			}
		}

		printf("Enter the first name of student:");
		scanf("%s",buffer[index].fname);

		printf("Enter the last name of student:");
		scanf("%s",buffer[index].lname);

		printf("Enter the GPA you obtained:");
		scanf("%f", &buffer[index].GPA);

		printf("Enter the course ID of each course\n");
		for (i = 0; i < 5; ++i) {
			printf("Course %d id: ", i+1);
			scanf("%d", &buffer[index].cid[i]);
		}

		printf("\n[INFO] UPDATED SUCCESSFULLY.");
	}

}





