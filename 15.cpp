#include <stdio.h>

int main() {
    printf("Given Grammar:\n");
    printf("S -> iEtS | iEtSeS | a\n");
    printf("E -> b\n\n");

    printf("After Left Factoring:\n\n");

    printf("S  -> iEtS S' | a\n");
    printf("S' -> eS | e\n");
    printf("E  -> b\n");

    return 0;
}
