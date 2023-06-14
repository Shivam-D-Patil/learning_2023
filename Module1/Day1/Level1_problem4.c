/*
Write a simple calculator program which should accept inputs in the same order.
    - Operand 1
    - Operator
    - Operand 2
The order of scan should be same, for example, you should first scan in the following order.
printf("Enter Number1: );
Scan the first number form the user.
printf("Enter the operator: );
Scan the operator from the user.
printf("Enter Number2: );
Scan the second number form the user.
*/
#include<stdio.h>
int main()
{
    int operand1,operand2;
    char operator;
    printf("Enter Number 1 : \n");
    scanf("%d",&operand1);

    printf("Enter the operator : \n");
    scanf("  %c",&operator);

    printf("Enter Number 2 : \n");
    scanf("%d",&operand2);

    if(operator=='*'){
        printf("operation is multiplication so multiplication of two no is : %d",operand1*operand2);

    }
    else if (operator=='/')
    {
         printf("operation is dividation so dividation of two no is : %d",operand1/operand2);
    }
    else if (operator=='+')
    {
        printf("operation is addition so addition of two no is : %d",operand1+operand2);
    }
    else if (operator=='-')
    {
        printf("operation is substraction so subtraction of two no is : %d",operand1-operand2);
    }
    
return 0;
}

//using swirch case 
/*
#include<stdio.h>

int main()
{
    int operand1, operand2;
    char operator;

    printf("Enter Number 1: ");
    scanf("%d", &operand1);

    printf("Enter the operator: ");
    scanf(" %c", &operator);

    printf("Enter Number 2: ");
    scanf("%d", &operand2);

    int result;

    switch(operator)
    {
        case '+':
            result = operand1 + operand2;
            printf("Addition Result: %d\n", result);
            break;
        case '-':
            result = operand1 - operand2;
            printf("Subtraction Result: %d\n", result);
            break;
        case '*':
            result = operand1 * operand2;
            printf("Multiplication Result: %d\n", result);
            break;
        case '/':
            if(operand2 != 0)
            {
                result = operand1 / operand2;
                printf("Division Result: %d\n", result);
            }
            else
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }

    return 0;
}

*/