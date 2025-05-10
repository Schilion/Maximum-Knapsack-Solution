#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Returns the maximum of two integers.
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Solves the 0/1 Knapsack problem using dynamic programming.
 * Uses 1D dp[] array for space optimization and prev[] array for backtracking.
 */
void knapsack_dp(int weights[], int values[], int n, int capacity) {
    int *dp = (int *)calloc(capacity + 1, sizeof(int));
    int *prev = (int *)calloc(capacity + 1, sizeof(int));

    if (dp == NULL || prev == NULL) {
        printf("Memory allocation failed.\n");
        if (dp) free(dp);
        if (prev) free(prev);
        return;
    }

    // Fill dp table and copy snapshot to prev for each item
    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], prev[w - weights[i]] + values[i]);
        }
        memcpy(prev, dp, (capacity + 1) * sizeof(int));
    }

    // Output result
    printf("\nDP Solution:\n");
    printf("Maximum value: %d\n", dp[capacity]);

    if (dp[capacity] == 0) {
        printf("No items selected.\n");
        free(dp);
        free(prev);
        return;
    }

    // Backtrack to find selected items, store in array to print in ascending order
    int w = capacity;
    int selected[n], count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (w >= weights[i] && dp[w] == prev[w - weights[i]] + values[i]) {
            selected[count++] = i + 1;  // store 1-based index
            w -= weights[i];
        }
    }

    printf("Selected items: ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", selected[i]);  // print in ascending order
    }
    printf("\n");

    free(dp);
    free(prev);
}

int main() {
    int n, capacity;

    // Input
    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of items.\n");
        return 1;
    }

    // Dynamically allocate memory for weights and values
    int *weights = (int *)malloc(n * sizeof(int));
    int *values = (int *)malloc(n * sizeof(int));
    if (weights == NULL || values == NULL) {
        printf("Memory allocation failed.\n");
        if (weights) free(weights);
        if (values) free(values);
        return 1;
    }

    printf("Enter weights of the %d items:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &weights[i]) != 1 || weights[i] < 0) {
            printf("Invalid weight input.\n");
            free(weights);
            free(values);
            return 1;
        }
    }

    printf("Enter values of the %d items:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &values[i]) != 1 || values[i] < 0) {
            printf("Invalid value input.\n");
            free(weights);
            free(values);
            return 1;
        }
    }

    printf("Enter knapsack capacity: ");
    if (scanf("%d", &capacity) != 1 || capacity < 0) {
        printf("Invalid capacity.\n");
        free(weights);
        free(values);
        return 1;
    }

    knapsack_dp(weights, values, n, capacity);

    // Free allocated memory
    free(weights);
    free(values);

    return 0;
}
