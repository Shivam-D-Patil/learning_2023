/*
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };
Write a function to swap 2 members in different indexes (based on user input) in the above array of structures
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void swapStudents(struct Student* students, int index1, int index2) {
    struct Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
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
    struct Student students[] = {
        {1001, "Aron", 90.00},
        {1002, "Bob", 85.50},
        {1003, "Charlie", 92.75},
        {1004, "David", 88.25},
        {1005, "Eva", 95.50}
    };

    int numStudents = sizeof(students) / sizeof(struct Student);

    printf("Before swapping:\n");
    displayStudents(students, numStudents);

    int index1, index2;
    printf("Enter the indexes of the students to swap (0-%d): ", numStudents - 1);
    scanf("%d %d", &index1, &index2);

    if (index1 >= 0 && index1 < numStudents && index2 >= 0 && index2 < numStudents) {
        swapStudents(students, index1, index2);
        printf("After swapping:\n");
        displayStudents(students, numStudents);
    } else {
        printf("Invalid indexes. Swapping failed.\n");
    }

    return 0;
}
