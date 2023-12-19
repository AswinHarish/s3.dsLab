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
	        printf("Enter element: ");
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
    if ((front == 0 && rear == max -1) || (front == rear + 1))
    {
    	printf("\nQueue is full\n");
    } else {
         
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == max - 1){
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = value;
    }
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
        front = -1;
        rear = -1;
    }
    if (front == max - 1){
        front++;
    }
    front++;
}

void display(int queue[])
{
    if (front == -1){
        printf("Empty Queue\n");
    }
    else if (front <= rear)
    {
        printf("\nQueue elements\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (int i = front; i < max; i++){
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= front; i++){
            printf("%d ", queue[i]);
        } 
    }
    printf("\n");
}

