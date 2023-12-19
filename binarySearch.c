#include <stdio.h>

int binarySearch(int arr[], int n, int key);

int main()
{
    int n, key, temp;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++){
        printf("[%d] : ", i);
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
               temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
            }
        }
    }
    
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    
    binarySearch(arr, n, key);
}

int binarySearch(int arr[], int n, int key)
{
    int start = 0, end = n, mid;
    while (start <= end){
        mid = (start + end) / 2;
        if (arr[mid] == key){
           printf("Element found at index %d\n", mid);
           return 0;
        }
        else if (key < arr[mid]){
             end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    printf("Element not found\n");
    return 0;
}

