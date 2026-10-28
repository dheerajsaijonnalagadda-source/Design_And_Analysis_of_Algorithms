//Write a program to implement Floyd Warshall Algorithm to find the shortest path between every pair of the vertices.

#include <stdio.h>
#define V 4
#define INF 99999
struct Node {
    int dist[V][V];
};
static void printSolution(struct Node* node);
static void floydWarshall(int graph[][V], struct Node* node);
static void initializeNode(struct Node* node);
int main() {
    int graph[V][V] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    struct Node node;
    initializeNode(&node);
    floydWarshall(graph, &node);
    return 0;
}
static void initializeNode(struct Node* node) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            node->dist[i][j] = INF;
        }
    }
}
static void floydWarshall(int graph[][V], struct Node* node) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            node->dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (node->dist[i][k] + node->dist[k][j] < node->dist[i][j]) {
                    node->dist[i][j] = node->dist[i][k] + node->dist[k][j];
                }
            }
        }
    }

    printSolution(node);
}
static void printSolution(struct Node* node) {
    printf("The following matrix shows the shortest distances"
           " between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (node->dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", node->dist[i][j]);
        }
        printf("\n");
    }
}