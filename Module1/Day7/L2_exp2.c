/*
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };
2. Write a function to delete a member at the start of the above array of structures
Note : Code must use Dynamic Memory concept
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void deleteStudent(struct Student** students, int* numStudents) {
    if (*numStudents == 0) {
        printf("No students to delete.\n");
        return;
    }

    (*numStudents)--;

    struct Student* newStudents = (struct Student*)realloc(*students, (*numStudents) * sizeof(struct Student));

    if (newStudents == NULL) {
        printf("Memory reallocation failed. Student could not be deleted.\n");
        return;
    }

    *students = newStudents;

    printf("Deleted student:\n");
    printf("Roll No: %d\n", (*students)[0].rollno);
    printf("Name: %s\n", (*students)[0].name);
    printf("Marks: %.2f\n", (*students)[0].marks);

    // Shift the remaining students by one position to the beginning of the array
    memmove(*students, *students + 1, (*numStudents) * sizeof(struct Student));
}

void displayStudents(const struct Student* students, int numStudents) {
    printf("Student Data:\n");
    printf("---------------------\n");

    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("---------------------\n");
    }
}

int main() {
    struct Student* students = NULL;
    int numStudents = 0;

    // Add some sample students
    struct Student student1 = {1001, "Aron", 90.00};
    struct Student student2 = {1002, "Bob", 85.50};
    struct Student student3 = {1003, "Charlie", 92.75};

    students = (struct Student*)malloc(3 * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    students[0] = student1;
    students[1] = student2;
    students[2] = student3;
    numStudents = 3;

    printf("Before deletion:\n");
    displayStudents(students, numStudents);

    deleteStudent(&students, &numStudents);

    printf("After deletion:\n");
    displayStudents(students, numStudents);

    free(students);

    return 0;
}
