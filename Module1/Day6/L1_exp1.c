/*
Assume User will be providing input in the form of a string as show below. 
Write a function to parse the string and initialize an array of structures. 

Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringToStructArray(const char* inputString, struct Student* students, int numStudents) {
    const char* delimiter = " ";
    char* token;

    token = strtok((char*)inputString, delimiter);

    for (int i = 0; i < numStudents; i++) {
  
        students[i].rollno = atoi(token);
 
        token = strtok(NULL, delimiter);
        strcpy(students[i].name, token);
 
        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);

        token = strtok(NULL, delimiter);
    }
}

void displayStudentArray(const struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("---------------------\n");
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
 
    while (getchar() != '\n');

    char inputString[100];
    printf("Enter the student data (rollno name marks): ");
    fgets(inputString, sizeof(inputString), stdin);

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    parseStringToStructArray(inputString, students, numStudents);
    displayStudentArray(students, numStudents);

    free(students);

    return 0;
}
