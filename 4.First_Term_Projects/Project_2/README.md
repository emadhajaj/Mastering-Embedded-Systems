# Students Database

This C code is a simple Student Management System that allows users to add, search, update, and delete student details. The program uses a circular queue (FIFO data structure), and student details are presented in a structure called `student_t`.

The `FIFO_t` structure holds circular buffer related details, including the base address of the buffer, count of elements in the buffer, and the number of allocated bytes in the buffer.

The code is divided into two major sections: **The Student** and **The FIFO**. The Student section includes the student details structure (`student_t`), while the FIFO section contains all the functions required for the implementation of the circular queue data structure.

The **Database APIs** section includes several functions, such as `add_student_file()`, `add_student_manually()`, `find_fn()`, `find_c()` used to manage students' information in the circular queue data structure.

### Building the code

To compile the code, please follow the steps:

1. Open the terminal or command prompt
2. Navigate to the directory containing the C file
3. Compile the code using a C compiler with the following command: `gcc -o outname filename.c`
4. Run the program with command: `./outname`

### How to use the program

This student management system provides the following options to the user:

1. Add the Student Details Manually
    - User can add details of a new student manually by providing their Name, Roll number, GPA, and course ids.
2. Add the Student Details From Text File
    - User can add details of one or more students via a file.
3. Find the Student Details by Roll Number
    - User can search for student details using their Roll number.
4. Find the Student Details by First Name
    - User can search for student details using their First Name.
5. Find the Student Details by Course Id
    - Users can search for a specific course ID across all students
6. Find the Total number of Students
    - This option will display the total number of students currently in the database.
7. Delete the Students Details by Roll Number
    - This option will delete student details for the given Roll number.
8. Update the Students Details by Roll Number
    - Users can update a student's details using their Roll number.
9. Show all information
    - This option will display all information about all enrolled students.

