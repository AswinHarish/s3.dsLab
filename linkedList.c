#include <stdio.h>
#include <stdlib.h>

struct Node* createNode(int data);
void displayList(struct Node* head);
void deleteEnd(struct Node** head);
void deleteFront(struct Node** head);
void addEnd(struct Node** head, int data);
void addFront(struct Node** head, int data);

struct Node {
    int data;
    struct Node* next;
};

int main()
{
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add an element to the front\n");
        printf("2. Add an element to the end\n");
        printf("3. Delete an element from the front\n");
        printf("4. Delete an element from the end\n");
        printf("5. Display the linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to add to the front: ");
                scanf("%d", &data);
                addFront(&head, data);
                break;
            case 2:
                printf("Enter the data to add to the end: ");
                scanf("%d", &data);
                addEnd(&head, data);
                break;
            case 3:
                deleteFront(&head);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("%d added to the front of the list.\n", data);
}

void addEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("%d added to the end of the list.\n", data);
}

void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    printf("%d deleted from the front of the list.\n", temp->data);
    free(temp);
}

void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        printf("%d deleted from the list.\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    printf("%d deleted from the end of the list.\n", current->next->data);
    free(current->next);
    current->next = NULL;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    if (current == NULL)
        printf("Empty\n");
    else{
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
    }
}
