//program to identify whether a given Line is Comment or not 
#include <stdio.h>
#include <string.h>

int main() {
    char line[100]; // To store the input line
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin); // Read input, including spaces

    // Check for single-line comment
    if (strncmp(line, "//", 2) == 0) {
        printf("The line is a single-line comment.\n");
    }
    // Check for multi-line comment
    else if (strncmp(line, "/*", 2) == 0 && strstr(line, "*/") != NULL) {
        printf("The line is a multi-line comment.\n");
    }
    // Not a comment
    else {
        printf("The line is not a comment.\n");
    }

    return 0;
}
