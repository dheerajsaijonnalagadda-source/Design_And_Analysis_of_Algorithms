/*4. Greedy Approach: Implementation of Fractional Knapsack*/

#include <stdio.h>
int main()
{
    int n, i;
    float weight[20], profit[20], ratio[20], capacity, total_profit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and profits of %d items:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }
    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            total_profit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            total_profit += ratio[i] * capacity;
            break;
        }
    }

    printf("Total profit in the knapsack = %.2f\n", total_profit);
    return 0;
}