# 0/1 Knapsack Problem

This implementation solves the 0/1 knapsack problem using dynamic programming.

## Problem Description
Given a set of items, each with a weight and a value, determine the maximum value that can be obtained by selecting items such that the total weight does not exceed a given capacity. Each item can be selected at most once (0/1).

## Algorithm Details
- Uses dynamic programming with a 2D table
- Time Complexity: O(nW) where n is number of items and W is capacity
- Space Complexity: O(nW)

## How to Use
1. Compile the program:
   ```
   g++ -o knapsack 01knapsackingUsingDP.cpp
   ```
2. Run the executable:
   ```
   ./knapsack
   ```
3. Enter the number of items
4. Enter the weights of items
5. Enter the values of items
6. Enter the knapsack capacity
7. The program will display the maximum value and selected items

## Example
Input:
```
Number of items: 4
Weights: 5 4 6 3
Values: 10 40 30 50
Capacity: 10
```

Output:
```
Selected items: 4 2
Maximum value: 90
``` 