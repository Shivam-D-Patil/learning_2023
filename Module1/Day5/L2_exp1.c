/*
Data Parser:
   A data logger transmits the data in ascii format as shown below
   "S1-T:36.5-H:100-L:50"
   Write a function to populate all the data in an array of structure. The output should be like
   Sensor Info:
   ---------------------
   Sensor ID: S1
   Temperature: 36.5 C
   Humidity: 100
   Light Intensity: 50%
*/

#include <stdio.h>
#include <string.h>

#define MAX_DATA_SIZE 100

 
struct SensorInfo {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
}; 
void populateSensorInfo(struct SensorInfo* sensorArray, const char* dataString, int arraySize) {
    int i = 0;
    const char* delimiter = "-";

    char* token = strtok(dataString, delimiter);
    while (token != NULL && i < arraySize) {
        sscanf(token, "S%s-T:%f-H:%d-L:%d", sensorArray[i].sensorID, &sensorArray[i].temperature,
               &sensorArray[i].humidity, &sensorArray[i].lightIntensity);

        token = strtok(NULL, delimiter);
        i++;
    }
}
 
void displaySensorInfo(const struct SensorInfo* sensorArray, int arraySize) {
    printf("Sensor Info:\n");
    printf("---------------------\n");

    for (int i = 0; i < arraySize; i++) {
        printf("Sensor ID: %s\n", sensorArray[i].sensorID);
        printf("Temperature: %.1f C\n", sensorArray[i].temperature);
        printf("Humidity: %d\n", sensorArray[i].humidity);
        printf("Light Intensity: %d%%\n", sensorArray[i].lightIntensity);
        printf("---------------------\n");
    }
}

int main() {
    char data[MAX_DATA_SIZE] = "S1-T:36.5-H:100-L:50";
    int numSensors = 1;
 
    struct SensorInfo sensorArray[numSensors];
 
    populateSensorInfo(sensorArray, data, numSensors);
 
    displaySensorInfo(sensorArray, numSensors);

    return 0;
}
