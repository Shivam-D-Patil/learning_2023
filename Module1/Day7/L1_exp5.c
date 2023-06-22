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
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int searchStudentByName(const struct Student* students, int numStudents, const char* name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;  
        }
    }
    return -1;  
}

void displayStudent(const struct Student* student) {
    printf("Roll No: %d\n", student->rollno);
    printf("Name: %s\n", student->name);
    printf("Marks: %.2f\n", student->marks);
}

int main() {
    struct Student students[] = {
        {1001, "Shivam", 100.00},
        {1002, "Vivek", 95.50},
        {1003, "Sanket", 87.75},
        {1004, "Manish", 92.25},
        {1005, "Partik", 80.50}
    };

    int numStudents = sizeof(students) / sizeof(struct Student);

    char searchName[20];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    int index = searchStudentByName(students, numStudents, searchName);

    if (index != -1) {
        printf("Student found!\n");
        printf("Student Details:\n");
        displayStudent(&students[index]);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}
