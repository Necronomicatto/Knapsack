#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an item
typedef struct {
    int value;
    int weight;
    double ratio; // value-to-weight ratio
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    
    // Sort in descending order of value-to-weight ratio
    if (itemA->ratio < itemB->ratio) return 1;
    if (itemA->ratio > itemB->ratio) return -1;
    return 0;
}

// Greedy algorithm to solve the knapsack problem
double knapsackGreedy(Item items[], int n, int capacity) {
    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(Item), compare);
    
    int totalWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            // Take the whole item
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // If the item can't be taken whole, break
            break;
        }
    }

    return totalValue;
}

int main() {
    // Example: define some items with value and weight
    Item items[] = {{60, 10, 0}, {100, 20, 0}, {120, 30, 0}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Solve the knapsack problem using greedy algorithm
    double maxValue = knapsackGreedy(items, n, capacity);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
