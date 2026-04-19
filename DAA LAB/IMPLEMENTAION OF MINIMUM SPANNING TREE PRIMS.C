#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 5 // Number of vertices
#define E 6 // Number of edges
// Function to find the vertex with minimum key value (Minimum edge weight)
int minKey(int key[], int visited[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
// Function to print MST
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");
    int total = 0;
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total Cost = %d\n", total);
}
// Prim's Algorithm Implementation
void primMST(int graph[V][V])
{
    int parent[V];  // Stores MST
    int key[V];     // Minimum edge weight
    int visited[V]; // Track visited vertices
    // Step 1: Initialize
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    // Step 2: Start from vertex 0
    key[0] = 0;
    parent[0] = -1;
    // Step 3: Build MST
    for (int count = 0; count < V - 1; count++)
    {
        // Pick minimum key vertex(Pick the smallest (minimum weight) edge)
        int u = minKey(key, visited);
        visited[u] = 1;
        // Update adjacent vertices for the picked vertex u
        for (int v = 0; v < V; v++)
        {
            //(u, v) is an edge and v is not visited and weight of (u, v) is smaller than key[v]
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
}
}
}
parent[v] = u;
key[v] = graph[u][v];
printPrimMST(parent, graph);
}
int main()
{
// Graph for Prim's (Adjacency Matrix)(List all edges of the graph  )
int graph[V][V] = {
{0, 2, 3, 0, 0},
{2, 0, 5, 3, 0},
{3, 5, 0, 0, 4},
{0, 3, 0, 0, 2},
{0, 0, 4, 2, 0}};
// Run Prim's Algorithm(calling function)
primMST(graph);
return 0;
}