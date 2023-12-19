#include <stdio.h>

void insertionSort(int arr[], int n);

int main()
{
    int n; 
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++){
        printf("[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    insertionSort(arr, n);
    
    printf("Sorted array\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n){
    int temp, j;
    for (int i = 1; i < n; i++){
        temp = arr[i];
        j = i - 1;
        while((j >= 0) && (arr[j] >= temp)){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
    arr[j + 1] = temp;
    }
}
