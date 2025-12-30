#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Global variables */
char expr[50];
int tempCount = 1;

/* Function to generate new temporary variable */
void generateTemp(char op, char op1, char op2) {
    printf("t%d = %c %c %c\n", tempCount, op1, op, op2);

    /* Replace expression part with temp */
    expr[0] = 't';
    expr[1] = tempCount + '0';
    expr[2] = '\0';

    tempCount++;
}

int main() {
    int i, len;

    printf("Enter an arithmetic expression: ");
    scanf("%s", expr);

    len = strlen(expr);

    for (i = 0; i < len; i++) {
        if (expr[i] == '*' || expr[i] == '/' ||
            expr[i] == '+' || expr[i] == '-') {

            generateTemp(expr[i], expr[i - 1], expr[i + 1]);

            /* Shift expression */
            int j;
            for (j = i - 1; j < len - 2; j++)
                expr[j] = expr[j + 2];

            len -= 2;
            expr[len] = '\0';
            i = -1;   // restart scanning
        }
    }

    printf("Result stored in %s\n", expr);
    return 0;
}
