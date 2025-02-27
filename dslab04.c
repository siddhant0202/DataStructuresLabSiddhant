 #include <stdio.h>
 #include <stdlib.h>


//Node Structure for containing data and address...
 struct Node{
    int data;
    struct Node *next;
 }*first=NULL, *second = NULL;     //first pointer we will store address..


//we will pass array elements and size for creating linked list.
void create(int arr[],int n){
   
   int i;   //for scanning through the array.
   struct Node* t,*last;
   
   //Lets create a first node.
   first=(struct Node*)malloc(sizeof(struct Node));
   first->data=arr[0];                //assign the first data.
   first->next=NULL;

   last = first;
//start from i=1 beacuse zeroth element is already created.
   for(i=1;i<n;i++){

    t = (struct Node*)malloc(sizeof(struct Node)); //else use new Node in C++.
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
}
}

void create_2_(int arr[],int n){
   
   int i;   //for scanning through the array.
   struct Node* t,*last;
   
   //Lets create a second node.
   second=(struct Node*)malloc(sizeof(struct Node));
   second->data=arr[0];                //assign the second data.
   second->next=NULL;

   last = second;
//start from i=1 beacuse zeroth element is already created.
   for(i=1;i<n;i++){

    t = (struct Node*)malloc(sizeof(struct Node)); //else use new Node in C++.
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
}
}

   //----------find length of linked list...------------
int len(struct Node *p){
    
   int length = 0;
   while(p!=NULL){
       p = p->next;
       length++;
   }

   return length;
}

   void Display(struct Node *p){

    while(p!= NULL){
        printf("%d ",p->data);
        p = p->next;
    }
   }

   //--------Inserting node in linked list..-------------
   void insert(int index,int x,int n){
      
   //create a new node
   struct Node *t = (struct Node *) malloc (sizeof(struct Node));
   //check if node position entered by user is less then n and greater than 1 else return none;
   if(index<0 || index > n) return;
   
    t->data = x;
   //if insertion is at beginning then just put the address of first node in new node's next
   // and point first to new node.
   if(index == 0){
        t->next = first;
        first = t;
   }

   //else move a pointer upto the desired position.
   else{
   struct Node *p = first;
   for(int i=1; i<index;i++){
     p = p->next;
   }
   t->next = p->next;  //put the address of next node in new node's next
   p->next = t;       //and add that node's address in the previous node's next.
 }
}
 

//-----------Delete Linked List nodes-------------
void _delete_(int index,int n){
   struct Node *p,*q = NULL;  //for deleting the node move two pointers..
   
   // Check if list is empty or index is invalid
   if(first == NULL || index < 1 || index > n) return;
   
   //if we have to delete the first node..
   //put the first address in that node and point first node to next node
   //then free that node.
   if(index == 1){
       p = first;
       first = p->next;
       free(p);
       return;  // Exit after deleting first node
   }
   
   //for deleting at particular location move the pointer from first node to that node.
   p = first;
   for(int i=1;i<index && p != NULL;i++){
         q = p;  //one q pointer will move 1 step behind the p..
         p = p->next;
   }
   
   // If p is NULL, the index was out of bounds
   if(p == NULL) return;
   
   //just add p->next in q->next --> put address of nexts->next in that node
   // and freep the node we are pointing to.
   q->next = p->next;
   free(p);
}



//------------concatinate link lists------------
void concat(){

   struct Node *p = first;
   while(p->next != NULL){
    p = p->next;
   }
   p->next = second; //point to next linked list after 1st ends.
   second = NULL;  // we can remove second pointer but don't use free(second).
}

 int main(){
   int n;
   printf("Enter the number of elements: ");
   scanf("%d",&n);
   int arr[n];
    
   printf("Enter the elements: ");
   for(int i=0;i<n;i++) scanf("%d",&arr[i]);

   create(arr,n);
   Display(first);

   // insert on beginning of linked list
   insert(0,23,len(first));
   printf("\nInserted node at beginning: ");
   Display(first);

   // for end
   printf("\nInserted a node at end: ");
   insert(len(first),50,len(first));
   Display(first);
   

   //for specific position..
   int x;
   printf("\nEnter value of data: ");
   scanf("%d",&x);

   int node_pos;
   printf("\nEnter node position: ");
   scanf("%d",&node_pos);

   printf("\nLinked List after insertion of element: ");
   insert(node_pos,x,len(first));
   Display(first);
   
   //-----deleting a node from linked list------
   int d;
   printf("\nEnter node number to delete: ");
   scanf("%d",&d);
   
   _delete_(d,len(first));
   printf("\n Linked List after deleting Node: ");
   Display(first);
   
   //----concatinating link lists------
   printf("\nEnter second Linked List: ");
   int b[n];
   for(int i=0;i<n;i++) scanf("%d",&b[i]);

   create_2_(b,n);
   
   printf("\nList after concatinating: ");
   concat();
   Display(first);

   
    return 0;
 }
