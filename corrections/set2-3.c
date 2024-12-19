#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, int data, int position) {
    int i;
    struct Node *newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

void deleteNode(struct Node **head, int position) {
    int i;
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node *temp = *head;
    if (position == 1) {
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }
    struct Node *toBeDeleted = temp->next;
    temp->next = toBeDeleted->next;
    if (toBeDeleted->next != NULL) {
        toBeDeleted->next->prev = temp;
    }
    free(toBeDeleted);
}

int countNodes(struct Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void reversePrint(struct Node *tail) {
    while (tail != NULL) {
        printf("%d<->", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

void reverseList(struct Node **head) {
    struct Node *temp = NULL;
    struct Node *current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    struct Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Print Linked List\n");
        printf("4. Count Nodes\n");
        printf("5. Reverse Print\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertNode(&head, data, position);
                break;

            case 2:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;

            case 3:
                printf("Linked List: ");
                struct Node *temp = head;
                while (temp != NULL) {
                    printf("%d <->", temp->data);
                    temp = temp->next;
                }
                printf("NULL\n");
                break;

            case 4:
                printf("Count of nodes: %d\n", countNodes(head));
                break;

            case 5:
                if (head == NULL) {
                    printf("The list is empty.\n");
                } else {
                    struct Node *temp2 = head;
                    while (temp2->next != NULL) {
                        temp2 = temp2->next;
                    }
                    printf("Reversed Print: ");
                    reversePrint(temp2);
                }
                break;

            case 6:
                reverseList(&head);
                printf("Linked list after reversal: ");
                temp = head;
                while (temp != NULL) {
                    printf("%d<->", temp->data);
                    temp = temp->next;
                }
                printf("NULL\n");
                break;

            case 7:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
