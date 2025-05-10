#include <stdio.h>
#include <stdlib.h>

/**
 * Returns the maximum of two integers.
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Solves the 0/1 Knapsack problem using brute-force (exhaustive search).
 * It checks all subsets of items and picks the one with the highest value
 * that fits within the weight capacity.
 */
void knapsack_brute_force(int weights[], int values[], int n, int capacity) {
    int max_value = 0;
    int best_mask = 0;

    // Check all subsets (2^n combinations)
    for (int mask = 0; mask < (1 << n); mask++) {
        int total_weight = 0, total_value = 0;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) { // Check if the j-th item is included in the subset
                total_weight += weights[j];
                total_value += values[j];
            }
        }
        if (total_weight <= capacity && total_value > max_value) {
            max_value = total_value;
            best_mask = mask;
        }
    }

    // Output
    printf("\nBrute-force Solution:\n");
    printf("Maximum value: %d\n", max_value);
    if (max_value == 0) {
        printf("No items selected.\n");
    } else {
        printf("Selected items: ");
        for (int j = 0; j < n; j++) {
            if (best_mask & (1 << j)) {
                printf("%d ", j + 1); // show 1-based index
            }
        }
        printf("\n");
    }
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

    knapsack_brute_force(weights, values, n, capacity);

    // Free allocated memory
    free(weights);
    free(values);

    return 0;
}