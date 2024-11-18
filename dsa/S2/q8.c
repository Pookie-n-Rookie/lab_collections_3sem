#include<stdio.h>
#define MAX_SIZE 5

struct CircularQueue {
int data[MAX_SIZE];
int front;
int rear;
int count;
};
void initializeQueue(struct CircularQueue* queue) {
queue->front = -1;
queue->rear = -1;
queue->count = 0;
}
int isQueueEmpty(struct CircularQueue* queue) {
return queue->count == 0;
}
int isQueueFull(struct CircularQueue* queue) {
return queue->count == MAX_SIZE;
}
void enqueue(struct CircularQueue* queue, int value) {
if (isQueueFull(queue)) {
printf("Queue is full. Cannot enqueue.\n");
return;
}
if (queue->front == -1)
queue->front = 0;
queue->rear = (queue->rear + 1) % MAX_SIZE;
queue->data[queue->rear] = value;
queue->count++;
printf("%d enqueued.\n", value);
}
int dequeue(struct CircularQueue* queue) {
if (isQueueEmpty(queue)) {
printf("Queue is empty. Cannot dequeue.\n");
return -1;
}
int value = queue->data[queue->front];
queue->front = (queue->front + 1) % MAX_SIZE;
queue->count--;

return value;
}
int queueSize(struct CircularQueue* queue) {
return queue->count;
}
void checkConditions(struct CircularQueue* queue) {
if (isQueueEmpty(queue)) {
printf("Underflow condition: Queue is empty.\n");
} else if (isQueueFull(queue)) {
printf("Overflow condition: Queue is full.\n");
} else {
printf("No overflow or underflow condition.\n");
}
}
void displayQueue(struct CircularQueue* queue) {
if (isQueueEmpty(queue)) {
printf("Queue is empty.\n");
return;
}
printf("Queue elements: ");
int i = queue->front;
int count = queue->count;
while (count > 0) {
printf("%d ", queue->data[i]);
i = (i + 1) % MAX_SIZE;
count--;
}
printf("\n");
}
int main() {
struct CircularQueue circularQueue;
initializeQueue(&circularQueue);
int choice, value;
do {
printf("\nCircular Queue Operations:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Check Number of Elements\n");
printf("4. Check Overflow and Underflow Conditions\n");

printf("5. Display Queue\n");
printf("6. Quit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to enqueue: ");
scanf("%d", &value);
enqueue(&circularQueue, value);
break;
case 2:
value = dequeue(&circularQueue);
if (value != -1) {
printf("%d dequeued.\n", value);
}
break;
case 3:
printf("Number of elements in the queue: %d\n",

queueSize(&circularQueue));
break;
case 4:
checkConditions(&circularQueue);
break;
case 5:
displayQueue(&circularQueue);
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
