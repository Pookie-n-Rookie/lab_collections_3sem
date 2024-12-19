#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at a given position
void insertNode(struct Node **head, int data, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at a given position
void deleteNode(struct Node **head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node *temp = *head;
    if (position == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }
    struct Node *toBeDeleted = temp->next;
    temp->next = toBeDeleted->next;
    free(toBeDeleted);
}

// Function to count the number of nodes
int countNodes(struct Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Recursive function to print the linked list in reverse
void reversePrint(struct Node *head) {
    if (head == NULL) {
        return;
    }
    reversePrint(head->next);
    printf("%d ", head->data);
}

// Function to reverse the linked list
void reverseList(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    *head = prev;
}

// Main function with user input
int main() {
    struct Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Count Nodes\n");
        printf("4. Reverse Print\n");
        printf("5. Reverse List\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert node
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert the node: ");
                scanf("%d", &position);
                insertNode(&head, data, position);
                break;
            case 2:
                // Delete node
                printf("Enter the position of the node to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                // Count nodes
                printf("Count of nodes: %d\n", countNodes(head));
                break;
            case 4:
                // Reverse print
                printf("Reversed Linked list: ");
                reversePrint(head);
                printf("\n");
                break;
            case 5:
                // Reverse list
                reverseList(&head);
                printf("Linked list after reversal: ");
                struct Node *temp = head;
                while (temp != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
                break;
            case 6:
                // Display list
                printf("Linked list: ");
                temp = head;
                while (temp != NULL) {
                    printf("%d->", temp->data);
                    temp = temp->next;
                }
                printf("NULL\n");
                break;
            case 7:
                // Exit the program
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
