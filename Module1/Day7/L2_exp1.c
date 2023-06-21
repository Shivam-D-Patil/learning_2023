/*
1. Sort the above "data.csv" based on the "Temperature" field in descending order

a. Use only file handling concepts

b. Use array of structures and file handling

 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[20];
} LogEntry;

void swapEntries(LogEntry *entries, int index1, int index2) {
    LogEntry temp = entries[index1];
    entries[index1] = entries[index2];
    entries[index2] = temp;
}

void sortEntriesByTemperature(LogEntry *entries, int numEntries) {
    int i, j;
    for (i = 0; i < numEntries - 1; i++) {
        for (j = 0; j < numEntries - i - 1; j++) {
            if (entries[j].temperature < entries[j + 1].temperature) {
                swapEntries(entries, j, j + 1);
            }
        }
    }
}

void swapLines(FILE *file, int lineIndex1, int lineIndex2) {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH]; 
    fseek(file, lineIndex1 * (MAX_LINE_LENGTH + 1), SEEK_SET);
    fgets(line1, MAX_LINE_LENGTH, file);

    fseek(file, lineIndex2 * (MAX_LINE_LENGTH + 1), SEEK_SET);
    fgets(line2, MAX_LINE_LENGTH, file);
 
    fseek(file, lineIndex1 * (MAX_LINE_LENGTH + 1), SEEK_SET);
    fputs(line2, file);

    fseek(file, lineIndex2 * (MAX_LINE_LENGTH + 1), SEEK_SET);
    fputs(line1, file);
}

void sortFileByTemperature() {
    FILE *file;
    char filename[] = "data.csv";
    char line[MAX_LINE_LENGTH];
    int numLines = 0;
    int i, j;
 
    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    } 
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        numLines++;
    } 
    for (i = 0; i < numLines - 1; i++) {
        for (j = 0; j < numLines - i - 1; j++) {
            float temp1, temp2;

            fseek(file, (j + 1) * (MAX_LINE_LENGTH + 1), SEEK_SET);
            fscanf(file, "%*[^,],%*[^,],%f", &temp1);

            fseek(file, j * (MAX_LINE_LENGTH + 1), SEEK_SET);
            fscanf(file, "%*[^,],%*[^,],%f", &temp2);

            if (temp1 > temp2) {
                swapLines(file, j, j + 1);
            }
        }
    } 
    fclose(file);
}

void writeEntriesToFile(LogEntry *entries, int numEntries) {
    FILE *file;
    char filename[] = "data.csv";
    int i; 
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    } 
    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,Timestamp\n");
    for (i = 0; i < numEntries; i++) {
        fprintf(file, "%d,%s,%.1f,%d,%d,%s\n",
                entries[i].entryNo, entries[i].sensorNo, entries[i].temperature,
                entries[i].humidity, entries[i].light, entries[i].timestamp);
    } 
    fclose(file);
}

int main() {
    LogEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    int i; 
    FILE *file;
    char filename[] = "data.csv";
    char line[MAX_LINE_LENGTH];
 
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    } 
    fgets(line, MAX_LINE_LENGTH, file); 
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]",
               &entries[numEntries].entryNo, entries[numEntries].sensorNo,
               &entries[numEntries].temperature, &entries[numEntries].humidity,
               &entries[numEntries].light, entries[numEntries].timestamp);
        numEntries++;
    }
 
    fclose(file); 
    sortEntriesByTemperature(entries, numEntries); 
    writeEntriesToFile(entries, numEntries); 
    printf("File sorted successfully.\n");
    return 0;
}
