#include <stdio.h>
#include <string.h>

#define MAX 10

int n; // number of productions
char productions[MAX][20]; // store grammar
char trailing[MAX][MAX];    // trailing sets
int tcount[MAX];           // count of elements in trailing set

// Function to check if terminal
int isTerminal(char c) {
    if (c == '+' || c == '*' || c == '(' || c == ')' || c == 'i') // 'i' represents id
        return 1;
    return 0;
}

// Function to add element to TRAILING set if not already present
void addTrailing(int index, char c) {
    for (int i = 0; i < tcount[index]; i++)
        if (trailing[index][i] == c)
            return; // already present
    trailing[index][tcount[index]++] = c;
}

int findNonTerminal(char c) {
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == c)
            return i;
    }
    return -1;
}

// Compute TRAILING sets
void computeTrailing() {
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < n; i++) {
            int len = strlen(productions[i]);
            for (int j = len - 1; j >= 3; j--) { // iterate from rightmost symbol
                char symbol = productions[i][j];

                if (isTerminal(symbol)) {
                    int prevCount = tcount[i];
                    addTrailing(i, symbol);
                    if (tcount[i] > prevCount)
                        changed = 1;
                    break; // only consider last symbol
                } else { // non-terminal
                    int ntIndex = findNonTerminal(symbol);
                    for (int k = 0; k < tcount[ntIndex]; k++) {
                        int prevCount = tcount[i];
                        addTrailing(i, trailing[ntIndex][k]);
                        if (tcount[i] > prevCount)
                            changed = 1;
                    }

                    // If previous symbol is also non-terminal, can consider it
                    // optional for complex grammars
                    break;
                }
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    getchar(); // consume newline

    printf("Enter productions (e.g., E->E+T):\n");
    for (int i = 0; i < n; i++)
        fgets(productions[i], 20, stdin);

    // remove newline
    for (int i = 0; i < n; i++)
        productions[i][strcspn(productions[i], "\n")] = 0;

    // initialize counts
    for (int i = 0; i < n; i++)
        tcount[i] = 0;

    computeTrailing();

    printf("\nTRAILING sets:\n");
    for (int i = 0; i < n; i++) {
        printf("TRAILING(%c) = { ", productions[i][0]);
        for (int j = 0; j < tcount[i]; j++)
            printf("%c ", trailing[i][j]);
        printf("}\n");
    }

    return 0;
}
