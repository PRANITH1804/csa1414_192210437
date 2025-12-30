#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// List of keywords
char *keywords[] = {
    "int", "float", "char", "double", "if", "else", "while", "for", "return", "void"
};
int num_keywords = 10;

// Function to check if a string is a keyword
int isKeyword(char str[]) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, str[MAX];
    int i = 0;

    // Open input file
    fp = fopen("input.c", "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {

        // Skip whitespaces
        if (isspace(ch))
            continue;

        // Detect identifiers or keywords
        if (isalpha(ch) || ch == '_') {
            i = 0;
            str[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_'))
                str[i++] = ch;
            str[i] = '\0';
            if (ch != EOF)
                ungetc(ch, fp);

            if (isKeyword(str))
                printf("Keyword: %s\n", str);
            else
                printf("Identifier: %s\n", str);
        }

        // Detect numeric constants
        if (isdigit(ch)) {
            i = 0;
            str[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && isdigit(ch))
                str[i++] = ch;
            str[i] = '\0';
            if (ch != EOF)
                ungetc(ch, fp);
            printf("Numeric constant: %s\n", str);
        }

        // Detect operators
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ||
            ch == '<' || ch == '>' || ch == '%' || ch == '!') {
            printf("Operator: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
