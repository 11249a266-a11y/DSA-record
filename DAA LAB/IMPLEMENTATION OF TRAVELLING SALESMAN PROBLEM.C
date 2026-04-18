#include <stdio.h>
#include <limits.h>

// Maximum number of cities
#define MAXN 15

// Represent infinity (very large value)
#define INF INT_MAX

int n;                          // Number of cities
int d[MAXN][MAXN];              // Distance matrix
int dp[MAXN][1 << MAXN];        // DP table

// Utility function to return minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Recursive function using DP + Bitmasking
// i = current city
// s = bitmask representing remaining cities to visit
int g(int i, int s) {

    // Base case: if no cities left to visit,
    // return cost to go back to starting city (0)
    if (s == 0)
        return d[i][0];

    // If already computed, return stored value
    if (dp[i][s] != -1)
        return dp[i][s];

    int mincost = INF;

    // Try visiting every city k that is still in set 's'
    for (int k = 0; k < n; k++) {

        // Check if k-th city is in the set 's'
        if (s & (1 << k)) {

            // Cost = distance from i → k + cost of remaining path
            int cost = d[i][k] + g(k, s ^ (1 << k));

            // Take minimum cost
            mincost = min(mincost, cost);
        }
    }

    // Store result in DP table and return
    return dp[i][s] = mincost;
}

int main() {

    // Input number of cities
    printf("Enter number of cities: ");
    scanf("%d", &n);

    // Input distance matrix
    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &d[i][j]);
        }
    }

    // Initialize DP table with -1 (means not computed)
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < (1 << MAXN); j++) {
            dp[i][j] = -1;
        }
    }

    // Start from city 0
    // Bitmask: all cities except 0 are initially unvisited
    int result = g(0, (1 << n) - 2);

    // Output result
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}