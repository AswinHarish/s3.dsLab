#include <stdio.h>

#define MAX_DEGREE 100

void multiplyPolynomials(int A[], int B[], int m, int n, int prod[]) {
    for (int i = 0; i < m + n - 1; i++)
        prod[i] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            prod[i + j] += A[i] * B[j];
        }
    }
}
void displayPolynomial(int poly[], int n) {
    int isFirstTerm = 1;

    for (int i = 0; i < n; i++) {
        if (poly[i] != 0) {
            if (!isFirstTerm) {
                printf(" + ");
            }

            printf("%dx^%d", poly[i], i);
            isFirstTerm = 0;
        }
    }

    if (isFirstTerm) {
        printf("0");
    }

    printf("\n");
}

int main() {
    int degreeA, degreeB;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degreeA);

    printf("Enter the coefficients of the first polynomial starting from x^0 up to x^%d:\n", degreeA);
    int polynomialA[MAX_DEGREE];
    for (int i = 0; i <= degreeA; i++) {
        scanf("%d", &polynomialA[i]);
    }

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degreeB);

    printf("Enter the coefficients of the second polynomial starting from x^0 up to x^%d:\n", degreeB);
    int polynomialB[MAX_DEGREE];
    for (int i = 0; i <= degreeB; i++) {
        scanf("%d", &polynomialB[i]);
    }

    int prodDegree = degreeA + degreeB;
    int product[MAX_DEGREE];
    multiplyPolynomials(polynomialA, polynomialB, degreeA + 1, degreeB + 1, product);

    printf("The product of the polynomials is: ");
    displayPolynomial(product, prodDegree + 1);

    return 0;
}