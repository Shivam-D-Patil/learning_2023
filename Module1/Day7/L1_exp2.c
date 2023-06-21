/*
ase Handler:
Write a C program to copy a file by considering the user option to handle the text case
-u, to change file content to Upper Case
-l, to change file content to Lower Case
-s, to change file content to Sentence Case
if no options are passed then it should be a normal copy
Example, say we have a file f1 with the following content
f1:
-----------------------
This is the file data
testing Case copy
application
-----------------------
./cp -s f1 f2
f2:
-----------------------
This Is The Tile Data
Testing Case Copy
Application
-----------------------
./cp -l f1 f3
f3:
-----------------------
this is the tile data
testing case copy
application
-----------------------
./cp -u f1 f4
f4:
-----------------------
THIS IS THE FILE DATA
TESTING CASE COPY
APPLICATION
-----------------------
./cp f1 f5
Should perform a normal copy
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void convertToUpper(FILE *source, FILE *destination) {
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}
void convertToLower(FILE *source, FILE *destination) {
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}
void convertToSentenceCase(FILE *source, FILE *destination) {
    char ch;
    int sentenceStart = 1;
    while ((ch = fgetc(source)) != EOF) {
        if (sentenceStart && isalpha(ch)) {
            fputc(toupper(ch), destination);
            sentenceStart = 0;
        } else {
            fputc(tolower(ch), destination);
            if (ch == '.' || ch == '?' || ch == '!') {
                sentenceStart = 1;
            }
        }
    }
}
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp [-u | -l | -s] source_file destination_file\n");
        return 1;
    }
    char *option = "";
    char *sourcePath = "";
    char *destinationPath = "";
 
    if (argc == 3) {
        sourcePath = argv[1];
        destinationPath = argv[2];
    } else if (argc == 4) {
        option = argv[1];
        sourcePath = argv[2];
        destinationPath = argv[3];
    }

    FILE *sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    FILE *destinationFile = fopen(destinationPath, "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (strcmp(option, "-u") == 0) {
        convertToUpper(sourceFile, destinationFile);
    } else if (strcmp(option, "-l") == 0) {
        convertToLower(sourceFile, destinationFile);
    } else if (strcmp(option, "-s") == 0) {
        convertToSentenceCase(sourceFile, destinationFile);
    } else {
        char ch;
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, destinationFile);
        }
    }
    fclose(sourceFile);
    fclose(destinationFile);
    printf("File copied successfully.\n");
    return 0;
}
