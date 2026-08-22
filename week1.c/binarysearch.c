//Aim: To implement binary search algorithm in C. 

#include <stdio.h>
int main() {
    int arr[100], n, key;
    int i, low, high, mid;
    int sorted = 1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            sorted = 0;
            break;
        }
    }

    if(sorted == 0) {
        printf("Array is not sorted\n");
    }
    else {
        printf("Array is sorted\n");

        printf("Enter the element to search: ");
        scanf("%d", &key);

        low = 0;
        high = n - 1;

        while(low <= high) {
            mid = (low + high) / 2;

            if(arr[mid] == key) {
                printf("Element found at position %d\n", mid + 1);
                return 0;
            }
            else if(arr[mid] < key) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        printf("Element not found\n");
    }

    return 0;
}


