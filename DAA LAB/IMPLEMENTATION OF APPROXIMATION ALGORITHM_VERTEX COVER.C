#include <stdio.h>
// Number of vertices in our graph 
#define V 5 
 /* A simple greedy approach to find a Vertex Cover. 
  * It follows a 2-approximation strategy. 
  */
void findVertexCover(int graph[V][V]) 
{ 
    // Array to represent our Cover Set 'C' 
    int visited[V]; 

    for (int i = 0; i < V; i++) 
    { 
//Initialize a set C to be empty (this will hold our vertex cover). 
        visited[i] = 0; 
    } 
  // Repeat until no unmarked edges remain in C (visited array) 
 // We use nested loops to scan every possible edge (u, v) in the matrix. 
    for (int u = 0; u < V; u++) 
    { 
        for (int v = 0; v < V; v++) 
        { 
            if (graph[u][v] == 1 && !visited[u] && !visited[v]) 
            { 
                visited[u] = 1; 
                visited[v] = 1; 
                 /* Removing of all edges incident on those two vertices 
                    We don't need to code to delete the edges.  
                    By marking 'u' and 'v' as visited,  
                    our 'if' condition above will automatically skip all other edges 
                    connected to them! 
                 */ 
            } 
        } 
    } 
 // Return the Cover Set C by printing all vertices we marked
    printf("Approximate Vertex Cover: "); 
    int count = 0; 
    for (int i = 0; i < V; i++) 
    { 
        if (visited[i]) 
        { 
            printf("%d ", i); 
            count++; 
        } 
    } 
    printf("\nTotal vertices in the cover: %d\n", count); 
} 

int main() 
{ 
// Adjacency Matrix
    int graph[V][V] = { 
        {0, 1, 0, 0, 0}, 
        {1, 0, 1, 1, 0}, 
        {0, 1, 0, 1, 1}, 
        {0, 1, 1, 0, 1}, 
        {0, 0, 1, 1, 0}}; 

    printf("Executing Vertex Cover Approximation...\n");
//function call 
    findVertexCover(graph); 
    return 0; 
}