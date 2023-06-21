/*
File Copy: Write a C program to copy a file using file operations
*/

#include <stdio.h>
int main() {
    FILE *file1, *file2;
    char path1[100], path2[100];
    char ch;
    printf("Enter the path of the file1: ");
    scanf("%s", path1);
    printf("Enter the path of the file2: ");
    scanf("%s", path2);

    file1 = fopen(path1, "r");
    if (file1 == NULL) {
        printf("Unable to open file1.\n");
        return 1;
    }

    file2 = fopen(path2, "w");
    if (file2 == NULL) {
        printf("Unable to create file2.\n");
        fclose(file1);
        return 1;
    }

    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file2);
    }
    fclose(file1);
    fclose(file2);

    printf("Contents of file1 copied to file2 successfully.\n");

    return 0;
}
