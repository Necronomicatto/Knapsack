#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an item
typedef struct {
    int value;
    int weight;
} Item;

// Function to compare two items based on their weight (ascending order)
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    
    return itemA->weight - itemB->weight;
}

// Greedy algorithm to maximize the number of items in the knapsack
int knapsackMaxItems(Item items[], int n, int capacity) {
    // Sort items by weight in ascending order
    qsort(items, n, sizeof(Item), compare);
    
    int totalWeight = 0;
    int totalItems = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            // Add the item to the knapsack
            totalWeight += items[i].weight;
            totalItems++;
        } else {
            // Stop if the next item can't fit
            break;
        }
    }

    return totalItems;
}

int main() {
    // Example: define some items with value and weight
    Item items[] = {{60, 10}, {100, 20}, {120, 30}, {50, 5}, {80, 15}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    // Solve the knapsack problem maximizing the number of items
    int maxItems = knapsackMaxItems(items, n, capacity);

    printf("Maximum number of items in Knapsack = %d\n", maxItems);

    return 0;
}
