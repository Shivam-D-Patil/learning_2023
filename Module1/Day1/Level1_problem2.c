/*
Write a program to print the grade of the given student using if else if block
    - 90 to 100 -> "Grade A"
    - 75 to 89 -> "Grade B"
    - 60 to 74 -> "Grade C"
    - 50 to 59 -> "Grade D"
    - 0 to 49 -> "Grade F"
*/
#include <stdio.h>

int main() {
    int grade;
    char name;

    printf("Enter a student name: ");
    scanf(" %c", &name);

    printf("Enter a student marks: ");
    scanf("%d", &grade);

    if (grade >= 90 && grade <= 100) {
        printf("Grade of %c obtained as 'Grade A'\n", name);
    } else if (grade >= 75 && grade <= 89) {
        printf("Grade of %c obtained as 'Grade B'\n", name);
    } else if (grade >= 60 && grade <= 74) {
        printf("Grade of %c obtained as 'Grade C'\n", name);
    } else if (grade >= 50 && grade <= 59) {
        printf("Grade of %c obtained as 'Grade D'\n", name);
    } else if (grade >= 0 && grade <= 49) {
        printf("Grade of %c obtained as 'Grade F'\n", name);
    }

    return 0;
}
//using loop 
/*
#include <stdio.h>

char* calculateGrade(int score) {
    if (score >= 90 && score <= 100) {
        return "Grade A";
    } else if (score >= 75 && score <= 89) {
        return "Grade B";
    } else if (score >= 60 && score <= 74) {
        return "Grade C";
    } else if (score >= 50 && score <= 59) {
        return "Grade D";
    } else if (score >= 0 && score <= 49) {
        return "Grade F";
    } else {
        return "Invalid score";
    }
}

int main() {
    int studentScore;
    printf("Enter the student's score: ");
    scanf("%d", &studentScore);

    char* grade = calculateGrade(studentScore);
    printf("The student's grade is: %s\n", grade);

    return 0;
}
*/

