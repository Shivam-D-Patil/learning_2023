/*
Write a program to find both smallest and largest digits in given n numbers
For example let's say we have n = 3, and n1 = 8, n2 = 156, n3 = 123450, the result will be "Not Valid", 1 and 6, 0 and 5
*/

#include <stdio.h>

void find_smallest_largest_digits(int n, int numbers[]) {
    int smallest_digit = 9;
    int largest_digit = 0;
    for (int i = 0; i < n; i++) {
        int current_number = numbers[i];

        while (current_number > 0) {
            int digit = current_number % 10;
            if (digit < smallest_digit)
                smallest_digit = digit;
            if (digit > largest_digit)
                largest_digit = digit;
            current_number /= 10;
        }
    }
    if (smallest_digit == 9 && largest_digit == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest digit: %d\n", smallest_digit);
        printf("Largest digit: %d\n", largest_digit);
    }
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    find_smallest_largest_digits(n, numbers);
    return 0;
}
