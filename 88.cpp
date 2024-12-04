//program to find FIRST of any Grammar 


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

// Function to calculate FIRST
void findFirst(char result[], char grammar[][MAX], char nonTerminal, int n) {
    for (int i = 0; i < n; i++) {
        if (grammar[i][0] == nonTerminal) { // Match the non-terminal
            for (int j = 3; grammar[i][j] != '\0'; j++) {
                char symbol = grammar[i][j];
                if (islower(symbol) || symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
                    // Add terminal to FIRST set
                    if (strchr(result, symbol) == NULL) { // Avoid duplicates
                        strncat(result, &symbol, 1);
                    }
                    break; // Stop after adding terminal
                } else if (isupper(symbol)) {
                    // If it's a non-terminal, recursively find its FIRST
                    char temp[MAX] = "";
                    findFirst(temp, grammar, symbol, n);
                    for (int k = 0; temp[k] != '\0'; k++) {
                        if (strchr(result, temp[k]) == NULL) { // Avoid duplicates
                            strncat(result, &temp[k], 1);
                        }
                    }
                    break; // Stop for simplicity, assuming no epsilon (for now)
                } else if (symbol == '|') {
                    continue; // Skip '|' and check next production
                }
            }
        }
    }
}

int main() {
    int n;
    char grammar[MAX][MAX], nonTerminal, result[MAX] = "";

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions (e.g., A=aB|c):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", grammar[i]);
    }

    printf("Enter the non-terminal to find FIRST: ");
    scanf(" %c", &nonTerminal);

    findFirst(result, grammar, nonTerminal, n);

    printf("FIRST(%c) = { ", nonTerminal);
    for (int i = 0; result[i] != '\0'; i++) {
        printf("%c ", result[i]);
    }
    printf("}\n");

    return 0;
}

