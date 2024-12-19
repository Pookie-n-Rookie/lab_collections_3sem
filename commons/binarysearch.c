#include <stdio.h>
#include <stdlib.h>

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

node *mid(node *start, node *last) {
    if (start == NULL) {
        return NULL;
    }

    if (start == last)
        return start;

    node *slow = start;
    node *fast = start->next;

    while (fast != last && fast->next!=last) {
        fast = fast->next->next;
        slow = slow->next;

    }

    return slow;
}


void binarysearch(node *head,int value){
   node*st=head;
   node*end=NULL;
   int c=0;
   while(st!=end){
    node*mi=mid(st,end);
    if(mi->val==value)
        {c=1;
      printf("present in the list");
      break;
      }
    else if(mi->val>value)end=mi;
    else st=mi->next;
  }
  if(!c)printf("not found in the list");
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
    node *head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add element to the list\n");
        printf("2. Print the list\n");
        printf("3. search for element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                node *newNode = create_node(value);
                if (head == NULL) {
                    head = newNode;
                } else {
                  insert(head,value);
                }
                break;
            case 2:
                printf("The current list is: ");
                print(head);
                break;
            case 3:
              int value;
              printf("enter the value to be search in the list :");
              scanf("%d",&value);
              binarysearch(head,value);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
