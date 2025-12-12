#include <stdio.h>
#include <limits.h>

#define MAXV 20
#define INF INT_MAX

void prim(int n, int wt[MAXV][MAXV], int start) {
    int selected[MAXV] = {0};
    int key[MAXV];
    int parent[MAXV];

    for (int i = 0; i < n; ++i) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[start] = 0;

    for (int count = 0; count < n; ++count) {
        int u = -1, min = INF;
        for (int v = 0; v < n; ++v)
            if (!selected[v] && key[v] < min) { min = key[v]; u = v; }

        if (u == -1) break;
        selected[u] = 1;

        for (int v = 0; v < n; ++v) {
            if (!selected[v] && wt[u][v] != INF && wt[u][v] < key[v]) {
                key[v] = wt[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    printf("Edges in MST (u - v : w):\n");
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            printf("%d - %d : %d\n", parent[i], i, wt[parent[i]][i]);
            total += wt[parent[i]][i];
        }
    }
    printf("Total cost of MST = %d\n", total);
}

int main() {
    int n = 6;
    int wt[MAXV][MAXV];
    /* Initialize matrix with INF (no edge) and 0 diagonal */
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            wt[i][j] = (i==j) ? 0 : INF;

    /* Example undirected weighted graph */
    wt[0][1] = wt[1][0] = 4;
    wt[0][2] = wt[2][0] = 4;
    wt[1][2] = wt[2][1] = 2;
    wt[1][3] = wt[3][1] = 5;
    wt[2][4] = wt[4][2] = 5;
    wt[3][4] = wt[4][3] = 4;
    wt[3][5] = wt[5][3] = 6;
    wt[4][5] = wt[5][4] = 7;

    prim(n, wt, 0);
    return 0;
}
