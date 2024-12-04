#include <stdio.h>
#include <string.h>

int main() {
   char keyword[32][10] = {
      "auto", "double", "int", "struct", "break", "else", "long",
      "switch", "case", "enum", "register", "typedef", "char",
      "extern", "return", "union", "const", "float", "short",
      "unsigned", "continue", "for", "signed", "void", "default",
      "goto", "sizeof", "volatile", "do", "if", "static", "while"
   };
   char str[20]; // String to hold user input
   int flag = 0;

   printf("Enter a keyword: ");
   scanf("%s", str); // Take user input

   for (int i = 0; i < 32; i++) {
      if (strcmp(str, keyword[i]) == 0) {
         flag = 1;
         break; // Exit loop if a match is found
      }
   }

   if (flag == 1)
      printf("%s is a keyword\n", str);
   else
      printf("%s is not a keyword\n", str);

   return 0;
}

