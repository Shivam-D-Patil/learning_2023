/*
Write a program to find total number of bits set in a given array.
Say we have a array of 3 elements
a[3] = {0x1, 0xF4, 0x10001};
The total number of set bits in the given array is
1 bit in 0x01, 5 in 0xF4, 2 in 0x10001, so the total is 1 + 5 + 2 = 8 bits

Topics to be covered
- Arrays
- Loops
- Bitwise Operators
*/
#include <stdio.h>

// Function to count the number of set bits in a number
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int arr[] = {0x1, 0xF4, 0x10001};
    int length = sizeof(arr) / sizeof(arr[0]);

    int totalBits = 0;
    for (int i = 0; i < length; i++) {
        totalBits += countSetBits(arr[i]);
    }

    printf("The total number of set bits in the array is: %d\n", totalBits);

    return 0;
}

//taking input
/*
#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int arr[length];
    printf("Enter the array elements in hexadecimal format:\n");
    for (int i = 0; i < length; i++) {
        scanf("%x", &arr[i]);
    }

    int totalBits = 0;
    for (int i = 0; i < length; i++) {
        totalBits += countSetBits(arr[i]);
    }

    printf("The total number of set bits in the array is: %d\n", totalBits);

    return 0;
}

*/
