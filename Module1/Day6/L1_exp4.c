/*
Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };
    Write a function to sort the array of structures in descending order based on marks 
*/
#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStudentsDescending(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap the positions of students[j] and students[j + 1]
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStudents(const struct Student* students, int numStudents) {

    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
         
}
int main ()
{
struct Student students[] = {
        {1001, "Aron", 100.00},
        {1002, "Bob", 95.50},
        {1003, "Charlie", 87.75},
        {1004, "David", 92.25},
        {1005, "Eva", 80.50}
    };

    int numStudents = sizeof(students) / sizeof(struct Student);

    printf("Before sorting:\n");
    displayStudents(students, numStudents);

    sortStudentsDescending(students, numStudents);

    printf("After sorting in descending order based on marks:\n");
    displayStudents(students, numStudents);

    return 0;
}
 

 