// 3) Implement stack using doubly LL.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* nNode = (Node*)malloc(sizeof(Node));
    if (!nNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    nNode->data = data;
    nNode->next = NULL;
    nNode->prev = NULL;
    return nNode;
}
int isEmpty(Node* top) {
    return (top == NULL);
}

void push(Node** top, int data) {
    Node* nNode = createNode(data);
    if (*top == NULL) {
        *top = nNode;
    } else {
        nNode->next = *top;
        (*top)->prev = nNode;
        *top = nNode;
    }
    printf("%d pushed to stack\n", data);
}

int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1;  
    }
    Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    if (*top != NULL)
        (*top)->prev = NULL;
    free(temp);
    return popped;
}

int peek(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty! No element to peek.\n");
        return -1;  
    }
    return top->data;
}

void disp(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); 
}

int main() {
    Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(stack));

    printf("Stack elements are:\n");
    disp(stack);

    int poppedVal = pop(&stack);
    if (poppedVal != -1)
        printf("%d popped from stack\n", poppedVal);

    printf("Stack elements after pop:\n");
    disp(stack);

    return 0;
}
