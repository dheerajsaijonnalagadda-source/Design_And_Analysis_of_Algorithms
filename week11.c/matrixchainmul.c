
#include <stdio.h>
#include <limits.h>

int main()
{
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter dimensions:\n");
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    int dp[n][n];

    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i] * p[k + 1] * p[j + 1];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum number of multiplications = %d", dp[0][n - 1]);

    return 0;
}
