#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
struct Stack {

	char data[MAX_SIZE];
	int top;
};
void initialize(struct Stack* stack) {
	stack->top = -1;
}
int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}
void push(struct Stack* stack, char c) {
	if (stack->top < MAX_SIZE - 1) {
		stack->data[++stack->top] = c;
	}
}
char pop(struct Stack* stack) {
	if (!isEmpty(stack)) {
		return stack->data[stack->top--];
	}
	return '\0';
}
int isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
int precedence(char c) {
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	return 0;
}
void infixToPostfix(char* infix, char* postfix) {
	struct Stack operatorStack;
	initialize(&operatorStack);
	int postfixIndex = 0;
	for (int i = 0; infix[i] != '\0'; i++) {
		if (isalnum(infix[i])) {
			postfix[postfixIndex++] = infix[i];
		} else if (infix[i] == '(') {
			push(&operatorStack, infix[i]);

		} else if (infix[i] == ')') {
			while (!isEmpty(&operatorStack) &&
					operatorStack.data[operatorStack.top] != '(') {

				postfix[postfixIndex++] = pop(&operatorStack);
			}
			pop(&operatorStack); // Pop '('
		} else if (isOperator(infix[i])) {
			while (!isEmpty(&operatorStack) &&

					precedence(operatorStack.data[operatorStack.top]) >= precedence(infix[i]))
			{

				postfix[postfixIndex++] = pop(&operatorStack);
			}
			push(&operatorStack, infix[i]);
		}
	}
	while (!isEmpty(&operatorStack)) {
		postfix[postfixIndex++] = pop(&operatorStack);
	}
	postfix[postfixIndex] = '\0';
}
int main() {
	char infix[MAX_SIZE];
	char postfix[MAX_SIZE];
	printf("Enter the infix expression: ");
	fgets(infix, sizeof(infix), stdin);
	infixToPostfix(infix, postfix);
	printf("Postfix expression: %s\n", postfix);
	return 0;
}
