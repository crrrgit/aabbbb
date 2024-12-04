//Program to perform Shift Reduce Parsing for 

#include <stdio.h>
#include <string.h>

#define MAX 50
#define STACK_SIZE 100

const char* grammar[3][2] = {
    {"S", "aA"},
    {"A", "b"},
    {"A", "c"}
};

char stack[STACK_SIZE];
int top = -1;
char input[MAX];
int input_pos = 0;

void shift() {
    if (input_pos < strlen(input)) {
        stack[++top] = input[input_pos++];
        printf("Shift: Stack = ");
        for (int i = 0; i <= top; i++) printf("%c ", stack[i]);
        printf("\n");
    }
}

int reduce() {
    for (int i = 0; i < 3; i++) {
        int len = strlen(grammar[i][1]);
        if (top >= len - 1 && strncmp(&stack[top - len + 1], grammar[i][1], len) == 0) {
            top -= len - 1;
            stack[++top] = grammar[i][0][0];
            printf("Reduce: Stack = ");
            for (int j = 0; j <= top; j++) printf("%c ", stack[j]);
            printf("\n");
            return 1;
        }
    }
    return 0;
}

void parse() {
    while (input_pos < strlen(input)) {
        if (!reduce()) shift();
        if (top == 0 && stack[0] == 'S' && input_pos == strlen(input)) {
            printf("Input string parsed successfully.\n");
            return;
        }
    }
    printf("Parsing failed.\n");
}

int main() {
    printf("Enter the input string: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0';
    parse();
    return 0;
}

