/*
Rotate String
*/
#include <stdio.h>
#include <string.h>

void rotateString(char *str, int positions) {
    int length = strlen(str); 
    positions = positions % length; 
    for (int i = 0; i < positions; i++) {
        char temp = str[0];
        for (int j = 0; j < length - 1; j++) {
            str[j] = str[j + 1];
        }
        str[length - 1] = temp;
    }
}
int main() {
    char str[100];
    int positions;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter the number of positions to rotate: ");
    scanf("%d", &positions);

    rotateString(str, positions);

    printf("Rotated string: %s\n", str);

    return 0;
}
