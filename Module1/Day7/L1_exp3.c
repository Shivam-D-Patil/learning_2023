/*
Data Viewer:
Write an application to view the log stored in data.csv
Example, say you have the following data in data.csv
------------------------------------
EntryNo,sensorNo,Temperature,Humidity,Light,
1,S1,36.5,100,50,10:30:50
2,S3,30,100,50,10:30:55
3,S2,-6.6,100,10,10:31:00
------------------------------------
a. Write a function to extract each line in the .csv file and store it in an array of structures. 
b. Also implement functions to display the contents of the array of structures.
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

void extractData(LogEntry logEntries[], int* numEntries) {
    FILE* file;
    char filename[] = "data.csv";
    char line[MAX_LINE_LENGTH];
    char* token;
    int entryCount = 0; 
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    } 
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (entryCount >= MAX_ENTRIES) {
            printf("Maximum number of entries exceeded.\n");
            break;
        } 
        line[strcspn(line, "\n")] = '\0';
        token = strtok(line, ",");
        if (token == NULL) {
            printf("Invalid line format: %s\n", line);
            continue;
        }
 
        logEntries[entryCount].entryNo = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Invalid line format: %s\n", line);
            continue;
        }
        strncpy(logEntries[entryCount].sensorNo, token, sizeof(logEntries[entryCount].sensorNo) - 1);
        logEntries[entryCount].sensorNo[sizeof(logEntries[entryCount].sensorNo) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Invalid line format: %s\n", line);
            continue;
        }
        logEntries[entryCount].temperature = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Invalid line format: %s\n", line);
            continue;
        }
        logEntries[entryCount].humidity = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Invalid line format: %s\n", line);
            continue;
        }
        logEntries[entryCount].light = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Invalid line format: %s\n", line);
            continue;
        }
        strncpy(logEntries[entryCount].timestamp, token, sizeof(logEntries[entryCount].timestamp) - 1);
        logEntries[entryCount].timestamp[sizeof(logEntries[entryCount].timestamp) - 1] = '\0';

        entryCount++;
    } 
    fclose(file); 
    *numEntries = entryCount;
}

void displayData(LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].timestamp);
    }
}
int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;
    extractData(logEntries, &numEntries);
    displayData(logEntries, numEntries);
    return 0;
}