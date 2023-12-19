#include <stdio.h>

int front = -1, rear = -1, max;

void dequeue(int queue[]);
void enqueue(int queue[], int value);
void display(int queue[]);

int main()
{
    int selection, value;
    printf("Enter the size of Queue: ");
    scanf("%d", &max);
    
    int queue[max];
    printf("Choose operation to perform on Queue\n");    
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &selection);
        switch (selection)
        {
	    case 1:
	        printf("Enter element to be added to queue: ");
		scanf("%d", &value);
		enqueue(queue, value);
		break;
	    case 2:
		dequeue(queue);
		break;
	    case 3:
		display(queue);
		break;
	    case 4:
		return 0;
	    default:
		printf("\nInvalid Selection\n");
       }
   }
}

void enqueue(int queue[], int value)
{
    if (rear == max - 1)
    {
    	printf("\nQueue is full\n");
    } 
    if (front == -1 && rear == -1)
    {
        front = 0;
    }
    
    rear++;
    queue[rear] = value;
}

void dequeue(int queue[])
{
    if (front == -1)
    {
        printf("\nEmpty queue\n");
    }
    int value = queue[front];
    printf("\n%d has been deleted from queue\n", value);
    
    if (front == rear)
    {
        front == -1;
        rear == -1;
    }
    else
        front++;
    
}

void display(int queue[])
{
    printf("\nStack elements\n");
    for (int i = 0; i < max; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

