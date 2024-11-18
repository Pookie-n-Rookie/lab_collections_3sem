#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

struct Node {
	int data;
	struct Node* next;
};

struct Queue {
	struct Node* front;
	struct Node* rear;
};

void initializeQueue(struct Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
}

int isQueueEmpty(struct Queue* queue) {
	return queue->front == NULL;
}

void enqueue(struct Queue* queue, int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	if (queue->rear == NULL) {
		queue->front = newNode;
		queue->rear = newNode;
	} else {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	printf("%d enqueued.\n", value);
}

int dequeue(struct Queue* queue) {
	if (isQueueEmpty(queue)) {
		printf("Queue is empty. Cannot dequeue.\n");
		return -1;
	}

	struct Node* temp = queue->front;
	int value = temp->data;
	queue->front = queue->front->next;
	if (queue->front == NULL) {
		queue->rear = NULL;
	}
	free(temp);
	return value;
}

int queueSize(struct Queue* queue) {
	int size = 0;
	struct Node* current = queue->front;
	while (current != NULL) {
		size++;
		current = current->next;
	}
	return size;
}

void checkConditions(struct Queue* queue) {
	if (queue->rear == NULL) {
		printf("Overflow condition: Queue is empty.\n");
	} else if (queueSize(queue) == MAX_SIZE) {
		printf("Overflow condition: Queue is full.\n");
	} else {
		printf("No overflow or underflow condition.\n");
	}
}

void displayQueue(struct Queue* queue) {
	if (isQueueEmpty(queue)) {
		printf("Queue is empty.\n");
		return;
	}
	printf("Queue elements: ");
	struct Node* current = queue->front;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}

	printf("\n");
}
int main() {
	struct Queue linkedListQueue;
	initializeQueue(&linkedListQueue);
	int choice, value;
	do {
		printf("\nQueue Operations:\n");
		printf("1. Enqueue (Linked List)\n");
		printf("2. Dequeue (Linked List)\n");
		printf("3. Check Number of Elements (Linked List)\n");
		printf("4. Check Overflow and Underflow Conditions (Linked
			List)\n");
		printf("5. Display Queue (Linked List)\n");
		printf("6. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value to enqueue: ");
				scanf("%d", &value);
				enqueue(&linkedListQueue, value);
				break;
			case 2:
				value = dequeue(&linkedListQueue);
				if (value != -1) {
					printf("%d dequeued.\n", value);
				}
				break;
			case 3:
				printf("Number of elements in the queue: %d\n",

						queueSize(&linkedListQueue));
				break;
			case 4:
				checkConditions(&linkedListQueue);
				break;
			case 5:
				displayQueue(&linkedListQueue);
				break;
			case 6:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice. Please select a valid option.\n");

		}
	} while (choice != 6);
	return 0;
}
