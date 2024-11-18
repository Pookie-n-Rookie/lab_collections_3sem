#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
struct Stack {
int data[MAX_SIZE];
int top;
};
void initialize(struct Stack* stack) {
stack->top = -1;
}
int isEmpty(struct Stack* stack) {
return stack->top == -1;

}
int isFull(struct Stack* stack) {
return stack->top == MAX_SIZE - 1;
}
void push(struct Stack* stack, int value) {
if (!isFull(stack)) {
stack->data[++stack->top] = value;
}
}
int pop(struct Stack* stack) {
if (!isEmpty(stack)) {
return stack->data[stack->top--];
}
return -1;
}
struct Queue {
struct Stack stack1;
struct Stack stack2;
};
void initializeQueue(struct Queue* queue) {
initialize(&queue->stack1);
initialize(&queue->stack2);
}
void enqueue(struct Queue* queue, int value) {
if (isFull(&queue->stack1)) {
printf("Queue is full. Cannot enqueue.\n");
return;
}
while (!isEmpty(&queue->stack1)) {
push(&queue->stack2, pop(&queue->stack1));
}
push(&queue->stack1, value);
while (!isEmpty(&queue->stack2)) {
push(&queue->stack1, pop(&queue->stack2));
}
printf("%d enqueued.\n", value);
}

int dequeue(struct Queue* queue) {
if (isEmpty(&queue->stack1)) {
printf("Queue is empty. Cannot dequeue.\n");
return -1;
}
return pop(&queue->stack1);
}
int main() {
struct Queue queue;
initializeQueue(&queue);
int choice, value;
do {
printf("\nQueue Operations using Two Stacks:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Quit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to enqueue: ");
scanf("%d", &value);
enqueue(&queue, value);
break;
case 2:
value = dequeue(&queue);
if (value != -1) {
printf("%d dequeued.\n", value);
}
break;
case 3:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please select a valid option.\n");
}
} while (choice != 3);
return 0;
}
