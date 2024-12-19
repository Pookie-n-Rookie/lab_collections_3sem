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

node *lsttofst(node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node *temp = head;
    node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    temp->next = head;
    head = temp;

    return head;
}
void insert(node *head,int value){
  node*temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  node *newe=create_node(value);
  temp->next=newe;
  
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
        printf("3. Move last node to front\n");
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
                head = lsttofst(head);
                printf("After moving last node to front, the list is: ");
                print(head);
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
