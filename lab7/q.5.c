// 5) Write an function to evaluate postfix expression using stack.

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        top++;
        stack[top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        return 0;
    }
}

// Checking if character is operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evalPostfix(char* postfix) {
    int i = 0;
    char ch;
    int op1, op2, result;

    while ((ch = postfix[i]) != '\0') {
        if (ch >= '0' && ch <= '9') {
            // Operand: convert char to int and push
            push(ch - '0');
        } else if (isOperator(ch)) {
            // Operator: pop two operands and apply operation
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }
        i++;
    }

    return pop();
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression (e.g., 53+82-*): ");
    scanf("%s", postfix);

    int result = evalPostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
