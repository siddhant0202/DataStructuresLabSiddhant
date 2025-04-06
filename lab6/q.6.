// 6) Merge two sorted linked list into one and sort them again.

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

Node* insertEnd(Node* head, int value) {
    Node* nNode = createNode(value);

    if (head == NULL) {
        return nNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nNode;
    return head;
}

// Merge two sorted lists and return a sorted merged list
Node* mergeSorted(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* merged = NULL;
    Node** lastPtr = &merged;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            *lastPtr = head1;
            head1 = head1->next;
        } else {
            *lastPtr = head2;
            head2 = head2->next;
        }
        lastPtr = &((*lastPtr)->next);
    }

    if (head1 != NULL) *lastPtr = head1;
    if (head2 != NULL) *lastPtr = head2;

    return merged;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head1 = NULL, *head2 = NULL;
    int n1, n2, val;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter sorted value %d: ", i + 1);
        scanf("%d", &val);
        head1 = insertEnd(head1, val);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter sorted value %d: ", i + 1);
        scanf("%d", &val);
        head2 = insertEnd(head2, val);
    }

    printf("\nList 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    Node* merged = mergeSorted(head1, head2);
    printf("\nMerged Sorted List: ");
    printList(merged);

    return 0;
}
