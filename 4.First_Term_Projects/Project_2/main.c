#include "FIFO.h"


int main() {

	int choise=0, tempInt=0;
	char firstName_main[50];

	FIFO_t Students_queue;
	#define studentsNumber 55
	student_t Students_buffer[studentsNumber];

	Fifo_Init(&Students_queue, Students_buffer, studentsNumber);

	printf("Welcome to the Student Management System\n\n");

	while (1) {
		printf("Choose The Task that you want to perform\n");
		printf("1. Add the Student Details Manually\n");
		printf("2. Add the Student Details From Text File\n");
		printf("3. Find the Student Details by Roll Number\n");
		printf("4. Find the Student Details by First Name\n");
		printf("5. Find the Student Details by Course Id\n");
		printf("6. Find the Total number of Students\n");
		printf("7. Delete the Students Details by Roll Number\n");
		printf("8. Update the Students Details by Roll Number\n");
		printf("9. Show all information\n");
		printf("10. To Exit\n");
		printf("Enter your choice to perform the task: ");

		scanf("%d", &choise);

		switch (choise) {
			case 1:
				add_student_manually(&Students_queue, Students_buffer);
				break;
			case 2:
				add_student_file(&Students_queue, Students_buffer);
				break;
			case 3:
				printf("Enter the Roll Number of the student:");
				scanf("%d", &tempInt);
				if(find_rl(tempInt, &Students_queue, Students_buffer) != 0){
					print_student(&Students_buffer[(find_rl(tempInt, &Students_queue, Students_buffer))-1]);
				} else{
					printf("\n[ERROR] Roll number does not exist");
				}
				break;
			case 4:
				printf("Enter the First Name of the student:");
				scanf("%s", firstName_main);
				find_fn(firstName_main, &Students_queue, Students_buffer); // check this for warning
				break;
			case 5:
				printf("Enter the course ID: ");
				scanf("%d", &tempInt);
				find_c(tempInt, &Students_queue, Students_buffer);
				break;
			case 6:
				tot_s(&Students_queue);
				break;
			case 7:
				del_s(&Students_queue, Students_buffer);
				break;
			case 8:
				up_s(&Students_queue, Students_buffer);
				break;
			case 9:
				Print_Fifo(&Students_queue, Students_buffer);
				break;
			case 10:
				printf("Exiting\n============Thank you============");
				return 0;
			default:
				printf("You Entered wrong number");
				break;
		}

		printf("\n\n\n=====================================================================\n\n\n");
	}


	return 0;
}
