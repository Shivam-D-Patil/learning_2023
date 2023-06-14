/*
Write a program to encode any given string such that it gets converted into an unrecognizable form. 
Also write a decode function to get back the original string.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *str, int shift) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' + shift) % 26 + 'A';
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

void decode(char *str, int shift) {
    encode(str, 26 - shift);
}

int main() {
    char str[100];
    int shift;

    printf("Enter a string to encode: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the shift value for encoding: ");
    scanf("%d", &shift);

    // Remove newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    encode(str, shift);
    printf("Encoded string: %s\n", str);

    decode(str, shift);
    printf("Decoded string: %s\n", str);

    return 0;
}
