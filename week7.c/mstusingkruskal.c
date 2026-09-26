#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = a;
}

void sort(struct Edge edges[], int e)
{
    int i, j;
    struct Edge temp;

    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main()
{
    struct Edge edges[100];
    int n, e, i;
    int count = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter source, destination and weight:\n");

    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (i = 0; i < n; i++)
        parent[i] = i;

    sort(edges, e);

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e && count < n - 1; i++)
    {
        if (find(edges[i].u) != find(edges[i].v))
        {
            printf("%d - %d : %d\n",
                   edges[i].u,
                   edges[i].v,
                   edges[i].w);

            cost += edges[i].w;
            unite(edges[i].u, edges[i].v);
            count++;
        }
    }

    if (count == n - 1)
        printf("Minimum Cost = %d\n", cost);
    else
        printf("MST does not exist\n");

    return 0;
}