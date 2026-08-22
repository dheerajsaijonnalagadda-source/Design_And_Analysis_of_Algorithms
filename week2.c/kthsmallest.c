//Aim: To implement kth smallest element algorithm in C.    

#include <stdio.h>

int main() {
    int x;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &x);

    int arr[x];

    printf("Enter the elements in the array: ");

    for (int n = 0; n < x; n++) {
        scanf("%d", &arr[n]);
    }

    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int k;

    printf("Enter K: ");
    scanf("%d", &k);

    printf("The kth smallest element is %d", arr[k - 1]);

    return 0;
}