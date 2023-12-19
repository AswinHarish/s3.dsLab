#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c);
char pop();
char peek();
int isEmpty();
int isOperator(char c);
int precedence(char c);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAX];
    char postfix[MAX] = {0};
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;

    for (i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push('(');
        } else if (infix[i] == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else if (isOperator(infix[i])) {
            while (!isEmpty() && precedence(infix[i]) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
}

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        exit(1);
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
