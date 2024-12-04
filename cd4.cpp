// Program to Count total number of Words, Blank spaces in a String 
#include <stdio.h>

int main() {
    char str[1000];
    int words = 0, spaces = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            spaces++;
        } else if ((i == 0 || str[i - 1] == ' ') && str[i] != '\n') {
            words++;
        }
    }

    printf("Total words: %d\n", words);
    printf("Total spaces: %d\n", spaces);

    return 0;
}

