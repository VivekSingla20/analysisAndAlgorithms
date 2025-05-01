# Sum of Subsets Algorithm

This implementation solves the sum of subsets problem using a backtracking approach.

## Problem Description
Given a set of integers and a target sum, find all possible subsets of the given set whose sum equals the target sum.

## Algorithm Details
- Uses backtracking to explore all possible combinations
- Time Complexity: O(2^n) where n is the number of elements
- Space Complexity: O(n) for recursion stack

## How to Use
1. Compile the program:
   ```
   g++ -o sumOfSubsets sumOfSubsets.cpp
   ```
2. Run the executable:
   ```
   ./sumOfSubsets
   ```
3. Enter the number of elements
4. Enter the elements
5. Enter the target sum
6. The program will display all possible solutions

## Example
Input:
```
Number of elements: 5
Elements: 1 2 3 4 5
Target sum: 7
```

Output:
```
Solution found: 2 5
Solution found: 3 4
Solution found: 1 2 4
``` 