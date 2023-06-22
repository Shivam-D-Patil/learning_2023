
/*
Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };
    Write a function to display all members in the above array of structures
*/
#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(const struct Student* students, int numStudents) {

    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

int main() {
    
    struct Student students[] = {
        {1001, "Aron", 100.00},
        {1002, "Bob", 95.50},
        {1003, "Charlie", 87.75}
    };

    int numStudents = sizeof(students) / sizeof(struct Student);

    displayStudents(students, numStudents);

    return 0;
}
