//Program to find FOLLOW of any Grammar 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char productions[MAX][MAX]; // Grammar productions
int numProductions;

// Function to compute FOLLOW
void findFollow(char result[], char nonTerminal) {
    if (nonTerminal == productions[0][0]) // Start symbol gets '$'
        strcat(result, "$");

    for (int i = 0; i < numProductions; i++) {
        char *prod = productions[i];
        for (int j = 3; prod[j] != '\0'; j++) {
            if (prod[j] == nonTerminal) {
                if (prod[j + 1] != '\0') { // Add FIRST of next symbol
                    if (islower(prod[j + 1]) || strchr("()+-*/", prod[j + 1]))
                        strncat(result, &prod[j + 1], 1);
                } else if (prod[0] != nonTerminal) { // Add FOLLOW of head
                    findFollow(result, prod[0]);
                }
            }
        }
    }
}

int main() {
    char followResult[MAX] = "";
    char nonTerminal;

    printf("Enter number of productions: ");
    scanf("%d", &numProductions);

    printf("Enter productions (e.g., A=aB|c):\n");
    for (int i = 0; i < numProductions; i++) {
        scanf("%s", productions[i]);
    }

    printf("Enter the non-terminal to find FOLLOW: ");
    scanf(" %c", &nonTerminal);

    findFollow(followResult, nonTerminal);

    printf("FOLLOW(%c) = { %s }\n", nonTerminal, followResult);

    return 0;
}

