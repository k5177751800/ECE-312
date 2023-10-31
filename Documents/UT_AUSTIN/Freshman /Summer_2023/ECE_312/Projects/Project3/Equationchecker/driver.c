//Konghwan Shin
//ECE 312
//KS54897
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack312_arr.h"
#define MAX_ELEMENTS 80
//identifies what is missing
char rule(char c) {
    const char open[] = {')', ']', '>', '(', '[', '<'};
    const char close[] = {'(', '[', '<', ')', ']', '>'};
    const int numberRules = sizeof(open) / sizeof(open[0]);

    for (int i = 0; i < numberRules; i++) {
        if (c == open[i]) {
            return close[i];
        } else if (c == close[i]) {
            return open[i];
        }
    }
    return ' ';
}
//checks wether the function has the same pair
void check(const char *expression){
    Stack312 stack;
    makeStack(&stack);
    int expressionLength = strlen(expression);
    char NStack[MAX_ELEMENTS];
    int stackTop = -1;

    for (int i = 0; i < expressionLength; i++) {
        char NeChar = expression[i];

        switch (NeChar) {
            case '(':
            case '[':
            case '<':
                NStack[++stackTop] = NeChar;
                break;
            case ')':
            case ']':
            case '>':
                if (stackTop == -1 || NeChar != rule(NStack[stackTop])) {
                    printf("%s is missing ,%c, invalid\n", expression, (stackTop == -1 ? NeChar : rule(NStack[stackTop])));
                    return;
                }
                stackTop--;
                break;
        }
    }
    if (stackTop == -1) {
        printf("%s is valid\n", expression);
    } else {
        printf("%s is missing ,%c, invalid\n", expression, rule(NStack[stackTop]));
    }

}

int main(int argc, char **argv){
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char line[MAX_ELEMENTS];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\r\n")] = '\0';
        check(line);
    }
    fclose(file);
    return 0;


}

