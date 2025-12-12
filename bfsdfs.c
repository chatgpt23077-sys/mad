#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n; // number of vertices

void initGraph(int vertices) {
    n = vertices;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = 0;
}

void addEdgeUndirected(int u, int v) {
    if (u < 0 || u >= n || v < 0 || v >= n) {
        printf("Invalid edge\n");
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void printAdjMatrix() {
    printf("Adjacency Matrix:\n   ");
    for (int i = 0; i < n; ++i) printf("%d ", i);
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%d: ", i);
        for (int j = 0; j < n; ++j)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

/* BFS using queue */
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; ++i) visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS traversal from %d: ", start);
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; ++v) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

/* DFS using recursion */
void DFS_util(int u) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; ++v)
        if (adj[u][v] && !visited[v])
            DFS_util(v);
}

void DFS(int start) {
    for (int i = 0; i < n; ++i) visited[i] = 0;
    printf("DFS traversal from %d: ", start);
    DFS_util(start);
    printf("\n");
}

int main() {
    int vertices = 6;
    initGraph(vertices);

    /* Example: build an undirected graph
       Edges: 0-1, 0-2, 1-3, 2-4, 2-5 */
    addEdgeUndirected(0,1);
    addEdgeUndirected(0,2);
    addEdgeUndirected(1,3);
    addEdgeUndirected(2,4);
    addEdgeUndirected(2,5);

    printAdjMatrix();

    BFS(0);
    DFS(0);

    return 0;
}
