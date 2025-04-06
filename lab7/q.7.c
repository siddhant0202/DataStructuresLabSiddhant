// 7) Using stack check whether string is palindrome or not?

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

// Function to check if string is a palindrome
int isPalindrome(char* str) {
    int i = 0, length = 0;

    // Finding length
    while (str[length] != '\0') {
        length++;
    }

    for (i = 0; i < length; i++) {
        push(str[i]);
    }

    // Comparing popped characters with original string
    for (i = 0; i < length; i++) {
        if (str[i] != pop()) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
