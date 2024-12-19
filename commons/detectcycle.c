#include <stdio.h>
#include <stdlib.h>
int i,j;
typedef struct Node {
    int val;
    struct Node *next;
} node;

node *create_node(int value) {
    node *newe = (node *)malloc(sizeof(node));
    if (newe == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newe->val = value;
    newe->next = NULL;
    return newe;
}

void insert(node *head,int value){
  node*temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  node *newe=create_node(value);
  temp->next=newe;
  
}
int dectectcycle(node *head){
    node *s = head;
    node *f = head;

    while (f != NULL &&f->next!=NULL) {
        
        s = s->next;
        f = f->next->next;
        if(s==f)return 1;
    }

    return 0;
}




node *input() {
    int n;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The linked list must have at least one node.\n");
        return NULL;
    }

    printf("Enter the elements of the linked list:\n");
    int headValue;
    scanf("%d", &headValue);
    node *head = create_node(headValue);
    node *temp = head;

    for (int i = 1; i < n; i++) {
        int value;
        scanf("%d", &value);
        temp->next = create_node(value);
        temp = temp->next;
    }
    printf("enter the position where the last node is connected if no connection after end enter -1 : ");
    int k;
    scanf("%d",&k);
    if(k!=-1){
    node*temp1=head;
    for(i=0;i<k;i++){
      temp1=temp1->next;
    }
    printf("%d is connected again %d",temp->val,temp1->val);
    temp->next=temp1;
    return head;
}
}
void print(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
      node* head=input();
      if(dectectcycle(head))printf("\nCYCLIC\n");
      else printf("\nNOT CYCLIC");
}
