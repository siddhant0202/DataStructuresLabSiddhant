
// 6) Write a program using stack to check whether parenthesis are balanced?

#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        top++;
        stack[top] = ch;
    } else {
        printf("Stack overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        return '\0'; // Stack underflow
    }
}

// Checking if pair is matching
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

// Function
int areBalanced(char* expr) {
    int i = 0;
    char ch, popped;

    while ((ch = expr[i]) != '\0') {
        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            popped = pop();
            if (!isMatching(popped, ch)) {
                return 0; // Not balanced
            }
        }
        i++;
    }

    if (top == -1) {
        return 1;
    } else {
        return 0; 
    }
}

int main() {
    char expr[MAX];

    printf("Enter expression with brackets: ");
    scanf("%s", expr);

    if (areBalanced(expr)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}
