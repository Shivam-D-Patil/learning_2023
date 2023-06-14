/*
Write a function to accept an integer (32 bits) and operation type to do the following and return the result to main function.
    - Set 1st bit, if operation type is 1
    - Clear 31st bit, if operation type is 2
    - Toggle 16th bit, if operation type is 3
   You can consider the below function prototype,
    - bit_operations(int num, int oper_type);
*/
#include<stdio.h>

int bit_operations(int num, int oper_type) {
    switch (oper_type) {
        case 1:
            num |= 1 << 0;   // Set the 1st bit
            break;
        case 2:
            num &= ~(1 << 31);   // Clear the 31st bit
            break;
        case 3:
            num ^= 1 << 15;   // Toggle the 16th bit
            break;
        default:
            printf("Error: Invalid operation type.\n");
            break;
    }

    return num;
}

int main() {
    int number, operationType;
    printf("Enter an integer (32 bits): ");
    scanf("%d", &number);

    printf("Enter the operation type (1 for set, 2 for clear, 3 for toggle): ");
    scanf("%d", &operationType);

    int result = bit_operations(number, operationType);
    printf("Result: %d\n", result);

    return 0;
}
