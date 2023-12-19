#include <stdio.h>

void selectionSort(int arr[], int n);

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
    
    selectionSort(arr, n);
    
    printf("Sorted array\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n){
    int min, j, temp;
    for (int i = 0; i < n - 1; i++){
        min = i;
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        
        if (min != i){
	    temp = arr[i];
	    arr[i] = arr[min];
	    arr[min] = temp;
	}
    }
}
