/*
Write a C program that uses functions to perform the following operations: 
     i) Reading a complex number 
     ii) Writing a complex number 
     iii) Addition of two complex numbers 
     iv) Multiplication of two complex numbers 
  (Note: represent complex number using a structure.
*/

#include <stdio.h>

struct Complex {
    double real;
    double imaginary;
};

struct Complex readComplex() {
    struct Complex c;
    printf("Enter the real part: ");
    scanf("%lf", &c.real);
    printf("Enter the imaginary part: ");
    scanf("%lf", &c.imaginary);
    return c;
}

void writeComplex(struct Complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imaginary);
}

struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex sum;
    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;
    return sum;
}

struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex product;
    product.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    product.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return product;
}

int main() {
    struct Complex num1, num2, sum, product;

    // Read the first complex number
    printf("Reading the first complex number:\n");
    num1 = readComplex();

    // Read the second complex number
    printf("Reading the second complex number:\n");
    num2 = readComplex();

    printf("\nFirst complex number:\n");
    writeComplex(num1);
    printf("Second complex number:\n");
    writeComplex(num2);

    sum = addComplex(num1, num2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("Product of the complex numbers:\n");
    writeComplex(product);

    return 0;
}
