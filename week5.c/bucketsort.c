#include <stdio.h>

void bucketSort(int a[], int n)
{
    int bucket[10][10];
    int count[10] = {0};
    int i, j, k = 0, index, temp;

    for(i = 0; i < n; i++)
    {
        index = a[i] / 10;
        bucket[index][count[index]] = a[i];
        count[index]++;
    }

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < count[i] - 1; j++)
        {
            for(k = 0; k < count[i] - j - 1; k++)
            {
                if(bucket[i][k] > bucket[i][k + 1])
                {
                    temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }

    k = 0;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < count[i]; j++)
        {
            a[k] = bucket[i][j];
            k++;
        }
    }
}

int main()
{
    int a[100];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    bucketSort(a, n);

    printf("Sorted array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}