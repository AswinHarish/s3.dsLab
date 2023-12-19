#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int power;
    struct Node* next;
} Node;

void freePolynomial(Node* poly);
void displayPolynomial(Node* poly);
Node* addPolynomials(Node* poly1, Node* poly2);
void insertNode(Node** head, int coeff, int power);
Node* createNode(int coeff, int power);

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    int n, coeff, expo;
    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n);

    printf("Enter coeff and expo of polynomial 1\n");
    for (int i = 0; i < n; i++){
        printf("Coeff: ");
        scanf("%d", &coeff);
        printf("Expo: ");
        scanf("%d", &expo);
        insertNode(&poly1, coeff, expo);
    }

    printf("Enter coeff and expo of polynomial 2\n");
    for (int i = 0; i < n; i++){
        printf("Coeff: ");
        scanf("%d", &coeff);
        printf("Expo: ");
        scanf("%d", &expo);
        insertNode(&poly2, coeff, expo);
    }

    Node* sum = addPolynomials(poly1, poly2);
    printf("Sum of the polynomials: ");
    displayPolynomial(sum);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
}


Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int coeff, int power) {
    Node* temp = *head;
    Node* newNode = createNode(coeff, power);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coeff = 0;
        int power = 0;

        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->power > poly2->power) {
                coeff = poly1->coeff;
                power = poly1->power;
                poly1 = poly1->next;
            } else if (poly1->power < poly2->power) {
                coeff = poly2->coeff;
                power = poly2->power;
                poly2 = poly2->next;
            } else {
                coeff = poly1->coeff + poly2->coeff;
                power = poly1->power;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        } else if (poly1 != NULL) {
            coeff = poly1->coeff;
            power = poly1->power;
            poly1 = poly1->next;
        } else if (poly2 != NULL) {
            coeff = poly2->coeff;
            power = poly2->power;
            poly2 = poly2->next;
        }

        if (coeff != 0) {
            insertNode(&result, coeff, power);
        }
    }

    return result;
}


void displayPolynomial(Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->power);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

void freePolynomial(Node* poly) {
    Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}


