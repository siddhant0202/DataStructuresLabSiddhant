#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
//Print Linklist
void printLinklist(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
        printf("->");
    }
    printf("NULL");
}
//Insert node at beginning
void insertListAtBeginning(struct node **head,int data){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}
//Insert node at end
void insertListAtEnd(struct node **head,int data){
    struct node *newnode,*temp;
    temp = *head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newnode->data = data;
    temp->next = newnode;
}
//Insert node at specific location
void insertAtLoc(struct node **head,int Loc,int data){
    struct node *newnode,*temp,*prev;
    newnode = (struct node*)malloc(sizeof(struct node));
    int i=1;
    temp = *head;
    while(i<Loc){
        prev = temp;
        temp=temp->next;
        i++;
    }
    newnode->data = data;
    newnode->next = temp;
    prev->next = newnode;
}
//Function to concate Linklist and store it in 3rd one
void concatenateLists(struct node **head1, struct node **head2, struct node **head3) {
    struct node *temp1 = *head1;
    struct node *temp2 = *head2;

    // If the first list is empty, head3 should point to the second list
    if (*head1 == NULL) {
        *head3 = *head2;
        return;
    }

    // If the second list is empty, head3 should point to the first list
    if (*head2 == NULL) {
        *head3 = *head1;
        return;
    }

    // Copy the first list into head3
    struct node *temp3 = (struct node*)malloc(sizeof(struct node));
    if (temp3 == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp3->data = temp1->data;
    temp3->next = NULL;
    *head3 = temp3;
    temp1 = temp1->next;

    // Copy the rest of the first list
    while (temp1 != NULL) {
        temp3->next = (struct node*)malloc(sizeof(struct node));
        temp3 = temp3->next;
        temp3->data = temp1->data;
        temp3->next = NULL;
        temp1 = temp1->next;
    }

    // Copy the second list
    while (temp2 != NULL) {
        temp3->next = (struct node*)malloc(sizeof(struct node));
        temp3 = temp3->next;
        temp3->data = temp2->data;
        temp3->next = NULL;
        temp2 = temp2->next;
    }
}
//Deletion
void deleteFromBeginning(struct node **head) {
    if (*head == NULL) {  
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);  
}
void deleteAtPosition(struct node **head, int position) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct node *target = temp->next;
    temp->next = target->next;
    free(target);
}
void deleteFromEnd(struct node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}
int main(){
    struct node *head = NULL;
    struct node *headA = NULL;
    struct node *headB = NULL;
    insertListAtBeginning(&head,23);
    insertListAtBeginning(&head,34);
    insertListAtEnd(&head,4);
    insertAtLoc(&head,2,67);
    printLinklist(head);
    printf("\n");
    insertListAtBeginning(&headA,89);
    insertListAtBeginning(&headA,313);
    insertListAtBeginning(&headA,9);
    printLinklist(headA);
    printf("\n");
    concatenateLists(&head,&headA,&headB);
    printLinklist(headB);
    printf("\n");
}