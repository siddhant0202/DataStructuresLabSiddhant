// 3) Implement a circular linked list by using singly linked list. Perform following operations on it: a) Insert b) Delete c) Print

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* nNode = (Node*)malloc(sizeof(Node));
    nNode->data = value;
    nNode->next = NULL;
    return nNode;
}

// Insert at end (circular list)
Node* insert(Node* tail, int value) {
    Node* nNode = createNode(value);

    if (tail == NULL) {
        nNode->next = nNode;
        return nNode;
    }

    nNode->next = tail->next;
    tail->next = nNode;
    return nNode; // return new tail
}

// Delete a node with specific value
Node* delete(Node* tail, int value) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    Node *curr = tail->next, *prev = tail;
    do {
        if (curr->data == value) {
            if (curr == tail && curr->next == tail) {
                free(curr);
                return NULL; // list becomes empty
            }
            if (curr == tail) tail = prev; // deleting tail node
            prev->next = curr->next;
            free(curr);
            return tail;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    printf("Value not found.\n");
    return tail;
}

void printList(Node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = tail->next;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

int main() {
    Node* tail = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Print\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            tail = insert(tail, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            tail = delete(tail, value);
            break;
        case 3:
            printList(tail);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
