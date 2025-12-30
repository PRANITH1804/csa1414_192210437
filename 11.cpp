#include <stdio.h>

int main() {
    char result, op1, op2, op;

    printf("Enter Three Address Code (Example: t=a+b): ");
    scanf(" %c = %c %c %c", &result, &op1, &op, &op2);

    printf("\nTarget Code:\n");

    switch (op) {
        case '+':
            printf("MOV %c, R1\n", op1);
            printf("ADD %c, R1\n", op2);
            printf("MOV R1, %c\n", result);
            break;

        case '-':
            printf("MOV %c, R1\n", op1);
            printf("SUB %c, R1\n", op2);
            printf("MOV R1, %c\n", result);
            break;

        case '*':
            printf("MOV %c, R1\n", op1);
            printf("MUL %c, R1\n", op2);
            printf("MOV R1, %c\n", result);
            break;

        case '/':
            printf("MOV %c, R1\n", op1);
            printf("DIV %c, R1\n", op2);
            printf("MOV R1, %c\n", result);
            break;

        default:
            printf("Invalid operator\n");
    }

    return 0;
}
