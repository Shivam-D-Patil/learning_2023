/*
Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };
    Write a function to initialize all members in the above array of structures
*/
#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudent(struct Student* student, const char* inputString) {
    sscanf(inputString, "%d %s %f", &(student->rollno), student->name, &(student->marks));
}

void displayStudent(const struct Student* student) {
    printf("Roll No: %d\n", student->rollno);
    printf("Name: %s\n", student->name);
    printf("Marks: %.2f\n", student->marks);
}

int main() {
    const char* inputString = "1001 Aron 100.00";
    struct Student student;

    initializeStudent(&student, inputString);
    displayStudent(&student);

    return 0;
}
