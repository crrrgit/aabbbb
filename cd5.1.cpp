//Program to Count total number of Operators in an Expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char expression[100];
    int i, count = 0;

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    for (i = 0; i < strlen(expression); i++) {
        if (expression[i] == '+' || expression[i] == '-' || 
            expression[i] == '*' || expression[i] == '/' || 
            expression[i] == '%' || expression[i] == '=' || 
            expression[i] == '<' || expression[i] == '>' || 
            expression[i] == '&' || expression[i] == '|' || 
            expression[i] == '!' || expression[i] == '^' || 
            (expression[i] == '+' && expression[i + 1] == '+') || 
            (expression[i] == '-' && expression[i + 1] == '-') || 
            (expression[i] == '&' && expression[i + 1] == '&') || 
            (expression[i] == '|' && expression[i + 1] == '|')) {

            count++;

            // If it's a double-character operator, skip the next character
            if (expression[i] == '+' && expression[i + 1] == '+') i++;
            if (expression[i] == '-' && expression[i + 1] == '-') i++;
            if (expression[i] == '&' && expression[i + 1] == '&') i++;
            if (expression[i] == '|' && expression[i + 1] == '|') i++;
        }
    }

    printf("Total number of operators: %d\n", count);

    return 0;
}
