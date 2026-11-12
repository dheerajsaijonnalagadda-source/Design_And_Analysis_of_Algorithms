//Implementation of N-Queen Problem using Backtracking

#include <stdio.h>
#include <stdlib.h>

int x[20], count = 0;

int Place(int k, int i)
{
    int j;

    for(j = 1; j < k; j++)
    {
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return 0;
        }
    }

    return 1;
}

void NQueens(int k, int n)
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
        if(Place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                count++;

                printf("\nSolution %d:\n", count);

                for(j = 1; j <= n; j++)
                {
                    printf("%d ", x[j]);
                }

                printf("\n");
            }
            else
            {
                NQueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if(n < 1 || n > 19)
    {
        printf("Invalid input!");
        return 0;
    }

    NQueens(1, n);

    if(count == 0)
    {
        printf("\nNo solution exists.");
    }
    else
    {
        printf("\nTotal number of solutions = %d", count);
    }

    return 0;
}

