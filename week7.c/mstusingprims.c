#include <stdio.h>
#include <limits.h>

#define MAX 100

void prim(int graph[MAX][MAX], int n, int start)
{
    int key[MAX];
    int parent[MAX];
    int visited[MAX];
    int i, j, u;
    int total = 0;

    for (i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = 0;
    }

    key[start] = 0;

    for (i = 0; i < n; i++)
    {
        u = -1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && (u == -1 || key[j] < key[u]))
                u = j;
        }

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (graph[u][j] != 0 &&
                !visited[j] &&
                graph[u][j] < key[j])
            {
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    printf("\nMinimum Spanning Tree:\n");

    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            printf("%d - %d : %d\n", parent[i], i, key[i]);
            total += key[i];
        }
    }

    printf("Total weight = %d\n", total);
}

int main()
{
    int graph[MAX][MAX];
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    prim(graph, n, start);

    return 0;
}