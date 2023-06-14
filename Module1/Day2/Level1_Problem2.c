/*
2. Write a program to swap any type of data passed to an function.

Topics to be covered
- Pointers
- Type Casting
*/
#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char* ptr1 = (char*)a;
    char* ptr2 = (char*)b;

    while (size--) {
        char temp = *ptr1;
        *ptr1++ = *ptr2;
        *ptr2++ = temp;
    }
}

int main() {
    int x = 5;
    int y = 10;
    printf("Before swapping: x = %d, y = %d\n", x, y);

    swap(&x, &y, sizeof(int));

    printf("After swapping: x = %d, y = %d\n", x, y);

    double a = 3.14;
    double b = 2.71;
    printf("Before swapping: a = %lf, b = %lf\n", a, b);

    swap(&a, &b, sizeof(double));

    printf("After swapping: a = %lf, b = %lf\n", a, b);

    return 0;
}
