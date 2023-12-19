#include <stdio.h>

struct sparse{
    int row;
    int col;
    int value;
};

int main()
{
    int row, col, size = 0;
    printf("Enter the size of rows and cols: ");
    scanf("%d%d", &row, &col);
    
    int matrix[row][col];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
            
            if (matrix[i][j] != 0){
                size++;
            }
        }
    }
    
    struct sparse sp[size];
    int k = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            
            if (matrix[i][j] != 0){
                sp[k].row = i;
                sp[k].col = j;
                sp[k].value = matrix[i][j];
                k++;
            }
        }
    }
    
    printf("Sparse matrix\n");
    printf("---------------\n");
    printf("|Row|Col|Value|\n");
    printf("---------------\n");
    for (int i = 0 ; i < size; i++){
        printf("| %d | %d |  %d  |\n", sp[i].row, sp[i].col, sp[i].value);
    }
}













