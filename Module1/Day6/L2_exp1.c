/*
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };
Write a function to add a member at the end of the above array of structures
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

void addStudent(struct Student** students, int* numStudents) {
    (*numStudents)++;
    struct Student* newStudents = (struct Student*)realloc(*students, (*numStudents) * sizeof(struct Student));

    if (newStudents == NULL) {
        printf("Memory allocation failed. Student could not be added.\n");
        return;
    }

    *students = newStudents;

    struct Student* newStudent = &((*students)[(*numStudents) - 1]);

    printf("Enter Roll No: ");
    scanf("%d", &(newStudent->rollno));
    printf("Enter Name: ");
    scanf("%s", newStudent->name);
    printf("Enter Marks: ");
    scanf("%f", &(newStudent->marks));
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

    addStudent(&students, &numStudents);
    addStudent(&students, &numStudents);
    addStudent(&students, &numStudents);

    displayStudents(students, numStudents);

    free(students);

    return 0;
}
