/*
Suppose 7 names are stored in an array of pointers names[] as shown below:
 char *name[]={
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
          }
  Write a program to arrange these names in alphabetical order.
*/
#include <stdio.h>
#include <string.h>

void sortNames(char *names[], int length) {
    char *temp;
    int i, j;

    // Bubble sort algorithm
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the names
                temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

int main() {
    char *names[] = {
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
    };
    int length = sizeof(names) / sizeof(names[0]);

    printf("Original names:\n");
    for (int i = 0; i < length; i++) {
        printf("%s\n", names[i]);
    }

    sortNames(names, length);

    printf("\nSorted names:\n");
    for (int i = 0; i < length; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
