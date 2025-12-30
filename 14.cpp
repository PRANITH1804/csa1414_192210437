#include <stdio.h>

int main() {
    printf("Given Grammar:\n");
    printf("S -> (L) | a\n");
    printf("L -> L , S | S\n\n");

    printf("Eliminating Left Recursion...\n\n");

    printf("New Grammar:\n");
    printf("S  -> (L) | a\n");
    printf("L  -> S L'\n");
    printf("L' -> , S L' | e\n");

    return 0;
}
