#include <stdio.h>

void first_fit(int items[], int n, int c)
{
    int bin[n];          // remaining capacity in each bin
    int binCount = 0;

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
    {
        bin[i] = c;
    }

    // Process each item
    for (int i = 0; i < n; i++)
    {
        int placed = 0;

        // Try to fit item in existing bins
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i];
                printf("Item %d placed in bin %d\n", items[i], j + 1);
                placed = 1;
                break;
            }
        }

        // If item not placed, create new bin
        if (!placed)
        {
            bin[binCount] = c - items[i];
            printf("Item %d placed in bin %d\n", items[i], binCount + 1);
            binCount++;
        }
    }

    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, c;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    printf("Enter bin capacity: ");
    scanf("%d", &c);

    first_fit(items, n, c);

    return 0;
}