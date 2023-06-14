/*
3. Write a program to sum every alternate elements of a given array starting for element 0
For example, let's say we have a[5] = {10, 20, 30, 40, 50}, the result should be 10 + 30 + 50 = 90

Topics to be covered
- Arrays
- Loops
- Basic Operators
*/
#include <stdio.h>

void summation(int arr[], int length) {
    int sum = 0,i;
    for ( i = 0; i < length; i++) {
        sum = sum + arr[i];
        i++;
    }
    printf("Sum is: %d\n", sum);
}

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int arr[length],i;
    printf("Enter the array elements:\n");
    for ( i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    summation(arr, length);

    return 0;
}
