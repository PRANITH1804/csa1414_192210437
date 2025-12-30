#include <stdio.h>
#include <string.h>

int main() {
    char line[200];

    printf("Enter a line of code:\n");
    fgets(line, sizeof(line), stdin);

    // Remove newline character
    line[strcspn(line, "\n")] = '\0';

    // Check for single-line comment
    if (line[0] == '/' && line[1] == '/') {
        printf("The given line is a Single-line comment.\n");
    }
    // Check for multi-line comment
    else if (line[0] == '/' && line[1] == '*') {
        int len = strlen(line);
        if (line[len - 2] == '*' && line[len - 1] == '/') {
            printf("The given line is a Multi-line comment.\n");
        } else {
            printf("The given line is a Multi-line comment (not closed).\n");
        }
    }
    else {
        printf("The given line is NOT a comment.\n");
    }

    return 0;
}
