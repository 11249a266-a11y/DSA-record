#include <stdio.h>

void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];
    int binCount = 0;

    // Initialize bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Place each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;
        int minSpace = capacity + 1;

        // Find best bin
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i] && (bin[j] - items[i] < minSpace))
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If found a bin
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i];
            printf("Item %d (size %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        }
        else
        {
            // Create new bin
            bin[binCount] -= items[i];
            printf("Item %d (size %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }

    printf("\nTotal bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);

        if (items[i] > capacity)
        {
            printf("Item size exceeds bin capacity! Enter again.\n");
            i--;
        }
    }

    bestFit(items, n, capacity);

    return 0;
}