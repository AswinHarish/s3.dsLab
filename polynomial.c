#include <stdio.h>

struct poly {
    int expo;
    int coeff;
};

int main()
{
    int n,m;
    printf("Enter the number of terms of x1: ");
    scanf("%d", &n);
    
    struct poly x1[n];
    printf("Enter values for x1\n");
    for (int i = 0; i < n; i++){
        printf("Enter coeffiecient of term %d: ", i + 1);
        scanf("%d", &x1[i].coeff);
        printf("Enter exponent of term %d: ", i + 1);
        scanf("%d", &x1[i].expo);
    }
    
    printf("\n");
    printf("Enter the number of terms of x2: ");
    scanf("%d", &m);
    
    struct poly x2[m];
    printf("Enter values for x2\n");
    for (int i = 0; i < m; i++){
        printf("Enter coeffiecient of term %d: ", i + 1);
        scanf("%d", &x2[i].coeff);
        printf("Enter exponent of term %d: ", i + 1);
        scanf("%d", &x2[i].expo);
    }
    printf("\n");
    
    int resSize = (n > m) ? n : m;
    struct poly res[resSize];
    
    // addition
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (x1[i].expo > x2[j].expo)
        {
            res[k].expo = x1[i].expo;
            res[k].coeff = x1[i].coeff;
            i++;
        }
        else if (x1[i].expo < x2[j].expo)
        {
            res[k].expo = x2[j].expo;
            res[k].coeff = x2[j].coeff;
            j++;
        }
        else
        {
            res[k].coeff = x1[i].coeff + x2[j].coeff;
            res[k].expo = x1[i].expo;
            i++;
            j++;
        }
        k++;
    }
    
    while (i < n)
    {
        res[k].expo = x1[i].expo;
        res[k].coeff = x1[i].coeff;
        i++;
        k++;
    }
    
    while (j < m)
    {
        res[k].expo = x2[j].expo;
        res[k].coeff = x2[j].coeff;
        j++;
        k++;
    }
    
    printf("Resultant polynomial\n");
    printf("Exponent: ");
    for (i = 0; i < k; i++){
        printf("%d ", res[i].expo);
    }
    printf("\n");
    
    printf("Coefficient: ");
    for (i = 0; i < k; i++){
        printf("%d ", res[i].coeff);
    }
    
    printf("\n");
}

