#include <stdio.h>
#include <stdlib.h>

#define MAXV 20
#define MAXE 400

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAXE];
int edgeCount = 0;

int parent[MAXV];

void initEdges() { edgeCount = 0; }
void addEdge(int u, int v, int w) {
    edges[edgeCount].u = u;
    edges[edgeCount].v = v;
    edges[edgeCount].w = w;
    edgeCount++;
}

int compareEdge(const void *a, const void *b) {
    Edge *ea = (Edge*)a;
    Edge *eb = (Edge*)b;
    return ea->w - eb->w;
}

/* Disjoint set (union-find) */
void makeSet(int n) {
    for (int i = 0; i < n; ++i) parent[i] = -1;
}

int findSet(int x) {
    if (parent[x] < 0) return x;
    parent[x] = findSet(parent[x]);
    return parent[x];
}

int unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return 0;
    if (parent[a] > parent[b]) { int t = a; a = b; b = t; }
    parent[a] += parent[b];
    parent[b] = a;
    return 1;
}

void kruskal(int n) {
    qsort(edges, edgeCount, sizeof(Edge), compareEdge);
    makeSet(n);

    int mstWeight = 0, used = 0;
    printf("Edges in MST (u - v : w):\n");
    for (int i = 0; i < edgeCount && used < n-1; ++i) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (findSet(u) != findSet(v)) {
            unionSet(u, v);
            printf("%d - %d : %d\n", u, v, w);
            mstWeight += w;
            used++;
        }
    }
    printf("Total cost of MST = %d\n", mstWeight);
}

int main() {
    /* Example graph with 6 vertices and weighted undirected edges */
    int n = 6;
    initEdges();
    addEdge(0,1,4);
    addEdge(0,2,4);
    addEdge(1,2,2);
    addEdge(1,3,5);
    addEdge(2,4,5);
    addEdge(3,4,4);
    addEdge(3,5,6);
    addEdge(4,5,7);

    kruskal(n);
    return 0;
}
