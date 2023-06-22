/*
Diff between even & odd indexed elements
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int *array;
    int evenSum = 0, oddSum = 0, diff;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            evenSum += array[i];
        } else {
            oddSum += array[i];
        }
    }
    diff = evenSum - oddSum;
    printf("Difference between even-indexed and odd-indexed elements: %d\n", diff);
    free(array);
    return 0;
}
