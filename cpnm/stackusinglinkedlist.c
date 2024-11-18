#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* top = NULL;
void push(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	newNode->data = value;
	newNode->next = top;
	top = newNode;
	printf("%d pushed to the stack.\n", value);
}
void pop() {
	if (top == NULL) {
		printf("Stack is empty. Cannot pop.\n");
		return;
	}
	struct Node* temp = top;
	top = top->next;
	printf("%d popped from the stack.\n", temp->data);
	free(temp);
}
void display() {
	if (top == NULL) {
		printf("Stack is empty.\n");
		return;
	}
	printf("Stack elements: ");
	struct Node* temp = top;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	int choice, value;

	do {
		printf("\nStack Operations:\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice. Please select a valid option.\n");
		}
	} while (choice != 4);
	return 0;
}
