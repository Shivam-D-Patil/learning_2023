/*
Write a program to demonstrate the swapping the fields of two structures using pointers
*/

#include <stdio.h>
 
struct Person {
    char name[50];
    int age;
};
 
void swapFields(struct Person* p1, struct Person* p2) {
 
    char tempName[50];
    strcpy(tempName, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, tempName);

  
    int tempAge = p1->age;
    p1->age = p2->age;
    p2->age = tempAge;
}

int main() {
    struct Person person1, person2;
 
    printf("Enter the name of person1: ");
    scanf("%s", person1.name);
    printf("Enter the age of person1: ");
    scanf("%d", &person1.age);
 
    printf("Enter the name of person2: ");
    scanf("%s", person2.name);
    printf("Enter the age of person2: ");
    scanf("%d", &person2.age);
 
    printf("\nOriginal Data:\n");
    printf("Person1: %s, %d years old\n", person1.name, person1.age);
    printf("Person2: %s, %d years old\n", person2.name, person2.age);
 
    swapFields(&person1, &person2);
 
    printf("\nSwapped Data:\n");
    printf("Person1: %s, %d years old\n", person1.name, person1.age);
    printf("Person2: %s, %d years old\n", person2.name, person2.age);

    return 0;
}
