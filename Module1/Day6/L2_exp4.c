/*
Write a program to pass a pointer to a structure as a parameter to a function and return back a pointer to structure 
   to the calling function after modifying the members of structure.
*/
#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void modifyPerson(struct Person* p) {
    printf("Enter the new name: ");
    scanf("%s", p->name);

    printf("Enter the new age: ");
    scanf("%d", &(p->age));
}

int main() {
    struct Person person;

    printf("Enter the name: ");
    scanf("%s", person.name);

    printf("Enter the age: ");
    scanf("%d", &person.age);

    printf("Original Data:\n");
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);

    modifyPerson(&person);

    printf("Modified Data:\n");
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);

    return 0;
}
