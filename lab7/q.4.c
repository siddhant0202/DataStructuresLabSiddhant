//4) Write a function to convert prefix expression into postfix expression.

#include <stdio.h>

#define MAX 100

// Stack to store postfix
char stack[MAX][MAX];
int top = -1;

void push(char expr[]) {
    int i = 0;
    top++;
    while (expr[i] != '\0') {
        stack[top][i] = expr[i];
        i++;
    }
    stack[top][i] = '\0';
}

void pop(char expr[]) {
    int i = 0;
    while (stack[top][i] != '\0') {
        expr[i] = stack[top][i];
        i++;
    }
    expr[i] = '\0';
    top--;
}

// Checking if character is operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int main() {
    char prefix[MAX];
    char ch;
    int i, length = 0;

    char op1[MAX], op2[MAX], temp[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    // Finding length
    while (prefix[length] != '\0') {
        length++;
    }

    // Scaning prefix
    for (i = length - 1; i >= 0; i--) {
        ch = prefix[i];

        if (isOperator(ch)) {
            pop(op1);
            pop(op2);

            int j = 0, k = 0;

            while (op1[k] != '\0') {
                temp[j++] = op1[k++];
            }

            k = 0;
            while (op2[k] != '\0') {
                temp[j++] = op2[k++];
            }

            temp[j++] = ch;
            temp[j] = '\0';

            push(temp);
        } else {
            // Operand
            temp[0] = ch;
            temp[1] = '\0';
            push(temp);
        }
    }

    printf("Postfix expression: %s\n", stack[top]);

    return 0;
}
