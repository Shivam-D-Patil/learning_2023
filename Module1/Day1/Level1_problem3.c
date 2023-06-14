/*
Write a program to read the 
    - Roll No
    - Name (Note, you should read full name of the student including initials)
    - Marks of Physics, Math and Chemistry
    Calculate the total, percentage and print the summary.
*/
#include <stdio.h>

int main() {
    int Roll_no, marks[3], i, total = 0;
    char name[20];
    float percentage;

    printf("Enter the roll no: ");
    scanf("%d", &Roll_no);

    printf("Enter the Name: ");
    scanf(" %s", name);

    printf("Enter the marks of Physics, Math, and Chemistry: ");
    for (i = 0; i < 3; i++) {
        scanf(" %d", &marks[i]);
        total += marks[i];
    }

    percentage = (float)(total * 100) / 300;

    printf("Roll No: %d\n", Roll_no);
    printf("Name: %s\n", name);
    printf("Total Marks Obtained: %d\n", total);
    printf("Total Percentage Obtained: %.2f\n", percentage);

    return 0;
}
