#include <stdio.h>

struct Item {
    int value;
    float weight;
    float ratio;
};

void sort(struct Item items[], int n) {
    struct Item temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    float total_profit = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("\nItem %d:\n", i + 1);

        printf("Weight: ");
        scanf("%f", &items[i].weight);

        printf("Value: ");
        scanf("%d", &items[i].value);

        items[i].ratio = items[i].value / items[i].weight;
    }

    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items by ratio
    sort(items, n);

    printf("\nItems sorted by value/weight ratio:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d -> Weight: %.2f, Value: %d, Ratio: %.2f\n",
               i + 1, items[i].weight, items[i].value, items[i].ratio);
    }

    // Fractional Knapsack logic
    float remaining = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remaining) {
            total_profit += items[i].value;
            remaining -= items[i].weight;
        } else {
            total_profit += items[i].ratio * remaining;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", total_profit);

    return 0;
}