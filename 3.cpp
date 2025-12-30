#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

int i = 0;
char input[50];

/* Function declarations */
void E();
void Eprime();
void T();
void Tprime();
void F();

void error() {
    printf("String is NOT accepted.\n");
    exit(0);
}

/* Match function */
void match(char expected) {
    if (input[i] == expected)
        i++;
    else
        error();
}

/* E ? T E' */
void E() {
    T();
    Eprime();
}

/* E' ? + T E' | e */
void Eprime() {
    if (input[i] == '+') {
        match('+');
        T();
        Eprime();
    }
}

/* T ? F T' */
void T() {
    F();
    Tprime();
}

/* T' ? * F T' | e */
void Tprime() {
    if (input[i] == '*') {
        match('*');
        F();
        Tprime();
    }
}

/* F ? ( E ) | id */
void F() {
    if (input[i] == '(') {
        match('(');
        E();
        match(')');
    }
    else if (input[i] == 'i' && input[i+1] == 'd') {
        match('i');
        match('d');
    }
    else {
        error();
    }
}

int main() {
    printf("Enter the input string: ");
    scanf("%s", input);

    E();

    if (input[i] == '\0')
        printf("String is ACCEPTED.\n");
    else
        printf("String is NOT accepted.\n");

    return 0;
}
