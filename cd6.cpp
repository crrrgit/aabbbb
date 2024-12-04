#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "inline", "int", "long", "register", "restrict", "return",
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while", 
};
#define NUM_KEYWORDS (sizeof(keywords) / sizeof(keywords[0]))

// Function to check if a word is a keyword
int is_keyword(const char *word) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to count keywords in a given string
int count_keywords(const char *str) {
    char buffer[1024];
    strcpy(buffer, str); // Copy input string to a buffer to tokenize
    char *token = strtok(buffer, " \t\n.,;(){}[]<>!?");
    int count = 0;

    while (token != NULL) {
        if (is_keyword(token)) {
            count++;
        }
        token = strtok(NULL, " \t\n.,;(){}[]<>!?");
    }

    return count;
}

int main() {
    char input[1024];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    int keyword_count = count_keywords(input);
    printf("Total number of keywords in the string: %d\n", keyword_count);

    return 0;
}

