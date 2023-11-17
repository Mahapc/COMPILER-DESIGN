#include <stdio.h>
#include <ctype.h>
#include <string.h>
int isKeyword(char *str) {
    char keywords[][10] = {"int", "float", "char", "if", "else", "while", "for", "return"};
    int i;
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(keywords[i], str) == 0) {
            return 1; 
        }
    }
    return 0; 
}
int isOperator(char ch) {
    char operators[] = {'+', '-', '*', '/', '=', '<', '>', '&', '|', '!'};
    int i;
    for (i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
        if (operators[i] == ch) {
            return 1;
        }
    }
    return 0; 
}
int isDigit(char ch) {
    return isdigit(ch);
}
int isIdentifierChar(char ch) {
    return isalnum(ch) || ch == '_';
}
int main() {
    char input[100];
    printf("Enter C code:\n");
    fgets(input, sizeof(input), stdin);

    printf("\nScanning and Printing:\n");

    int i = 0;
    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
            continue;
        }
        if (isOperator(input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
            continue;
        }
        if (isDigit(input[i])) {
            printf("Digit: %c\n", input[i]);
            i++;
            continue;
        }
        if (isalpha(input[i]) || input[i] == '_') {
            int j = 0;
            char identifier[100];
            while (isIdentifierChar(input[i])) {
                identifier[j++] = input[i++];
            }
            identifier[j] = '\0';
            if (isKeyword(identifier)) {
                printf("Keyword: %s\n", identifier);
            } else {
                printf("Identifier: %s\n", identifier);
            }
            continue;
        }
        printf("Unknown: %c\n", input[i]);
        i++;
    }
    return 0;
}
