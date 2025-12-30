#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 20

int isOperator(char ch) {
    char operators[] = "+-*/%=<>&|!";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[MAX_ID_LEN];
    int i;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Cannot open input file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        /* Ignore spaces, tabs and newlines */
        if (isspace(ch))
            continue;

        /* Ignore single-line comments */
        if (ch == '/') {
            char next = fgetc(fp);
            if (next == '/') {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }
            /* Ignore multi-line comments */
            else if (next == '*') {
                while (1) {
                    ch = fgetc(fp);
                    if (ch == '*' && fgetc(fp) == '/')
                        break;
                }
                continue;
            } else {
                ungetc(next, fp);
            }
        }

        /* Identifier */
        if (isalpha(ch) || ch == '_') {
            i = 0;
            buffer[i++] = ch;

            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_')) {
                if (i < MAX_ID_LEN - 1)
                    buffer[i++] = ch;
            }
            buffer[i] = '\0';
            printf("Identifier: %s\n", buffer);
            ungetc(ch, fp);
        }

        /* Constant (Number) */
        else if (isdigit(ch)) {
            i = 0;
            buffer[i++] = ch;

            while ((ch = fgetc(fp)) != EOF && isdigit(ch)) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            printf("Constant: %s\n", buffer);
            ungetc(ch, fp);
        }

        /* Operator */
        else if (isOperator(ch)) {
            printf("Operator: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
