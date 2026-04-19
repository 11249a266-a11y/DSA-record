#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 5 // Number of vertices
#define E 6 // Number of edges
// Edge structure
struct Edge
{
int src, dest, weight;
};
// Parent array for Union-Find
int parentUF[V];
// Find function
int find(int i)
{
if (parentUF[i] == i)
return i;
return find(parentUF[i]);
}
// Union function
void unionSet(int u, int v)
{
int rootU = find(u);
int rootV = find(v);
parentUF[rootU] = rootV;
}
// Compare edges for sorting
int compare(const void *a, const void *b)
{
return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
// Kruskal's Algorithm
void kruskalMST(struct Edge edges[])
{
printf("\nKruskal's MST:\n");
printf("Edge \tWeight\n");
// Step 1: List and Sort edges using inbuilt qsort, part of C standard library(Sort edges in increasing order of weight)
qsort(edges, E, sizeof(edges[0]), compare);
// Step 2: Initialize sets
for (int i = 0; i < V; i++)
parentUF[i] = i;
int count = 0;
int total = 0;
// Step 3: Pick edges(Pick the smallest edge)
for (int i = 0; i < E && count < V - 1; i++)
{
int u = edges[i].src;
int v = edges[i].dest;
// Step 4: Check cycle
if (find(u) != find(v))
{
printf("%d - %d \t%d\n", u, v, edges[i].weight);
total += edges[i].weight;
unionSet(u, v); // Merge sets
count++;
}
}
}
printf("Total Cost = %d\n", total);
int main()
{
// Edge list for Kruskal's(List all edges of the graph)
struct Edge edges[E] = {
{0, 1, 2},
{0, 2, 3},
{1, 2, 5},
{1, 3, 3},
{2, 4, 4},
{3, 4, 2}};
// Run Kruskal's Algorithm(calling fun)
kruskalMST(edges);
return 0;
}