#include <stdio.h>

void first(char symbol) {
    if (symbol == 'A' || symbol == 'B') {
        printf("e ");
    }
    else if (symbol == 'S') {
        printf("a b ");
    }
}

int main() {
    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> e\n");
    printf("B -> e\n\n");

    printf("FIRST(A) = { ");
    first('A');
    printf("}\n");

    printf("FIRST(B) = { ");
    first('B');
    printf("}\n");

    printf("FIRST(S) = { ");
    first('S');
    printf("}\n");

    return 0;
}
