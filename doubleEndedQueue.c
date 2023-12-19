#include <stdio.h>

int front = -1, rear = -1, max;

void enqueueFront(int queue[], int value);
void enqueueRear(int queue[], int value);
void dequeueFront(int queue[]);
void dequeueRear(int queue[]);
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
        printf("\n1. Enqueue at Front\n2. Enqueue at Rear\n3. Dequeue at Front\n4. Dequeue at Rear\n5. Display\n6. Exit\n");
        scanf("%d", &selection);
        switch (selection)
        {
	    case 1:
	        printf("Enter element to be added to queue: ");
		scanf("%d", &value);
		enqueueFront(queue, value);
		break;
	    case 2:
		printf("Enter element to be added to queue: ");
		scanf("%d", &value);
		enqueueRear(queue, value);
		break;
	    case 3:
		dequeueFront(queue);
		break;
	    case 4:
		dequeueRear(queue);
		break;
	    case 5:
	        display(queue);
	        break;
	    case 6:
	        return 0;
	    default:
		printf("\nInvalid Selection\n");
       }
   }
}

void enqueueFront(int queue[], int value){
    if ((front == 0 && rear == max - 1) || (front == rear + 1)){
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1){
        front = 0;
        rear = 0;
    } else if (front == 0){
        front = max - 1;
    } else {
        front--;
    }
    queue[front] = value;
}

void enqueueRear(int queue[], int value){
    if ((front == 0 && rear == max - 1) || (front == rear + 1)){
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1){
        front = 0;
        rear = 0;
    } else if (rear == max - 1){
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
}

void dequeueFront(int queue[]){
    if (front == -1 && rear == -1){
        printf("Empty Queue\n");
    }
    printf("%d has been deleted from queue\n", queue[front]);
    if (front == rear){
        front = -1;
        rear = -1;
    } else if (front == max - 1){
        front = 0;
    } else {
        front++;
    }
}

void dequeueRear(int queue[]){
    if (front == -1 && rear == -1){
        printf("Empty Queue\n");
    }
    printf("%d has been deleted from queue\n", queue[rear]);
    if (front == rear){
        front = -1;
        rear = -1;
    } else if (rear == 0){
        rear = max - 1;
    } else {
        rear--;
    }
}


void display(int queue[]){
    if (front == -1 && rear == -1){
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
        for (int i = 0; i <= rear; i++){
            printf("%d ", queue[i]);
        } 
    }
    printf("\n");
}

