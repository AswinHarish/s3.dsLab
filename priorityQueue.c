#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** front, int data, int priority) {
    Node* newNode = createNode(data, priority);

    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        Node* temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void dequeue(Node** front) {
    if (*front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node* temp = *front;
        *front = (*front)->next;
        printf("Dequeued element: %d\n", temp->data);
        free(temp);
    }
}


void display(Node* front) {
    printf("Priority Queue: ");
    while (front != NULL) {
        printf("(%d, %d) ", front->data, front->priority);
        front = front->next;
    }
    printf("\n");
}

void freeQueue(Node** front) {
    Node* current = *front;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *front = NULL;
}

int main() {
    Node* front = NULL;
    int choice, data, priority;

    do {
        printf("Priority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority to enqueue: ");
                scanf("%d %d", &data, &priority);
                enqueue(&front, data, priority);
                break;
            case 2:
                dequeue(&front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                freeQueue(&front);
                printf("Priority Queue freed. Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}