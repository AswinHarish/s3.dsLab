#include <stdio.h>

int main()
{
    int arr[20], key, n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
             printf("Element found\n");
             return 0;
        }
    }
    printf("Element not found\n");
    
}

