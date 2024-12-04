//Program to Count total number of Vowels and Consonants in a String.
#include <stdio.h>
#include <ctype.h>
#include <string.h> // Include this for strcspn

void countVowelsAndConsonants(const char *str, int *vowelCount, int *consonantCount) {
    *vowelCount = 0;
    *consonantCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]); // Convert character to lowercase for uniformity
        if (ch >= 'a' && ch <= 'z') { // Check if it's an alphabet
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowelCount)++;
            } else {
                (*consonantCount)++;
            }
        }
    }
}

int main() {
    char str[1000];
    int vowels, consonants;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character added by fgets
    str[strcspn(str, "\n")] = '\0';

    countVowelsAndConsonants(str, &vowels, &consonants);

    printf("Total vowels: %d\n", vowels);
    printf("Total consonants: %d\n", consonants);

    return 0;
}


