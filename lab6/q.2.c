// 1) Write a program to create and traverse a doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* nNode = (Node*)malloc(sizeof(Node));
    nNode->data = value;
    nNode->prev = NULL;
    nNode->next = NULL;
    return nNode;
}

// Function to create a doubly linked list with n nodes
Node* createList(int n) {
    Node *head = NULL, *temp = NULL, *nNode = NULL;
    int value, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        nNode = createNode(value);

        if (head == NULL) {
            head = nNode;
            temp = nNode;
        } else {
            temp->next = nNode;
            nNode->prev = temp;
            temp = nNode;
        }
    }

    return head;
}

void traverseF(Node* head) {
    Node* temp = head;
    printf("\nList in forward direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void traverseB(Node* head) {
    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nList in backward direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main() {
    Node* head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    traverseF(head);
    traverseB(head);

    return 0;
}
