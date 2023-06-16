/*
 Find the largest number by deleting single digit in a 4 digit number 5872 - 872, 9856 - 986

Concepts to be used.
- Loops
- Operators
*/
#include <stdio.h>

int find_largest_number(int num) {
    char num_str[5];  
    sprintf(num_str, "%d", num); 
    int largest_num = 0;

   
    for (int i = 0; i < 4; i++) {
       
        int j = 0;
        for (; j < i; j++)
            num_str[j] = num_str[j];
        for (; j < 3; j++)
            num_str[j] = num_str[j + 1];
        num_str[j] = '\0';

        int new_num = atoi(num_str);   
        if (new_num > largest_num)
            largest_num = new_num;
    }

    return largest_num;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    int largest = find_largest_number(num);
    printf("Largest number by deleting a single digit: %d\n", largest);

    return 0;
}
