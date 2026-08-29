#include <stdio.h>
#define SIZE 20
int hashTable[SIZE];
int main(){
    int a[SIZE], n, target;
    int i, index, complement;
    int found = 0;
    
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
        
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    printf("Enter the target value: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++){
        complement = target - a[i];
        for (index = 0; index < SIZE; index++){
            if (hashTable[index] == complement){
                printf("Pair found: %d + %d = %d\n",
                       complement, a[i], target);
                found = 1;
                break;
            }
        }
        if (found)
            break;
        index = a[i] % SIZE;
        while (hashTable[index] != -1){
            index = (index + 1) % SIZE;
        }
        hashTable[index] = a[i];
    }
    if (!found)
        printf("No pair found\n");
    return 0;
}
