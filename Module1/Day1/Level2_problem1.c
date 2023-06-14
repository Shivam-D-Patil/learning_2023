/*
Write a function to return the greatest of 3 number using if else if.  
*/
#include <stdio.h>

int findGreatest(int a, int b, int c) {
    if (a > b && a > c) {
        return a;
    } else if (b > a && b > c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int a, b, c;

    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Enter the third number: ");
    scanf("%d", &c);

    int greatest = findGreatest(a, b, c);
    printf("The greatest number is: %d\n", greatest);

    return 0;
}
