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

node* insert(node *head,int value){
  if(head==NULL){
    head=create_node(value);
    return head ;
  }
  node*temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  node *newe=create_node(value);
  temp->next=newe;
  return head;
  
}

node*common(node*head1,node*head2){
  node *t1=head1;
  node *t2=head2;
  if(t1==NULL || t2==NULL)return NULL;
  while(t1!=t2){
    t1=t1->next;
    t2=t2->next;
    if(t1->next==NULL)t1=head2;
    if(t2->next==NULL)t1=head1;
}
  return t1;
}
void insertboth(node*head1,node*head2,int val){
  node*newe=create_node(val);
  node*t1=head1;
  node*t2=head2;
  while(t1->next!=NULL)t1=t1->next;
  while(t2->next!=NULL)t2=t2->next;
  t1->next=newe;
  t2->next=newe;
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
    node*h1=NULL;
    node*h2=NULL;
    int ctr=0;
       int x;
    while(1){
        printf("\nMenu:\n");
        printf("1. Add element to the list 1,if list is empty ignore..\n");
        printf("2. Add element to the list 2,if list is empty ignore..\n");
        printf("3. Add element that in both list1 & list2 \n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int c;
        scanf("%d",&c);
        switch(c){
          case 1:
           printf("enter the value to be inserted in list1 :");
           
           scanf("%d",&x);
           h1=insert(h1,x);
           break;
          
          case 2:
           printf("enter the value to be inserted in list2 :");
           
           scanf("%d",&x);
           h2=insert(h2,x);
           break;
          case 3:
           printf("enter the value to be inserted in list1&& list 2 :");
           scanf("%d",&x);
           insertboth(h1,h2,x);
           ctr++;
           break;
          
          case 4:
              printf("ALL ELEMENTS INSERTED FOR BOTH THE LISTS ...");
                if(ctr==0){
          printf("\nNO INTERSECTION\n");
          return 0;
        }
        node*neww=common(h1,h2);
        if(neww==NULL){
          printf("\nNO INTERSECTION\n");
          return 0;
        }
        else{
          printf("the intersecting element of the two lists is present at %p  and value is %d",(void*)neww,neww->val);
        }
          }
          
    }
    return 0;
  


}
