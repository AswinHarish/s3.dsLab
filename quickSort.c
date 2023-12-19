#include <stdio.h>

void quickSort(int arr[], int lb, int ub);
int partition(int arr[], int lb, int ub);

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
    
    int start = 0;
    int end = n - 1;
    quickSort(arr, start, end);
    
    printf("Sorted array\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quickSort(int arr[], int lb, int ub){
    int loc;
    if (lb < ub){
        loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}


int partition(int arr[], int lb, int ub){
    int temp;
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end){
        while (arr[start] <= pivot){
            start++;
        }
        while (arr[end] > pivot){
            end--;
        }
        if (start < end){
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    
    return end;
}

