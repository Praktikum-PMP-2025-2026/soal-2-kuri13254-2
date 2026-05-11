#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to add an edge to the graph
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1; // For undirected graph
}

// Recursive function to perform DFS and check for cycles
int isCyclicUtil(int graph[MAX_VERTICES][MAX_VERTICES], int currentVertex, int parent, int visited[MAX_VERTICES]) {
    visited[currentVertex] = 1;

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[currentVertex][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(graph, i, currentVertex, visited))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

// Function to check whether a graph contains a cycle
int isCyclic(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, -1, visited))
                return 1;
        }
    }

    return 0;
}

int main() {
    int vertices, edges;

    // Input the number of vertices
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize the adjacency matrix with zeros

    // Input the number of edges
    scanf("%d", &edges);

    // Input edges and construct the adjacency matrix
    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Input edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);

        // Validate input vertices
        if (start < 0 || start >= vertices || end < 0 || end >= vertices) {
            printf("Invalid vertices. Try again.\n");
            i--;
            continue;
        }

        addEdge(graph, start, end);
    }

    // Check if the graph contains a cycle
    if (isCyclic(graph, vertices))
        printf("TIDAK BISA");
    else
        printf("BISA");

    return 0;
}
