#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

bool isValid(char * s) {
    char *stack = malloc(strlen(s)), *top = stack, *p = s;
    for(; *p; p++) {
        if(*p=='(' || *p=='{' || *p=='[') {
            *top = *p;
            top++;
        }
        else if(
            top!=stack &&
            (
                (*p==')' && top[-1]=='(') ||
                (*p=='}' && top[-1]=='{') ||
                (*p==']' && top[-1]=='[')
            )
        ) top--;
        else return false;
    }
    if(top == stack) return true;
    else return false;
}