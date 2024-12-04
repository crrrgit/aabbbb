#include<stdio.h>
#include<ctype.h>
#include<string.h>

int isKeyword(const char *str) {
	const char *keywords[] = {
	"auto", "break", "const", "case", "char", "continue", "default", "do", 
	"double", "ennum", "else", "extern", "for", "float", "goto", "if",
	"int", "long", "return", "register", "short", "signed" , "sizeof",
	"stuct", "static", "switch",  "typedef", "union", "unsigned", "void",
	"volatile", "while","",
	};
	int numKeywords = sizeof(keywords)/sizeof(keywords[0]);
	for(int i=0;i<numKeywords;i++){
		if(strcmp(str,keywords[i])==0){
			return 1; //string is key word
		}
	}
	return 0;
}

int isvalidIdentifier(const char *str){
	if(str==NULL || str[0]=='\0')
	{
		return 0;
	}
	if(!isalpha(str[0]) && str[0] != '_')
	{
		return 0;
	}
	for(int i= 1;str[i]!='\0';i++){
		if(!isalnum(str[i]) && str[i]!='_'){
			return 0;
		}
	}
	if (isKeyword(str))
	{
		return 0;
	}
	return 1;
}
int main() {
    char identifier[100];
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isvalidIdentifier(identifier)) {
        printf("\"%s\" is a valid identifier.\n", identifier);
    } else {
        printf("\"%s\" is not a valid identifier.\n", identifier);
    }

    return 0;
}
