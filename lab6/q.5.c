// 5) Merge the given two circular linked list and merge them into a single circular linked list

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

// Merge two circular singly linked lists
Node* mergeCircularLists(Node* tail1, Node* tail2) {
    if (tail1 == NULL) return tail2;
    if (tail2 == NULL) return tail1;

    Node* head1 = tail1->next;
    Node* head2 = tail2->next;

    tail1->next = head2;
    tail2->next = head1;

    return tail2; // or tail1; either is fine as long as it's the new tail
}

int main() {
    Node *tail1 = NULL, *tail2 = NULL;
    int n1, n2, val, i;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        tail1 = insert(tail1, val);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        tail2 = insert(tail2, val);
    }

    printf("\nList 1: ");
    printList(tail1);
    printf("List 2: ");
    printList(tail2);

    Node* mergedTail = mergeCircularLists(tail1, tail2);
    printf("\nMerged Circular List: ");
    printList(mergedTail);

    return 0;
}
