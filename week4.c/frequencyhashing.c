#include <stdio.h>
#define SIZE 100
int hash[SIZE];
int count[SIZE];
int main(){
    int a[SIZE], n;
    int i, index;
    for(i = 0; i < SIZE; i++){
        hash[i] = -1;
        count[i] = 0;
    }
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++){
        index = a[i] % SIZE;
        if(index < 0)
            index = index + SIZE;
        while(hash[index] != -1 && hash[index] != a[i])
            index = (index + 1) % SIZE;
        if(hash[index] == -1){
            hash[index] = a[i];
            count[index] = 1;
        }
        else{
            count[index]++;
        }
    }
    printf("Element\tFrequency\n");
    for(i = 0; i < SIZE; i++){
        if(hash[i] != -1)
            printf("%d\t%d\n", hash[i], count[i]);
    }
    return 0;
}
