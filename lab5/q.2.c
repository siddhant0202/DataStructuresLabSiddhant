#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


void printList(struct node* head) {
    // printf("[");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    // printf("]");
}

struct node* createnode(int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

struct node* append(struct node* head, int new_data) {

    struct node* new_node = createnode(new_data);

    if (head == NULL) {
        return new_node;
    }

    struct node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    return head;
}



void freq(struct node* head) {
    struct node* outer = head;
    struct node* inner;
    int visited[1000] = {0}; 
    int found;

    while (outer != NULL) {
        if (visited[outer->data] == 0) {
            int count = 0;
            inner = head;

            while (inner != NULL) {
                if (inner->data == outer->data) {
                    count++;
                }
                inner = inner->next;
            }

            printf("\nElement %d: %d times\n", outer->data, count);

            visited[outer->data] = 1; 
        }
        outer = outer->next;
    }
}



int main() {
  
    int element;
    struct node *head = NULL;
    
    while(1){
        printf("Enter next element or -1 : ");
        scanf("%d", &element);
        
        if (element != -1){
            head = append(head,element);
            continue;
        }
        else{
            break;
        }
    }
    printf("\n\nYour enterted Linked List is : ");
    printList(head);
    freq(head);
    


    return 0;
}
