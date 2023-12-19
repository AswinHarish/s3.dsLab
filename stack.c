#include <stdio.h>
#include <stdlib.h>

int top = -1;
int max;

void pop(int stack[]);
void push(int stack[], int value);
void display(int stack[]);

int main()
{
    int selection, value;
    printf("Enter the size of the stack: ");
    scanf("%d", &max);
    
    int stack[max];
    printf("Choose operation to perform on stack\n");    
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &selection);
        switch (selection)
        {
	    case 1:
	        printf("Enter element to be pushed on to stack: ");
		scanf("%d", &value);
		push(stack, value);
		break;
	    case 2:
		pop(stack);
		break;
	    case 3:
		display(stack);
		break;
	    case 4:
		return 0;
	    default:
		printf("\nInvalid Selection\n");
       }
   }
}

void push(int stack[], int value)
{
    if (top == max - 1)
    {
    	printf("\nStack overflow\n");
    	exit(0);
    } else {
    	top++;
    	stack[top] = value;
    }
}

void pop(int stack[])
{
    if (top == -1)
    {
        printf("\nStack underflow\n");
        exit(0);
    } else {
        int value = stack[top];
        top--;
        printf("\n%d has been popped\n", value);
    }
}

void display(int stack[])
{
    printf("\nStack elements\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    exit(0);
}

