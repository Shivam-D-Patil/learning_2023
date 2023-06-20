/*
Implement structures to read, write and compute average- marks and the students scoring above
   and below the average marks for a class of N students.
*/
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    float marks;
};

void readStudents(struct Student* students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name and marks for student %d: ", i + 1);
        scanf("%s %f", students[i].name, &students[i].marks);
    }
}

void displayStudents(struct Student* students, int n) {
    printf("Student Data:\n");
    printf("---------------------\n");

    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("---------------------\n");
    }
}

float calculateAverage(struct Student* students, int n) {
    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum += students[i].marks;
    }

    return sum / n;
}

void displayAboveBelowAverage(struct Student* students, int n) {
    float average = calculateAverage(students, n);

    printf("Students scoring above average:\n");
    printf("---------------------\n");

    for (int i = 0; i < n; i++) {
        if (students[i].marks > average) {
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("---------------------\n");
        }
    }

    printf("Students scoring below average:\n");
    printf("---------------------\n");

    for (int i = 0; i < n; i++) {
        if (students[i].marks < average) {
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("---------------------\n");
        }
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

    readStudents(students, numStudents);
    displayStudents(students, numStudents);
    displayAboveBelowAverage(students, numStudents);

    return 0;
}
