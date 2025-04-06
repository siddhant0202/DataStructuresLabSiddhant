// 4) Implement a circular linked list by using doubly linked list. Perform following operations on it: a) Insert b) Delete c) Print

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
    nNode->prev = nNode->next = NULL;
    return nNode;
}

Node* insert(Node* head, int value) {
    Node* nNode = createNode(value);

    if (head == NULL) {
        nNode->next = nNode;
        nNode->prev = nNode;
        return nNode;
    }

    Node* tail = head->prev;

    tail->next = nNode;
    nNode->prev = tail;
    nNode->next = head;
    head->prev = nNode;

    return head;
}

// Delete node with given value
Node* delete(Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    Node* curr = head;
    do {
        if (curr->data == value) {
            if (curr->next == curr && curr->prev == curr) {
                free(curr);
                return NULL; // list becomes empty
            }

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            if (curr == head) head = curr->next;

            free(curr);
            return head;
        }
        curr = curr->next;
    } while (curr != head);

    printf("Value not found.\n");
    return head;
}

//Printing in Forward Direction
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Print\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            head = insert(head, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            head = delete(head, value);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
