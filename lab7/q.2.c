// 3) Implement stack using doubly LL.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* nNode = (Node*)malloc(sizeof(Node));
    if (!nNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    nNode->data = data;
    nNode->next = NULL;
    return nNode;
}

void push(Node** top, int data) {
    Node* nNode = createNode(data);
    nNode->next = *top;
    *top = nNode;
    printf("%d pushed to stack\n", data);
}

int isEmpty(Node* top) {
    return (top == NULL);
}

int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1;  
    }
    Node* temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
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

void display(Node* top) {
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
    display(stack);

    int poppedValue = pop(&stack);
    if (poppedValue != -1)
        printf("%d popped from stack\n", poppedValue);

    printf("Stack elements after pop:\n");
    display(stack);

    return 0;
}
