                                                                                                                                                                        #include <stdio.h>

void mergeSort(int arr[], int lb, int ub);
void merge(int arr[], int lb, int ub, int mid);

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int start = 0;
    int end = n - 1;
    mergeSort(arr, start, end);
    
    printf("Sorted array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergeSort(int arr[], int lb, int ub){
    if (lb < ub){
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, ub, mid);
    }
}

void merge(int arr[], int lb, int ub, int mid){
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub + 1];

    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        b[k++] = arr[i++];
    }

    while (j <= ub) {
        b[k++] = arr[j++];
    }

    for (k = lb; k <= ub; k++) {
        arr[k] = b[k];
    }
}
