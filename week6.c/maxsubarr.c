/*Divide and conquer: Implementation of maximum-subarray problem.*/
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

int crossSum(int a[], int low, int mid, int high)
{
    int leftSum = -9999;
    int rightSum = -9999;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + a[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + a[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarray(int a[], int low, int high)
{
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    int left = maxSubarray(a, low, mid);
    int right = maxSubarray(a, mid + 1, high);
    int cross = crossSum(a, low, mid, high);

    return max3(left, right, cross);
}

int main()
{
    int a[100], n = 9;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int result = maxSubarray(a, 0, n - 1);

    printf("Maximum subarray sum = %d", result);

    return 0;
}