/*
1. Write a program to swap every alternate element of a given array starting for element 0
For example, let's say we have a[5] = {10, 20, 30, 40, 50}, the result should be a[5] = {30, 20, 10, 40, 50}
one more example a[5] = {10, 20, 30, 40, 50, 60}, the result should be a[5] = {30, 20, 10, 60, 50, 40}

Topics to be covered
- Arrays
- Loops
- Basic Operators
*/
#include <stdio.h>

void swapAlternateElements(int arr[], int length) {
    for (int i = 0; i < length - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 2];
        arr[i + 2] = temp;
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    swapAlternateElements(arr, length);

    printf("\nSwapped array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
