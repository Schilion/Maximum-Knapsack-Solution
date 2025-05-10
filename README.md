# Maximum Knapsack Project
CMSC 142 — 2nd Semester 2024-2025

## Members:
- Clemente
- Malco


## Problem Description
The **Maximum Knapsack Problem** is defined as:

Given:
- `n` items, each with a **weight** and a **value**
- a maximum **capacity** of the knapsack

Select a subset of items to **maximize the total value** without exceeding the weight capacity.

---

## Implemented Solutions

### 1️⃣ Brute-force (Exhaustive Search)
- Checks all \( 2^n \) possible subsets of items.
- Tracks the maximum value subset within the capacity.
- Uses **bitmasking** to generate combinations.
- **Time complexity:** \( O(2^n) \)
- **Memory:** Dynamically allocated `weights[]` and `values[]` arrays, safe `malloc()` + `free()`.

### 2️⃣ Dynamic Programming (DP)
- Uses a **space-optimized 1D dp array** \( dp[w] \) for weight limits.
- Uses an additional **prev array** \( prev[w] \) to enable **backtracking** and recover selected items.
- Builds optimal solutions incrementally for each item.
- **Time complexity:** \( O(n \cdot capacity) \)
- **Space complexity:** \( O(capacity) \)
- **Memory:** Dynamically allocated `weights[]`, `values[]`, `dp[]`, and `prev[]`; safe `malloc()`, `calloc()`, and `free()`.

---

## Compilation Instructions

```bash
gcc knapsack_brute_force.c -o brute_force
gcc knapsack_dp.c -o dp
```

---

## Running the Programs

```bash
./brute_force
```

```bash
./dp
```

---

## Sample Input

```
Enter number of items: 4
Enter weights of the 4 items:
2 3 4 5
Enter values of the 4 items:
3 4 5 6
Enter knapsack capacity: 5
```

---

## Sample Output

```
Brute-force Solution:
Maximum value: 4
Selected items: 2

DP Solution:
Maximum value: 4
Selected items: 2
```

---

## Improvements over basic versions
- Fully **dynamic input** (no hardcoded values).
- **Input validation** (rejects invalid or negative inputs).
- **Dynamic memory allocation** to handle large datasets.
- **Safe memory cleanup** (`free()` with NULL checks).
- **Optimized DP with backtracking** to recover selected items in ascending order.

---

## Real-world Applications
- Cloud storage optimization
- File selection under storage or bandwidth limits
- Investment and resource allocation under budget constraints
- Media file selection for portable devices

---

## References
- KTH NP-complete problem compendium: https://www.csc.kth.se/~viggo/wwwcompendium/
- GeeksforGeeks 0/1 Knapsack (DP): https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

---

## Notes
- Brute-force is practical only for small \( n \leq 20 \).
- DP can handle larger datasets efficiently.
- Both methods always return the optimal solution.
