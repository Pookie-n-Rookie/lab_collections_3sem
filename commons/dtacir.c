#include<stdio.h>
#include<stdlib.h>


typedef struct node{
   int val;
   struct node* prev;
   struct node* next;
}node;


node*  create(int value){
  node* nn=(node*)malloc(sizeof(node));
  nn->val=value;
  nn->next=NULL;
  nn->prev=NULL;
}

void insert(node* head,int value){
      node* temp=head;
      while(temp->next!=head){
        temp=temp->next;
      }
      node*newn=(node*)malloc(sizeof(node));
      newn->val=value;
      temp->next=newn;
      newn->prev=temp;
      newn->next=head;
      head->prev=newn;
}
node *input() {
    int n;
    printf("Enter the size of the doubly linked list: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The linked list must have at least one node.\n");
        return NULL;
    }

    printf("Enter the elements of the linked list:\n");
    int headValue;
    scanf("%d", &headValue);
    node *head = create(headValue);
    node *temp = head;

    for (int i = 1; i < n; i++) {
        int value;
        scanf("%d", &value);
        temp->next = create(value);
        temp->next->prev=temp;
        temp = temp->next;
    }
    temp->next=head;
    head->prev=temp;

    return head;
}
void print(node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    node* temp = head;
    do {
        printf("%d <-> ", temp->val);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head: %d)\n", head->val);
}


int main(){
node* head1=input();
print(head1);
int v;
printf("enter the value to be pushed at the end of CLL :");
scanf("%d",&v);
insert(head1,v);
print(head1);
}

