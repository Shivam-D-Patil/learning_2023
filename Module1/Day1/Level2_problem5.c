/*
Write a function to find the type of the character passed
    - 'A' to 'Z', return 1
    - 'a; to 'z', return 2
    - '0' to '9', return 3
    - Any Other printable symbols, return 4
    - Non printable symbols, return 5 
*/
 #include <stdio.h>

int getCharType(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return 1;  // Uppercase alphabets
    } else if (ch >= 'a' && ch <= 'z') {
        return 2;  // Lowercase alphabets
    } else if (ch >= '0' && ch <= '9') {
        return 3;  // Digits
    } else if (ch >= 32 && ch <= 126) {
        return 4;  // Other printable symbols
    } else {
        return 5;  // Non-printable symbols
    }
}

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    int charType = getCharType(ch);

    switch (charType) {
        case 1:
            printf("Type: Uppercase Alphabet\n");
            break;
        case 2:
            printf("Type: Lowercase Alphabet\n");
            break;
        case 3:
            printf("Type: Digit\n");
            break;
        case 4:
            printf("Type: Other Printable Symbol\n");
            break;
        case 5:
            printf("Type: Non-Printable Symbol\n");
            break;
        default:
            printf("Invalid character\n");
            break;
    }

    return 0;
}
