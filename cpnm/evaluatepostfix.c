#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
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
void push(struct Stack* stack, int value) {
	if (stack->top < MAX_SIZE - 1) {
		stack->data[++stack->top] = value;
	}
}
int pop(struct Stack* stack) {
	if (!isEmpty(stack)) {
		return stack->data[stack->top--];
	}
	return 0; // Return a default value
}
int evaluatePostfix(char* postfix) {
	struct Stack operandStack;
	initialize(&operandStack);
	for (int i = 0; postfix[i] != '\0'; i++) {
		if (isdigit(postfix[i])) {
			push(&operandStack, postfix[i] - '0');
		} else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] ==
				'*' || postfix[i] == '/') {

			int operand2 = pop(&operandStack);
			int operand1 = pop(&operandStack);
			int result;
			switch (postfix[i]) {
				case '+':
					result = operand1 + operand2;
					break;
				case '-':
					result = operand1 - operand2;

					break;
				case '*':
					result = operand1 * operand2;
					break;
				case '/':
					result = operand1 / operand2;
					break;
			}
			push(&operandStack, result);
		}
	}
	return pop(&operandStack);
}
int main() {
	char postfix[MAX_SIZE];
	printf("Enter the postfix expression: ");
	fgets(postfix, sizeof(postfix), stdin);
	int result = evaluatePostfix(postfix);
	printf("Result: %d\n", result);
	return 0;
}
