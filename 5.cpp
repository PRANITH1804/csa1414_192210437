#include <stdio.h>
#include <string.h>

#define MAX 10

int n; // number of productions
char productions[MAX][20]; // store grammar
char leading[MAX][MAX];    // leading sets
int lcount[MAX];           // count of elements in leading set

// Function to check if terminal
int isTerminal(char c) {
    if (c == '+' || c == '*' || c == '(' || c == ')' || c == 'i') // i represents id
        return 1;
    return 0;
}

// Function to add element to LEADING set if not already present
void addLeading(int index, char c) {
    for (int i = 0; i < lcount[index]; i++)
        if (leading[index][i] == c)
            return; // already present
    leading[index][lcount[index]++] = c;
}

int findNonTerminal(char c) {
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == c)
            return i;
    }
    return -1;
}

// Compute LEADING sets
void computeLeading() {
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < n; i++) {
            int len = strlen(productions[i]);
            for (int j = 3; j < len; j++) { // skip "E->"
                char symbol = productions[i][j];

                if (isTerminal(symbol)) {
                    int prevCount = lcount[i];
                    addLeading(i, symbol);
                    if (lcount[i] > prevCount)
                        changed = 1;
                    break; // only first symbol
                } else { // non-terminal
                    int ntIndex = findNonTerminal(symbol);
                    for (int k = 0; k < lcount[ntIndex]; k++) {
                        int prevCount = lcount[i];
                        addLeading(i, leading[ntIndex][k]);
                        if (lcount[i] > prevCount)
                            changed = 1;
                    }

                    // If next symbol is also present, consider it as per precedence
                    if (j + 1 < len && !isTerminal(productions[i][j + 1])) {
                        // optional for more complex grammars
                    }
                    break; // only consider first symbol in production
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
        lcount[i] = 0;

    computeLeading();

    printf("\nLEADING sets:\n");
    for (int i = 0; i < n; i++) {
        printf("LEADING(%c) = { ", productions[i][0]);
        for (int j = 0; j < lcount[i]; j++)
            printf("%c ", leading[i][j]);
        printf("}\n");
    }

    return 0;
}
