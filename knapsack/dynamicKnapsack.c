#include <stdio.h>

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsackDP(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    // Build the table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no item or zero capacity
            } else if (weights[i - 1] <= w) {
                // Max of including the item or excluding it
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ?
                           values[i - 1] + dp[i - 1][w - weights[i - 1]] :
                           dp[i - 1][w];
            } else {
                // Can't include this item, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The last cell of the table contains the maximum value
    return dp[n][capacity];
}

int main() {
    // Example: define weights, values of items, and knapsack capacity
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    // Solve the knapsack problem
    int maxValue = knapsackDP(capacity, weights, values, n);

    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}
