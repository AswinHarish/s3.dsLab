#include <stdio.h>

int main()
{
    int size, n, key, index;
    printf("Enter the size of has table: ");
    scanf("%d", &size);
    int table[size];
    
    for (int i = 0; i < size; i++){
        table[i] = -1;
    }
    
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Enter key: ");
        scanf("%d", &key);
        
        index = key % (size);
        if (table[index] != -1){
            printf("Collision at index %d\n", index);
        }
        else {
            table[index] = key;
            printf("%d added to hash table %d\n", key, index);
        }
    }
    
    printf("Hash Table\n");
    for (int i = 0; i < size; i++){
        if (table[i] != -1){
            printf("%d ", table[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}
