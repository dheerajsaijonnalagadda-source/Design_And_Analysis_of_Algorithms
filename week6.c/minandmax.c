/*1. Implementation of finding the maximum and minimum element using divide and conquer
strategy. Analyse and describe how the divide and conquer strategy is better when
compared to traditional approach.*/
#include <stdio.h>

void MaxMin(int a[], int low, int high, int result[])
{
    int mid;
    int left[2], right[2];

    if (low == high)
    {
        result[0] = a[low];
        result[1] = a[low];
    }
    else if (low == high - 1)
    {
        if (a[low] > a[high])
        {
            result[0] = a[low];
            result[1] = a[high];
        }
        else
        {
            result[0] = a[high];
            result[1] = a[low];
        }
    }
    else
    {
        mid = (low + high) / 2;

        MaxMin(a, low, mid, left);
        MaxMin(a, mid + 1, high, right);

        result[0] = left[0] > right[0] ? left[0] : right[0];
        result[1] = left[1] < right[1] ? left[1] : right[1];
    }
}

int main()
{
    int a[100], n, result[2];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    MaxMin(a, 0, n - 1, result);

    printf("Maximum = %d\n", result[0]);
    printf("Minimum = %d\n", result[1]);

    return 0;
}